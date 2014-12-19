/*
 * RemoteControl.h
 *
 *  Created on: 14.12.2014
 *      Author: kripton
 */

#ifndef REMOTECONTROL_H_
#define REMOTECONTROL_H_

#include "types.h"
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>


class RemoteControl {

public:

	RemoteControl();
	virtual ~RemoteControl();

	bool isRead();

	virtual void read()=0;


protected:

	RF24* radio;
	QuadroCommand quadCommand;
	QuadroInfo quadInfo;
	bool readSuccess = false;

	const uint8_t client_addr = 0xF0F0F0F0A1;
	const uint8_t server_addr = 0xF0F0F0F0B1;


private:

	const short rx_pin = 9;
	const short tx_pin = 10;

};

#endif /* REMOTECONTROL_H_ */
