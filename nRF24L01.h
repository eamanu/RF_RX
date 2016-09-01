/*
 * nRF24L01.h
 *
 *  Created on: Jul 9, 2016
 *      Author: root
 */

#ifndef COMM_NRF24L01_H_
#define COMM_NRF24L01_H_

#include "nRF24L01_RegisterMap.h"
#include <avr/io.h>

#define CE PORTB5 /*Digital pin 11*/
#define CSN PORTB0 /*Digital pin 53*/

/*write a cmd*/
void rf_w_config_register(uint8_t reg, uint8_t data);

/*write register*/
void rf_write_register(uint8_t reg, uint8_t * data, uint8_t len);

/*read a register*/
void rf_read_register(uint8_t reg, uint8_t * data, uint8_t len);

/*RF config*/
void rf_config(void);

/*Init RF*/
void rf_init(void);

/*Standby-I*/
void StandbyI(void);

/*flush RX fifo*/
void nrf24l01_flushRXfifo(void);

/* flush RX fifo */
void nrf24l01_flushTXfifo(void);

/*RX MODE*/
void RX_MODE(void);

/*Set power Level*/
void setPowerLevel(void);

/*Know if there're data to read*/
uint8_t rf_data_ready();

/*Get Data from RX FIFO payload*/
void rf_get_data(uint8_t * data);




#endif /* COMM_NRF24L01_H_ */

