
/*
https://www.teachmemicro.com/arduino-servo-motor-tutorial/
https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
https://github.com/tomas-fryza/digital-electronics-2
hlava ŠIMONA BUCHTY a  ŠTĚPÁNA VEČEŘI 
ŠIMON BUCHTA MAESTRO ZAPOJENÍ
*/
/*Defines ------------------------------------------------------------*/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <gpio.h>           // gpio
//#include <uart.h>         // Peter Fleury's UART library
//#include <stdlib.h>       // C library. Needed for number conversions
//#include <lcd.h>          // Peter Fleury's LCD library

/*Variables---------------------------------------------------------*/
int Val;

int main(void)
{
    DDRD |= (1<<PD6);
    DDRB |= (1<<PB3);


    OCR0A = 100;          
    TCCR0A |= ((1<<COM0A1) | (1<<COM0A0) | (1<<WGM01) | (1<<WGM00));
    TCCR0B &= ~((1<<CS01) | (1<<CS00)); TCCR0B |= (1<<CS02);            //prescaler 255

    TCCR2A |= ((1<<COM2A1) | (1<<COM2A0) | (1<<WGM21) | (1<<WGM20));
    TCCR2B &= ~( (1<<CS20)); TCCR2B |= ((1<<CS22) | (1<<CS21));         //prescaler 255
    OCR2A = 100;
    
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);

    // Select input channel ADC0 (voltage divider pin)
    ADMUX &= ~((1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3));
    // Enable ADC module
    ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= ((1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2));


    //TIM1_overflow_262ms();
    TIM1_overflow_4ms()
    TIM1_overflow_interrupt_enable();

    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

ISR(TIMER1_OVF_vect){
    static uint8_t no_of_overflows = 0;
    ADCSRA |= (1<<ADSC);
    no_of_overflows ++;
    if (no_of_overflows >= 250){                    //sekunda
        no_of_overflows = 0;
        OCR0A = OCR0A + 10;
        if (OCR0A >= 240){
            OCR0A = 100;
        }
    }

}

ISR(ADC_vect)
{
 Val = ADC;
    if (Val <10){    
        if (OCR2A < 240){
        OCR2A = OCR2A + 1 ;         //go left     
        }      
    }
    else if (Val > 900){ 
        if (OCR2A > 100){
        OCR2A = OCR2A - 1;          //go right
        }
    } 
}
