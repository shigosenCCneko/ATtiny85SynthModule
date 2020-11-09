/*
 * memtone.h
 *
 * Created: 2020/10/17 22:35:07
 *  Author: Keiji
 */ 


#ifndef MEMTONE_H_
#define MEMTONE_H_


struct MemTone {
	private:
	uint16_t sin_pos;
	uint16_t sin_step;
	uint8_t  vol;

	uint8_t env_state;
	uint8_t env_cnt;

	uint8_t atk;
	uint8_t decy;
	uint8_t sul;
	uint8_t sus;
	uint8_t rel;
	uint8_t level;
	uint16_t wave_tbl;
	uint8_t env_step;
	public:
	MemTone();
	void tone_on( int , int );
	void tone_off();
	void set_wave(char *wave);
	void set_envelope( uint8_t , uint8_t , uint8_t , uint8_t , uint8_t );

	private:
	
	uint8_t conv_count(uint8_t );

};



#endif /* MEMTONE_H_ */