#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

typedef struct {

public:
	short pitch;
	short yaw;
	short roll;
	short power;
} QuadroCommand;


typedef struct {

public:
	short gyro;
	short accel;

} QuadroInfo;

#endif
