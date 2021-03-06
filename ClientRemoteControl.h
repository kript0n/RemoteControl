/*
 * ClientRemoteControl.h
 *
 *  Created on: 14.12.2014
 *      Author: kripton
 */

#ifndef CLIENTREMOTECONTROL_H_
#define CLIENTREMOTECONTROL_H_

#include "RemoteControl.h"

class ClientRemoteControl : public RemoteControl {


public:

	ClientRemoteControl();
	virtual ~ClientRemoteControl();

	bool sendFlyCommand(short pitch, short roll, short yaw, short power);
	QuadroInfo getQuadroInfo();

	void read();

};

#endif /* CLIENTREMOTECONTROL_H_ */
