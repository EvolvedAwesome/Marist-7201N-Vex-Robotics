#pragma config(Sensor, in1,    selector,       sensorAnalog)
#pragma config(Motor,  port1,           backLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           rightLift1,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rightLift2,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           liftClaw1,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           leftLift2,     tmotorVex393, openLoop)
#pragma config(Motor,  port8,           leftLift1,     tmotorVex393, openLoop)
#pragma config(Motor,  port9,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          backRight,     tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "DriverFunctions.h"
#include "SelectorFunctions.h"
#include "constants.h"


task main(){
	init();
	while(true){ //ONLY for testing
		autonomous();
		//drive();
	}
		//blueRight();

}
