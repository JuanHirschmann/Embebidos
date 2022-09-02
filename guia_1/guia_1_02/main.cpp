#include "mbed.h"
#include "arm_book_lib.h"
#include "hal/gpio_api.h"
#include "platform/mbed_toolchain.h"
#include "gpio_object.h"
int main()
{
    gpio_t gasDetector;
    gpio_init_in_ex(&gasDetector, D2,PullDown);

    //DigitalIn gasDetector(D2); /* Constructor de DigitalIn con parámetro pin D2*/
    gpio_t alarmLed;
    gpio_init_out(&alarmLed, LED1);
    
    //DigitalOut alarmLed(LED1);/* Constructor de DigitalOut con parámetro pin LED1*/

    //gasDetector.mode(PullDown);/* Método de DigitalIn para activar resistencia de pulldown*/
    //alarmLed = OFF; /*Asigna a alarmLED el valor OFF */
    gpio_write(&alarmLed, OFF);
    while (true) { //Ciclo infinito
    
        if ( gpio_read(&gasDetector) == ON ) { //Si se detectó gas
            gpio_write(&alarmLed, ON);         // Encender LED
        }
        
        if ( gpio_read(&gasDetector) == OFF ) { //Si no se detectó gas
            gpio_write(&alarmLed, OFF);         // Apagar LED
        }
    }
}