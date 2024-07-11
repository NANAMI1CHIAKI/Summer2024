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

	USART2_Init(115200);                //��ʼ��USART2 115200 ʹ�� �����������жϽ���
   
  OLED_Init();                         // OLED��ʼ��
  OLED_P8x16Str(10, 0,"Test USART2");  // �ַ���
	delay_1ms(50);
	printf("USART2 Init OK \n");
  USART_Sent_String(USART2,"USART2 Init OK\n");
	
	
	
	
	while(1)
	{
		
		Push_Red_Ball();
		
	}
	while(1)
	{
	delay_1ms(100);
	}
}

