/*4
 * envtone_defh.h
 *
 * Created: 2020/10/17 21:07:07
 *  Author: Keiji
 */ 


#define MAX_TONE  4
/*
 * PWM_KHZ サンプリング周波数
 */

#define PWM_KHZ  20

#define BAUD 4800
//#define BPS_T  (PWM_KHZ * 1000+(BAUD/2))/BAUD

#define BPS_S	4
#define BPS		8
#define BPS_E	4



	/*
 * PWM_PIN 出力PINの選択  
 */
 #define PWM_PIN    PB1

//#define MONO_MODE

