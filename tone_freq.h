/*
 * tone_freq.h
 *
 * Created: 2020/10/21 21:52:02
 *  Author: Keiji
 */ 
#include <avr/pgmspace.h>

#ifndef TONE_FREQ_H_
#define TONE_FREQ_H_
#include "envtone_def.h"

#define SAMPLE_VAL  64

/*
 * MIDI Note No 24�`127��1�T���v�����O������̃X�e�b�v����16bit(8.8)�̌Œ菬���_�̒l�ɂ����e�[�u��
 * 
 *  ���g�� * �T���v�����O�� * 256 /�T���v�����O���g��
 *  
 *  
 */
 
const  uint16_t tone_freq[] PROGMEM = {
int( 32.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 34.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 36.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 38.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 41.2 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 43.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 46.2 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 49.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 51.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 55.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 58.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 61.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 65.4 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 69.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 73.4 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 77.8 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 82.4 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 87.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 92.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 98.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 103.8 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 110.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 116.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 123.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 130.8 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 138.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 146.8 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 155.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 164.8 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 174.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 185.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 196.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 207.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 220.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 233.1 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 246.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 261.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 277.2 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 293.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 311.1 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 329.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 349.2 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 370.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 392.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 415.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 440.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 466.2 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 493.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 523.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 554.4 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 587.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 622.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 659.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 698.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 740.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 784.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 830.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 880.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 932.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 987.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1046.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1108.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1174.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1244.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1318.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1396.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1480.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1568.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1661.2 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1760.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1864.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
int( 1975.5 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),

//int( 4186.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 4434.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 4698.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 4978.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 5274.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 5587.7 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 5919.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 6271.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 6644.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 7040.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 7458.6 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),


//int( 7902.1 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 8372.0 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 8869.8 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 9397.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 9956.1 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 10548.1 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 11175.3 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 11839.8 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
//int( 12543.9 * SAMPLE_VAL * 256 / PWM_KHZ / 1000 + 0.5 ),
};




#endif /* TONE_FREQ_H_ */