#include<16f877.h>

#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT

#use delay(clock=4M)
#use fast_io(c)
#use fast_io(d)

const int digit[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

//clock format [d,c : b,a]

int8 a=0;      //second units digit
int8 b=0;      //second tens digit
int8 c=0;      //minute units digit
int8 d=0;      //minute tens digit
int time=0;
int second=0;
int minute=0;

void main(){
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_c(0x00);
   set_tris_d(0x00);
   
   while(1){
      
      start:
      for(int i=0; i<=50; i++){
         output_d(0x00);
         output_c(0b00000001);
         output_d(digit[a]);
         delay_ms(5);
      
         output_d(0x00);
         output_c(0b00000010);
         output_d(digit[b]);
         delay_ms(5);
      
         output_d(0x00);
         output_c(0b00000100);
         output_d(digit[c]);
         delay_ms(5);
      
         output_d(0x00);
         output_c(0b00001000);
         output_d(digit[d]);
         delay_ms(5);
      }
      time++;           //time = total second 
      second=time%60;
      a = second%10;
      b = second/10;
         
      minute=time/60;
      c = minute%10;
      d = minute/10;
      goto start;
 
   }  
}
