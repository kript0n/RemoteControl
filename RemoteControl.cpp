/*
 * RemoteControl.cpp
 *
 *  Created on: 14.12.2014
 *      Author: kripton
 */

#include "RemoteControl.h"


RemoteControl::RemoteControl() {

	/* Create new radio */
	radio = new RF24(rx_pin, tx_pin);
	radio->begin();

	/* 8 bytes of payload will be OK */
	/* Standart number of retries */
	/* 8 bytes(or bits) of CRC will be OK it's not important */
	/* 250kbps might improve signal level */
	radio->setPayloadSize(8);
	radio->setRetries(15, 15);
	radio->setCRCLength(RF24_CRC_8);
	radio->setDataRate(RF24_1MBPS);

}


RemoteControl::~RemoteControl() {

	delete radio;

}


bool RemoteControl::isRead() {

	return readSuccess;
}

