

#include "include.h"
#include "calculation.h"





/*************************
����ϵͳ��ȫ�ֱ���
*************************/



extern  u8  LPT_INT_count ;
extern  u8  DMA_Over_Flg ;            //�ɼ���ɱ�־λ
extern  u8  LinADCout ;





extern u8 TIME0flag_5ms   ;
extern u8 TIME0flag_10ms  ;
extern u8 TIME0flag_15ms  ;
extern u8 TIME0flag_20ms  ;
extern u8 TIME0flag_80ms ;
extern u8 TIME1flag_1s ;

uint8_t i ;
u16 count = 0 ;

void main()
{
      DisableInterrupts;                             //��ֹ���ж� 
  
  /*********************************************************
  ��ʼ������
  *********************************************************/

     /*************************************
    ��ʼ�����
    *************************************/
   /* */
 
    FTM_PWM_init(FTM0 , CH0, 80000,0);                        //���ռ�ձ����ó�ʼ��   MOD =313 ;  ռ�ձ� = duty /(MOD +1 ) ;FTM_CnV_REG(FTMx[ftmn], ch) = cv;
    FTM_PWM_init(FTM0 , CH2, 80000,0);                        //���ռ�ձ����ó�ʼ��   MOD =313 ;  ռ�ձ� = duty /(MOD +1 ) ;FTM_CnV_REG(FTMx[ftmn], ch) = cv;
    FTM_PWM_init(FTM0 , CH1, 80000,0);                        //���ռ�ձ����ó�ʼ��   MOD =313 ;  ռ�ձ� = duty /(MOD +1 ) ;FTM_CnV_REG(FTMx[ftmn], ch) = cv;
    FTM_PWM_init(FTM0 , CH3, 80000,0);                        //���ռ�ձ����ó�ʼ��   MOD =313 ;  ռ�ձ� = duty /(MOD +1 ) ;FTM_CnV_REG(FTMx[ftmn], ch) = cv;
/***
   uart_init (UART0 , 115200);                      //��ʼ��UART0�������PTA15�������PTA14������Ƶ�� 9600
   gpio_init (PORTA , 16, GPO,HIGH);
   gpio_init (PORTA , 17, GPO,HIGH); 
   gpio_init (PORTB , 17, GPI,HIGH);   
   pit_init_ms(PIT0, 5);                                    //��ʼ��PIT0����ʱʱ��Ϊ�� 5ms
   pit_init_ms(PIT1, 1000);                                //��ʼ��PIT1����ʱʱ��Ϊ�� 1000ms    
   EnableInterrupts;			                    //�����ж�  
***/    
   /******************************************
    ִ�г���
    ******************************************/
    while(1)
    {
        uart_init (UART0 , 115200);                      //��ʼ��UART0�������PTA15�������PTA14������Ƶ�� 9600
   gpio_init (PORTA , 16, GPO,HIGH);
   gpio_init (PORTA , 17, GPO,HIGH); 
   gpio_init (PORTB , 17, GPI,HIGH);   
   pit_init_ms(PIT0, 5);                                    //��ʼ��PIT0����ʱʱ��Ϊ�� 5ms
   pit_init_ms(PIT1, 1000);                                //��ʼ��PIT1����ʱʱ��Ϊ�� 1000ms    
   EnableInterrupts;			                    //�����ж� 
  

      
      
 
      
      
      /*********************
      5ms����ִ�д����
      *********************/
      
      /****   ��ʱע��
      
      if(TIME0flag_5ms == 1)
      { 
        TIME0flag_5ms = 0 ;
        
      }                 ��ʱע��  **************/
      
      /*********************
      10ms����ִ�д����
      *********************/
      
      /****   ��ʱע��
      
      if(TIME0flag_10ms == 1)
      {
        TIME0flag_10ms = 0 ;
        
        
       i =  uart_getcharflg (UART0)  ; 
         if(i){ 
           i = uart_getchar(UART0) +1;
           uart_putchar(UART0, i) ;
         }



      }                ��ʱע��  **************/
      
      /*********************
      15ms����ִ�д����
      *********************/
      
      
      /****   ��ʱע��
      
       if(TIME0flag_15ms == 1)
      {
        TIME0flag_15ms = 0 ;
      //  uart_putchar(UART0,0xff);
        
      }
      
      /*********************
      20ms����ִ�д����
      *********************/
      
      
      /****   ��ʱע��
      
      if(TIME0flag_80ms == 1)
      {
        TIME0flag_80ms = 0 ;
        PTA16_OUT = ~PTA16_OUT ;
        PTA17_OUT = ~PTA17_OUT ;
if( count == 3 )
       {
          count = 2 ;
          FTM_PWM_Duty(FTM0 , CH0,0);
          FTM_PWM_Duty(FTM0 , CH1,0);
          FTM_PWM_Duty(FTM0 , CH2,0);
          FTM_PWM_Duty(FTM0 , CH3,0);
       } else if(count == 2)
       {
         
          count = 1 ;
          FTM_PWM_Duty(FTM0 , CH0,0);
          FTM_PWM_Duty(FTM0 , CH1,80);
          FTM_PWM_Duty(FTM0 , CH2,0);
          FTM_PWM_Duty(FTM0 , CH3,80);
          
       }else if(count == 1)
       {
         
          count = 0 ;

          FTM_PWM_Duty(FTM0 , CH0,0);
          FTM_PWM_Duty(FTM0 , CH1,0);
          FTM_PWM_Duty(FTM0 , CH2,0);
          FTM_PWM_Duty(FTM0 , CH3,0); 
       
       } else if(count == 0)
       {
         
          count = 3 ;
          FTM_PWM_Duty(FTM0 , CH0,80);
          FTM_PWM_Duty(FTM0 , CH1,0);
          FTM_PWM_Duty(FTM0 , CH2,80);
          FTM_PWM_Duty(FTM0 , CH3,0);  
          
       }
       
      }                 ******************/
      
    

    }
}


  
