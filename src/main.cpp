#include <avr/io.h>
#include <util/delay.h>


void display(uint8_t number, int segment);


int main (void){
  DDRC = 0b00001111; //Setup BCD Outputs
  DDRB = 0b00001111; //Setup Multiplex outputs
  
  
  while(1){

    display(1, 0);
    display(7, 1);
  }

  return(0);
}


void display(uint8_t number, int segment){
  PORTC = number;
  PORTB = (1 << segment);
  _delay_ms(1);
}