/*
 * ServerRemoteControl.h
 *
 *  Created on: 14.12.2014
 *      Author: kripton
 */

#ifndef SERVERREMOTECONTROL_H_
#define SERVERREMOTECONTROL_H_


#include "RemoteControl.h"


class ServerRemoteControl : public RemoteControl {

public:

	ServerRemoteControl();
	virtual ~ServerRemoteControl();

	bool sendQuadroInfo(short gyro, short accel);
	QuadroCommand getFlyCommand();

	void read();
	

};

#endif /* SERVERREMOTECONTROL_H_ */
