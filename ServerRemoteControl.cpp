/*
 * ServerRemoteControl.cpp
 *
 *  Created on: 14.12.2014
 *      Author: kripton
 */

#include "ServerRemoteControl.h"


ServerRemoteControl::ServerRemoteControl() {

	/* Write with server address and read from client address */
	radio->openWritingPipe(server_addr);
	radio->openReadingPipe(1, client_addr);

	radio->startListening();

}


ServerRemoteControl::~ServerRemoteControl() {
	// TODO Auto-generated destructor stub
}


bool ServerRemoteControl::sendQuadroInfo(short gyro, short accel) {

	quadInfo.gyro = gyro;
	quadInfo.accel = accel;

	radio->stopListening();
	bool sent = radio->write(&quadInfo, sizeof(QuadroInfo));
	radio->startListening();

	return sent;
}


/* Should call isRead before
 */
QuadroCommand ServerRemoteControl::getFlyCommand() {

	return quadCommand;
}


void ServerRemoteControl::read() {

	if(radio->available()) {
		readSuccess = radio->read(&quadCommand, sizeof(QuadroCommand));
	}
	else {
		readSuccess = false;
	}
}

