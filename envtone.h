/*
 * envtone.h
 *
 * Created: 2020/10/17 22:33:28
 *  Author: Keiji
 */ 


#ifndef ENVTONE_H_
#define ENVTONE_H_

#include "memtone.h"
#include "envtone_def.h"

class EnvTone
{

	protected:


	private:
	#ifndef MONO_MODE
	/* MIDI ポリフォニック発音割り振り用　*/
	uint8_t queue_cnt ;
	uint8_t voice_queue[MAX_TONE];
	uint8_t voice_queue_top;
	uint8_t voice_queue_tail;
	uint8_t active_voice_num ;
	
	uint8_t ch_midino[MAX_TONE];
	#endif 

	public:


	EnvTone();
	void setup_hardware();
	void note_on(uint8_t, uint8_t, uint8_t);
	void note_off(uint8_t );
	void midi_command(uint8_t , char , char , char );
	
	void midi_set_envelope(uint8_t atk, uint8_t decy, uint8_t sul, uint8_t sus, uint8_t rel);
	void set_envelope(uint8_t , uint8_t atk, uint8_t decy, uint8_t sul, uint8_t sus, uint8_t rel);

    void midi_setTone(signed char source[]);
    void setTone(uint8_t ch, signed char source[]);

	private:
	
	void midi_note_off(uint8_t);


};

extern EnvTone ENVTONE;




#endif /* ENVTONE_H_ */