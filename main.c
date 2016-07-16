/*
 * main.c
 *
 *  Created on: Jul 12, 2016
 *      Author: root
 */

#include <avr/io.h>
#include <util/delay.h>

//USART communication
#include "uart.h"
//nRF24L01 lib
#include "nRF24L01.h"



int main(){
	//inizialize usart
	usart_init();
	//inizialize rf receiver
	rf_init();
	rf_config();

	//uint8_t reg = 0x07;
	uint8_t reg = RX_ADDR_P0;

	uint8_t data;

	while(1){
		if(rf_data_ready()){
			put_string("hay algo\n||||	|");
		}else{
			put_string("no hay nada\n");
		}
		_delay_ms(1000);
	}
}
