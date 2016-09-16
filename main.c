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

/*define addr*/
uint8_t tx_address[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};
uint8_t rx_address[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};

int main(){
	//inizialize usart
	usart_init();

	//inizialize rf receiver
	rf_init();

	//channel 2; payload len 4 byte
	rf_config(2,1);

    /* Set the device addresses */
	set_tx_address(tx_address);
    set_rx_address(rx_address);

    uint8_t data;

	while(1){
		if(rf_data_ready())
		{
			rf_get_data(&data);
			put_int(data);

		}
	}
}
