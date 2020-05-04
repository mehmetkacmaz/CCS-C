#include<16f877.h>

#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT

#use delay(clock=4M)
#use fast_io(b)
#use fast_io(d)

#byte portd=0x06

#define satir_1 pin_B3
#define satir_2 pin_B2
#define satir_3 pin_B1
#define satir_4 pin_B0
#define sutun_1 pin_B4
#define sutun_2 pin_B5
#define sutun_3 pin_B6
#define sutun_4 pin_B7

char tus=0;


char keypad(){

   output_b(0x00);
   
   output_high(satir_1);
   if (input(sutun_1)){ 
      while(input(sutun_1));
      delay_ms(20);
      tus=0x0A;
      }
   if (input(sutun_2)){
      while(input(sutun_2));
      delay_ms(20);
     tus=3;
      }
   if (input(sutun_3)){
      while(input(sutun_3));
      delay_ms(20);
      tus=2;
      }
   if (input(sutun_4)){
      while(input(sutun_4));
      delay_ms(20);
      tus=1;
      }
   output_low(satir_1);

   output_high(satir_2);
   if (input(sutun_1)){
      while(input(sutun_1));
      delay_ms(20);
      tus=0X0B; 
      }
   if (input(sutun_2)){ 
      while(input(sutun_2));
      delay_ms(20);
      tus=6; 
      }
   if (input(sutun_3)){ 
      while(input(sutun_3));
      delay_ms(20);
      tus=5; 
   }
   if (input(sutun_4)){ 
      while(input(sutun_4));
      delay_ms(20);
      tus=4; 
   }
   output_low(satir_2);

   output_high(satir_3);
   if (input(sutun_1)){
      while(input(sutun_1));
      delay_ms(20);
      tus=0x0C;
      }
   if (input(sutun_2)){
      while(input(sutun_2));
      delay_ms(20);
      tus=9; 
   }
   if (input(sutun_3)){ 
      while(input(sutun_3));
      delay_ms(20);
      tus=8; 
   }
   if (input(sutun_4)){
      while(input(sutun_4));
      delay_ms(20);
      tus=7; 
   }
   output_low(satir_3);

   output_high(satir_4);
   if (input(sutun_1)){
      while(input(sutun_1));
      delay_ms(20);
      tus=0x0D; 
      }
   if (input(sutun_2)){
      while(input(sutun_2));
      delay_ms(20);
      tus=0x0F;
   }
   if (input(sutun_3)){
      while(input(sutun_3));
      delay_ms(20);
      tus=0; 
   }
   if (input(sutun_4)){
      while(input(sutun_4));
      delay_ms(20);
      tus=0x0E; 
   }
   output_low(satir_4);
   
   return tus;
}


void main(){
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_b(0xF0);    //satýrlar giriþ - sütunlar çýkýþ
   set_tris_d(0x00);
   
   output_d(0x00);
   
   while(1){
      portd=keypad();
   }
}

