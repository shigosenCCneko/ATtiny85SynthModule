/*
 * memtone.cpp
 *
 * Created: 2020/10/17 22:35:34
 *  Author: Keiji
 */ 
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "MemTone.h"
#include "envtone_def.h"
#include "tone_freq.h"
const uint8_t envelope_cnt[16] PROGMEM = {0, 1, 2, 3, 4, 5, 7, 10, 13, 20, 29, 43, 64, 86, 128, 255}; //endless,255,127,85,63,51,36,25,19,12,8,5,3,2,1,0



MemTone::MemTone() {
this->sin_step = 0;
	
}


void MemTone::tone_on( int tone, int vol) {
	int f;
	if (tone >= 24)
	tone -= 24;
	f = pgm_read_word(&(tone_freq[tone]));

	this->sin_step = f;
	this->sin_pos = 0;
	this->env_state = 1;
	this->vol = vol & 0x1f;
	this->env_cnt = 249;
	this->level = 0;
	 this->env_step = this->atk;

}

void MemTone::tone_off() {
	this->env_state = 4;
  this->env_step = this->rel;
}

void MemTone:: set_wave(char *wave) {

	this->wave_tbl = (uint16_t)wave;
}

 void MemTone::set_envelope( uint8_t atk, uint8_t decy, uint8_t sul, uint8_t sus, uint8_t rel) {
	this->atk = conv_count(atk);
	this->decy = conv_count(decy);
	this->sul = sul;
	this->sus = conv_count(sus);
	this->rel = conv_count(rel);

}


uint8_t MemTone::conv_count(uint8_t d) {
	return pgm_read_byte(&(envelope_cnt[d & 0x0f]));
}



