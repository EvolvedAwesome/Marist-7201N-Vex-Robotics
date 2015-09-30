#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    selector,       sensorAnalog)
#pragma config(Sensor, in2,    selection5,     sensorAnalog)
#pragma config(Sensor, in3,    selection4,     sensorAnalog)
#pragma config(Sensor, in4,    selection2,     sensorAnalog)
#pragma config(Sensor, in5,    selection3,     sensorAnalog)
#pragma config(Sensor, in6,    selection1,     sensorAnalog)
#pragma config(Sensor, I2C_1,  rightEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  leftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           backLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port3,           rightLift1,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rightLift2,    tmotorVex393, openLoop)
#pragma config(Motor,  port5,           liftClaw2,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           liftClaw1,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           leftLift2,     tmotorVex393, openLoop)
#pragma config(Motor,  port8,           leftLift1,     tmotorVex393, openLoop)
#pragma config(Motor,  port9,           frontRight,    tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port10,          backRight,     tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "DriverFunctions.h"
#include "SelectorFunctions.h"


#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


void pre_auton()
{
		clearLCDLine(0);
		clearLCDLine(1);
	init();
	displayLCDString(0, 0, "7201N Official");
	displayLCDString(1, 0, errors[runDiagnostics()]);
	bStopTasksBetweenModes = true;
}


task autonomous()
{
	pre_auton();
	auton();
}

task usercontrol()
{
	clearLCDLine(0);
	clearLCDLine(1);
	while (true)
	{
		displayLCDString(0, 0, "7201N Official  ");
		displayLCDString(1, 0, errors[runDiagnostics()]);
		PlaySoundFile("sound.wav");
		drive();
	}

}
