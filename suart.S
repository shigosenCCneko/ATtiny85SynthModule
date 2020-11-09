/*
 *	ソフトウェアシリアルの受信
 *  波形メモリ音源割り込み処理でカウントアップするtimer_uを使ってタイミングを取る
 */


#include "envtone_def.h"
#include <avr/io.h>

#define	SKIP_IN_1	sbis _SFR_IO_ADDR(PINB), 3	/* Skip if 1 */
#define	SKIP_IN_0	sbic _SFR_IO_ADDR(PINB), 3	/* Skip if 0 */

.extern timer_u



.global rcvr
.func rcvr
rcvr:

	ldi r23,0
	ldi r24,0x80
11: SKIP_IN_1
	rjmp 11b

12: SKIP_IN_0
	rjmp 12b

	cli 
	sts timer_u,r23
	sei
13: lds r25,timer_u
	cpi r25,BPS_S
	brne 13b

14: cli
	sts timer_u,r23
	sei

15:	lds r25,timer_u
	cpi r25,BPS
	brne 15b

	lsr r24
	SKIP_IN_0
	ori r24,0x80
	brcc 14b

	cli
	sts timer_u,r23
	sei
16: lds r25,timer_u
	cpi r25,BPS_E
	brne 16b


	ret
.endfunc		






