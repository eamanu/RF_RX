/**
 * @file main.c
 * @author Arias Emmanuel.
 * @date Jul 12, 2016
 * @brief Ejemplo de transmisor usando nRF24L01+.
 *
 * Para el transmisor se utiliza el módulo nRF24L01 + arduino Nano.
 *
 * La disposición de los pines es la siguiente
 *
 * - GND    >  GND
 * - VCC    >  3.3V
 * - CE     >  9
 * - CSN    >  53
 * - SCK    >  52
 * - MOSI 	 >  51
 * - MISO 	 >  50
 * - IRQ    >  No usado
 *
 *	@see http://freektc.blogspot.com.ar/2016/09/nrf24l01-usando-arduino-avr-ii.html
 */

#include <avr/io.h>
#include <util/delay.h>

//USART communication
#include "uart.h"
//nRF24L01 lib
#include "nRF24L01.h"

/*define addr*/
uint8_t tx_address[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};/**<Dirección del transmisor*/
uint8_t rx_address[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};/**<Dirección del receptor*/

int main(){
	//inizialize usart
	usart_init();

	//inizialize rf receiver
	put_string("RX\n");
	rf_init();

	//channel 2; payload len 4 byte
	rf_config(2,1);/** Se configura el radio. Chanel 2. Size payload: 1byte*/

    /* Set the device addresses */
	set_tx_address(tx_address);/** Se setea la dirección del transmisor*/
    set_rx_address(rx_address);/** Se setea la dirección del receptor*/

    uint8_t data;
    put_string("RX\n");
	while(1){

		if(rf_data_ready())
		{
			rf_get_data(&data);
			put_int(data);

		}
	}
}
