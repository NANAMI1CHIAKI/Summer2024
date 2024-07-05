#include "gd32f10x_it.h"
#include "main.h"
#include "systick.h"
#include "led_driver.h"

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
    /* if NMI exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void)
{
    /* if Memory Manage exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void)
{
    /* if Bus Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void)
{
    /* if Usage Fault exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void)
{
    /* if SVC exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void)
{
    /* if DebugMon exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void)
{
    /* if PendSV exception occurs, go to infinite loop */
    while(1){
    }
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void)
{
	 delay_decrement();

}
void TIMER0_UP_IRQHandler(void)
{
	timer_flag_clear(TIMER0, TIMER_FLAG_UP);
    led_toggle();	
	
}
extern uint8_t  transfersize1;
extern uint8_t  receivesize1;
extern uint8_t  txcount1; 
extern uint16_t rxcount1; 
extern uint8_t  receiver_buffer1[32];
extern uint8_t  transmitter_buffer1[];
void USART1_IRQHandler(void)
{
    if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_RBNE))
		{
        /* receive data */
        receiver_buffer1[rxcount1++] = usart_data_receive(USART1);
        if(rxcount1 == receivesize1){
            usart_interrupt_disable(USART1, USART_INT_RBNE);
        }
    }

    if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_TBE)){
        /* transmit data */
        usart_data_transmit(USART1, transmitter_buffer1[txcount1++]);
        if(txcount1 == transfersize1){
            usart_interrupt_disable(USART1, USART_INT_TBE);
        }
    }
}

extern uint8_t USART_Rx_Buf[];  // ���ڱ��� RX ���յ�������
extern uint16_t USART_Rx_Len;   // ���ڱ��� RX ���յ������ݵĸ���
extern uint16_t USART_Rx_Count; // ���ڱ��� RX ��������ʱ�Ѿ����յ������ݸ���
// extern uint8_t  USART_Tx_Buf[];		// ���ڱ��� Tx Ҫ���͵�����
// extern uint16_t USART_Tx_Len;			// ���ڱ��� Tx Ҫ���͵����ݵĸ���
// extern uint16_t USART_Tx_Count;		// ���ڱ��� Tx Ҫ���͵�����ʱ�Ѿ����͵����ݸ���

/*void USART2_IRQHandler(void)
{
    // Test RX&TX OK!
    unsigned char data;
    if (RESET != usart_interrupt_flag_get(USART2, USART_INT_FLAG_RBNE))
    {
        data = usart_data_receive(USART2);
        //  ��һ����һ��
        usart_data_transmit(USART2, (uint8_t)data);
        while (RESET == usart_flag_get(USART2, USART_FLAG_TBE))
            ; // ��������ж�
    }
}*/

extern unsigned char receive_data;
void USART2_IRQHandler(void)
{
    // Test RX&TX OK!
    if (RESET != usart_interrupt_flag_get(USART2, USART_INT_FLAG_RBNE))
    {
        receive_data = usart_data_receive(USART2);	//��������
        //��һ����һ��
        usart_data_transmit(USART2, (uint8_t)receive_data);		//��������
        while (RESET == usart_flag_get(USART2, USART_FLAG_TBE)); // ��������ж�
    }
}

uint32_t TimeCounter;	//���ڳ�������ʱ
void TIMER2_IRQHandler(void)
{
	timer_flag_clear(TIMER2, TIMER_FLAG_UP);	
	TimeCounter++;
}
