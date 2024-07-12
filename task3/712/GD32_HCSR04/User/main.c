#include "gd32f10x.h"
#include "systick.h"
#include <stdio.h>
#include "led_driver.h"
#include "key_driver.h"
#include "oled_driver.h"
#include "tim_driver.h"
#include "enc_driver.h"
#include "uart_driver.h"
#include "pwm_driver.h"
#include "Photoelectric.h"
#include "hcsr04_driver.h"

/*!
	\brief      main function
	\param[in]  none
	\param[out] none
	\retval     none
*/

int main(void)
{
	uint8_t sensor_Value[4];
	char txt[20];
	char TXT[50];
	systick_config();
	rcu_ahb_clock_config(RCU_AHB_CKSYS_DIV1); // AHB��Ƶ��1��Ƶ
	systick_config();						  // ϵͳ��Ƶ72MHZ,�����ⲿ����
	rcu_periph_clock_enable(RCU_AF);		  // �ܽŸ���ʱ��alternate function clockʹ��

	led_init(); // LED��ʼ��
	key_init();
	OLED_Init(); // OLED��ʼ��
	
	delay_1ms(200);
	OLED_CLS();
	sensor_init();
	Motor_Init();	
  int32_t duty = 0;	//����ռ�ձȵı���	
	
	
	Timer_Init();
	encoder1_config();
	encoder2_config();
	encoder3_config();
	int32_t Enc1 = 0;
	int32_t Enc2 = 0;
	int32_t Enc3 = 0;
	
	
	systick_config();
	rcu_ahb_clock_config(RCU_AHB_CKSYS_DIV1); // AHB��Ƶ��1��Ƶ
	systick_config();						  // ϵͳ��Ƶ72MHZ,�����ⲿ����,�����������(__SYSTEM_CLOCK_72M_PLL_HXTAL��HXTAL_VALUE)
	rcu_periph_clock_enable(RCU_AF);		  // �ܽŸ���ʱ��alternate function clockʹ��

	led_init(); // LED��ʼ��
	key_init();
	OLED_Init(); // OLED��ʼ��
	delay_1ms(200);
	OLED_CLS();

	Ultrasonic_Init();
	OLED_Init();						 // OLED��ʼ��
	OLED_P6x8Str(10, 2, "Test red ball "); // �ַ���
	
	delay_1ms(5);

	
	while(1)
	{
		OLED_P6x8Str(0, 1, "TIM_Test."); // �ַ���
		Enc1 = ENC_Read(ENCODER1_TIMER);
		Enc2 = ENC_Read(ENCODER2_TIMER);
		Enc3 = ENC_Read(ENCODER3_TIMER);
		//sprintf(TXT, "E:%4d %4d %4d ", Enc1, Enc2, Enc3);
		
		OLED_P6x8Str(0, 2, TXT);
		delay_1ms(100);
		
		
		//if(Enc1 <= 3 && Enc3 <= 3 && Enc1 >= -3 && Enc3 >= -3)
		//{
		//	MotorCtrl3W(1800, 1800, 1800);
	//		delay_1ms(100);
	//		MotorCtrl3W(-1800, -1800, -1800);
		//}
		//else
		{
			Test_UASRT2();
		}
		delay_1ms(10);
	}
}

