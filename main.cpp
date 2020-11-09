/*
 * GccApplication1.cpp
 *
 * Created: 2020/10/20 16:51:47
 * Author : Keiji
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "envtone_def.h"
#include "envtone.h"


//#define U_DEBUG
extern "C" {
	char rcvr(void);
	};

#ifdef U_DEBUG

extern "C" {
	void xmit(unsigned char);

};


void xout(unsigned char c){
	char a;
	a = (c & 0xf0) >> 4;
	if(a < 10){
		a += 0x30;
		}else{
		a += 0x37;
	}
	xmit(a);	
	
	a = c & 0x0f;
	if(a < 10){
		a += 0x30;
	}else{
		a += 0x37;
	}
	xmit(a);

	xmit(',');	

}

#endif



signed  char tone1[]  = {
 15,  0, 18,  1, 12,
	0, 8, 17, 23, 27, 28, 29, 30, 29, 28, 27, 27, 23, 21, 21, 21,
	21, 25, 28, 30, 30, 27, 23, 17, 8, 0, -3, -6, -8, -8, -6, -3,
	0, 3, 6, 8, 8, 6, 3, 0, -8, -17, -23, -27, -30, -30, -28, -25,
	-21, -21, -21, -21, -23, -27, -27, -28, -29, -30, -29, -28, -27, -23, -17, -8
   };
   
signed   char tone2[] = {//flute
 15,  2, 25,  4,  5,
 11, 18, 24, 21, 24, 26, 30, 23, 26, 21, 14, 15, 14, 11,  7,  8,
 6,  7,  8, 11, 12, 15, 16, 18, 21, 24, 29, 28, 28, 24, 24, 19,
 -15,-16,-25,-29,-28,-32,-26,-31,-21,-20,-18,-19,-12,-11, -6,-12,
 -11, -9, -8, -9, -8,-16,-14,-24,-25,-25,-27,-30,-23,-25,-22,-13,
 
	   };
	   
 signed  char tone3[] = {//sax
 14,  1, 13,  1, 13,
 25, 24, 25, 28, 29, 28, 27, 32, 24, 24, 28, 24, 23, 15, 18, 22,
 30, 29, 27, 26, 26, 26, 29, 29, 30, 31, 29, 31, 31, 32, 27, 27,
 25, 20, 22, 21, 15, 18, 14, 21, 17, 21, 23, 29, -7, -6,-30,-24,
 -24,-26,-27,-28,-29,-24,-29,-22,-23,-28,-28,-26,-33,-28,-27,-29,

   };	   
   
signed char tone4[] = {//sin1-3
 14,  0, 18,  1, 12,
 0, -2, -6, -9,-12,-16,-19,-21,-22,-23,-24,-23,-21,-20,-18,-18,
 -18,-18,-18,-19,-20,-21,-22,-24,-24,-23,-21,-18,-15,-12, -8, -2,
 1,  6, 13, 18, 21, 22, 23, 23, 24, 24, 25, 24, 22, 21, 19, 20,
 21, 21, 18, 20, 21, 23, 24, 23, 22, 21, 19, 16, 12,  9,  6,  2,
	
};
signed char tone5[] ={//space
 15, 11, 18,  3,  7,
 0,  3,  9, 20, 24, 24, 20, 25, 17, 16, 17, 12,  9,  9, 11, 10,
 12, 12, 11, 11, 13, 15, 20, 23, 26, 30, 28, 31, 29, 26, 18, 13,
 -6,-16,-17,-22,-29,-26,-31,-24,-26,-22,-18,-12,-14,-11,-13, -7,
 -7, -8,-10,-12,-15,-11,-18,-13,-17,-23,-23,-21,-26,-17,-11, -8,
};
	   
  
	   

  void play_midi();
  int mem_cmp (const void* dst, const void* src, int cnt);
  void swap(uint8_t *a,uint8_t *b);
  uint8_t usart_read(void);
  volatile uint16_t timer_u = 0;  //   2/PWM_KHZ
  
  
  
int main(void)
{


	ENVTONE.setup_hardware();


#ifdef MONO_MODE
	ENVTONE.setTone(0,tone1);
	ENVTONE.setTone(2,tone2);
	ENVTONE.setTone(3,tone3);
	ENVTONE.setTone(1,tone4);

#else if
 
	ENVTONE.midi_setTone(tone1);
	ENVTONE.midi_set_envelope(15,0,8,1,10);
#endif
	
	
	
#ifndef U_DEBUG
	sei();

#endif

	play_midi();	

	while(1)
		;  
   
}

void swap(uint8_t *a,uint8_t *b){
	uint8_t c;
	c = *a;
	*a = *b;
	*b = c;
}




void play_midi(){
	uint8_t data;
	uint8_t sysExcnt = 0;
	uint8_t dat1, dat2, dat3, com;

	while (1) {
		dat1 = usart_read();
		if (dat1 == 0xf0) {
			sysExcnt = 1;
			do {
				data = usart_read();
				//sysex_buf[sysExcnt++] = data;
				if (sysExcnt > 64) {
					break;
				}
			} while (data != 0xf7);  //システムエクルシーブメッセージ終了
			//midi_sysEx(sysex_buf, sysExcnt);
			sysExcnt = 0;

			} else {
			if (dat1 & 0x80) {
				com = dat1 & 0xf0;
				dat2 = usart_read();

				if ( (com == 0xc0) || (com == 0xd0)) {
					ENVTONE.midi_command(com, dat1, dat2, dat3);
					} else {
					dat3 = usart_read();
					ENVTONE.midi_command(com, dat1, dat2, dat3);
					}
				}else{
					if(com == 0xc0){
						// Program change
						switch(dat2){
#ifdef MONO_MODE
							case 0:
							ENVTONE.setTone(dat1 & 0x0f,tone1);
							break;
							case 1:
							ENVTONE.setTone(dat1 & 0x0f,tone2);
							break;
							case 2:
							ENVTONE.setTone(dat1 & 0x0f,tone3);
							break;
							case 3:
							ENVTONE.setTone(dat1 & 0x0f,tone4);
							break;
							case 4:
							ENVTONE.setTone(dat1 & 0x0f,tone5);
							break;
#else if
							case 0:
							ENVTONE.midi_setTone(tone1);
							break;
							case 1:
							ENVTONE.midi_setTone(tone2);
							break;
							case 2:
							ENVTONE.midi_setTone(tone3);
							break;
							case 3:
							ENVTONE.midi_setTone(tone4);
							break;
							case 4:
							ENVTONE.midi_setTone(tone5);
							break;
#endif								
							default:

							break;
							
						
					}
				}
			}
		}
	}
}

uint8_t usart_read(){
	uint8_t c;
	c = rcvr();

	return c;

}