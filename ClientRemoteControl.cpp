/*
 * ClientRemoteControl.cpp
 *
 *  Created on: 14.12.2014
 *      Author: kripton
 */

#include "ClientRemoteControl.h"


ClientRemoteControl::ClientRemoteControl() {

	radio->openWritingPipe(client_addr);
	radio->openReadingPipe(1, server_addr);

	radio->startListening();
}


ClientRemoteControl::~ClientRemoteControl() {
	// TODO Auto-generated destructor stub
}


bool ClientRemoteControl::sendFlyCommand(short pitch, short roll, short yaw, short power) {

	quadCommand.pitch = pitch;
	quadCommand.roll = roll;
	quadCommand.yaw = yaw;
	quadCommand.power = power;

	radio->stopListening();
	bool ok = radio->write(&quadCommand, sizeof(QuadroCommand));
	radio->startListening();

	return ok;

}


/* Should call isRead before getting info
 */
QuadroInfo ClientRemoteControl::getQuadroInfo() {

	return quadInfo;
}


/* Read data into quadInfo and set reading flag */
void ClientRemoteControl::read() {

	if(radio->available()) {
		readSuccess = radio->read(&quadInfo, sizeof(QuadroInfo));
	}
	else {
		readSuccess = false;
	}

}

