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

struct Data_struct {
	uint8_t id;
	uint64_t timing;
} data_to_read;


int main(){
	//inizialize usart
	usart_init();

	//inizialize rf receiver
	put_string("RX\n");

	rf_init();

	//channel 2; payload len 9 byte
	rf_config(2,9);

    /* Set the device addresses */
	set_tx_address(tx_address);
    set_rx_address(rx_address);

    uint8_t data;


	while(1){

		if(rf_data_ready())
		{
			rf_get_data(&data_to_read);
			put_int(data_to_read.id);
			put_string("\n");
			put_long(data_to_read.timing);
			put_string("\n");


			TX_MODE(&data_to_read);

			/*Wait for transmission end*/
			while(nrf24_isSending());

			RX_MODE();


		}
	}
}
