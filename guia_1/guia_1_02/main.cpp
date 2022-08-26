#include "mbed.h"
#include "arm_book_lib.h"
int main()
{
    DigitalIn gasDetector(D2); /* Constructor de DigitalIn con parámetro pin D2*/
    //bool gasDetector;
    
    DigitalOut alarmLed(LED1);/* Constructor de DigitalOut con parámetro pin LED1*/

    gasDetector.mode(PullDown);/* Método de DigitalIn para activar resistencia de pulldown*/
    alarmLed = OFF; /*Asigna a alarmLED el valor OFF */

    while (true) { //Ciclo infinito
        //scanf(D2,gasDetector); 
    
        if ( gasDetector == ON ) { //Si se detectó gas
            alarmLed = ON;         // Encender LED
        }
        
        if ( gasDetector == OFF ) { //Si no se detectó gas
            alarmLed = OFF;         // Apagar LED
        }
    }
}