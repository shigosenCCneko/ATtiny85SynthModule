/*
 * envtone.cpp
 *
 * Created: 2020/10/17 22:34:37
 *  Author: Keiji
 */ 
#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "envtone.h"


#define MIDI_NOTE_OFF        0x80
#define MIDI_NOTE_ON         0x90

EnvTone ENVTONE;            //
extern MemTone memtone[MAX_TONE];


EnvTone:: EnvTone() {
	

	
	for (int i = 0; i < MAX_TONE ; i ++) {

		memtone[i].set_envelope(15, 9, 9, 2, 5);
#ifndef MONO_MODE
		voice_queue[i] = i;
		ch_midino[i] = 0;
#endif
	}
#ifndef MONO_MODE
	queue_cnt = 0;
	voice_queue_top = 0;
	voice_queue_tail = 0;
	active_voice_num = 0;
#endif
	
}


void EnvTone::setup_hardware() {
	//cli();
	DDRB = 0xf7;
	PORTB = 0xff;
	

	
	CLKPR = 0x80;
	CLKPR = 0x00;
// 	OSCCAL = 0x00;
// 	OSCCAL = 0x81;
	
	PLLCSR |= (1 <<PCKE) | (1 <<PLLE);
	TCCR1 = (1<<CS00);	// 1/8分周
	
	//GTCCR = (1<<PWM1B)|(1<<COM1B0);		//output both OCR1B & ~OCR1B
	GTCCR = (1<<PWM1B)|(1<<COM1B1);			// only OCR1B onlu	
	
	TCCR0A = (1<<WGM01);
//	TCCR0B = (1<< CS01);	// 1/8
	TCCR0B = (1 << CS00); // 1/1
	  uint8_t freq;
	 freq = (80000 / PWM_KHZ  ) / 20;  //浮動小数点ライブラリを使いたくない

	 OCR0A = freq;
	TIMSK = (1<< OCIE0A);	
	

}


void EnvTone::note_on(uint8_t ch, uint8_t no, uint8_t vel) {
	ch &= 0x07;
	memtone[ch].tone_on(no, vel >> 2);

}

void EnvTone::note_off(uint8_t ch) {
	memtone[ch].tone_off();
}


#ifdef MONO_MODE
void EnvTone::set_envelope(uint8_t ch, uint8_t atk, uint8_t decy, uint8_t sul, uint8_t sus, uint8_t rel){
	ch &= 0x07;
	atk &= 0x0f;
	decy &= 0x0f;
	sul &= 0x1f;
	sus &= 0x0f;
	rel &= 0x0f;
	memtone[ch].set_envelope(atk,decy,sul,sus,rel);
}

#else if

void EnvTone::midi_set_envelope(uint8_t atk, uint8_t decy, uint8_t sul, uint8_t sus, uint8_t rel){
	atk &= 0x0f;
	decy &= 0x0f;
	sul &= 0x1f;
	sus &= 0x0f;
	rel &= 0x0f;
	for(uint8_t i = 0;i < MAX_TONE;i++){
		memtone[i].set_envelope(  atk,  decy,  sul, sus,  rel);
	}
	
}
#endif
void EnvTone::midi_command(uint8_t com, char dat1, char dat2, char dat3) {

	uint8_t voice_ch;
	uint8_t ch = dat1 & 0x07;

//	if ( this->midi_state == MIDI_POLY) {  // PolyPhonic Mode
#ifndef MONO_MODE		
		if (ch == 0) {
			
			switch (com) {
	
				case MIDI_NOTE_ON:
				if (dat3 == 0) {  //ベロシティ0はノートオフ
					midi_note_off(dat2);
					} else {
					// キューから鳴らすチャンネル番号を得る
					if (active_voice_num == MAX_TONE) {
						voice_ch = voice_queue[voice_queue_top];
						memtone[voice_ch].tone_off();
						} else {
						voice_ch = voice_queue[voice_queue_top++];
						if (voice_queue_top == MAX_TONE) {
							voice_queue_top = 0;
						}
						active_voice_num++;
					}
					ch_midino[voice_ch] = dat2;
					memtone[voice_ch].tone_on(dat2, dat3 >> 2);

				}
				break;

				case MIDI_NOTE_OFF:
				midi_note_off(dat2);

				break;


				default:
				break;
			}
		}
#else if

		switch (com) {

			case MIDI_NOTE_ON:

			if (dat3 == 0) {
				memtone[ch].tone_off();

				} else {
				memtone[ch].tone_on( dat2, dat3 >> 2 );

			}
			break;

			case MIDI_NOTE_OFF:
			memtone[ch].tone_off();

			break;
			default:

			break;
		}
#endif

}

#ifndef MONO_MODE
void EnvTone::midi_note_off(uint8_t midi_no) {
	for (uint8_t i = 0; i < MAX_TONE; i++) {
		if (ch_midino[i] == midi_no) {
			memtone[i].tone_off();
			ch_midino[i] = 0;
			// キューへオフしたチャンネル番号を入れる
			voice_queue[voice_queue_tail++] = i;
			if (voice_queue_tail == MAX_TONE) {
				voice_queue_tail = 0;
			}
			active_voice_num--;

		}
	}
}
#endif


#ifdef MONO_MODE
void EnvTone::setTone(uint8_t ch,signed char *source){
	set_envelope(ch,*(source),*(source+1),*(source+2),*(source+3),*(source+4));
	source+=5;
	memtone[ch].set_wave((char *)source);
}

#else if
void EnvTone::midi_setTone(signed char source[]){
	midi_set_envelope(*(source),*(source+1),*(source+2),*(source+3),*(source+4));
	source+=5;

	for (uint8_t i = 0; i < MAX_TONE; i++) {
		memtone[i].set_wave((char *)source);
	}
}
#endif

