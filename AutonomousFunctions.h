#pragma config(Sensor, in1,    selector,       sensorAnalog)
#pragma config(Sensor, in1,    selector,       sensorAnalog)
#pragma config(Sensor, I2C_1,  rightEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  leftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
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

void waitForTruth(bool truth){
	while(!truth){
		wait1Msec(1);
	}
}

void resetEncoders(){
	right_Encoder = 0;
	left_Encoder = 0;
}

//linear:  straight  forward, backward in any direction
void linearMove(int power){
	LEFT_BACK =	power;
	RIGHT_BACK = power;
	LEFT_FRONT = power;
	RIGHT_FRONT = power;
}




//lift arm function for the robot
void liftArm(const string direction, int power, int time) {
	if(direction == "down") {
		RIGHT_LIFT_MOTOR1 = power;
		RIGHT_LIFT_MOTOR2 = power;
		LEFT_LIFT_MOTOR1 = -power;
		LEFT_LIFT_MOTOR2 = -power;
	}
	if(direction == "up") {
		RIGHT_LIFT_MOTOR1 = -power;
		RIGHT_LIFT_MOTOR2 = -power;
		LEFT_LIFT_MOTOR1 = power;
		LEFT_LIFT_MOTOR2 = power;
	}
	wait1Msec(time);
	RIGHT_LIFT_MOTOR1 = 0;
	RIGHT_LIFT_MOTOR2 = 0;
	LEFT_LIFT_MOTOR1 = 0;
	LEFT_LIFT_MOTOR2 = 0;
}

//lift claw function for the claw
void controlClaw(const string direction, int power, int time) {
	if(direction == "down") {
		LIFT_CLAW_MOTOR1  = -power;
		LIFT_CLAW_MOTOR2 = -power;
	}
	if(direction == "up") {
		LIFT_CLAW_MOTOR1  = power;
		LIFT_CLAW_MOTOR2 = power;
	}
	wait1Msec(time);
	LIFT_CLAW_MOTOR1 = 0;
	LIFT_CLAW_MOTOR2 = 0;
}

//lateral move will decide in which direction the robot will go(left and right)
void lateralMove(const string direction, int power) {
	if(direction == "left") {
		LEFT_FRONT = power;
		LEFT_BACK = -power;
		RIGHT_FRONT = -power;
		RIGHT_BACK = power;
	}
	if(direction == "right") {
		LEFT_FRONT = -power;
		LEFT_BACK = power;
		RIGHT_FRONT = power;
		RIGHT_BACK = -power;
	}
}

void turnInPlace(const string direction, int power){
	if(direction == "right"){
		LEFT_FRONT = power;
		LEFT_BACK = power;
		RIGHT_FRONT = -power;
		RIGHT_BACK = -power;
	}
	if (direction ==  "left") {
		LEFT_BACK =	-power;
		RIGHT_BACK = power;
		LEFT_FRONT = -power;
		RIGHT_FRONT = power;
	}

}

void forwardTick(int power, int tick){
	resetEncoders();
	linearMove(power);
	while(left_Encoder < tick){}
	linearMove(0);
}

void backwardTick(int power, int tick){
	resetEncoders();
	linearMove(-power);
	while(right_Encoder < tick){}
	linearMove(0);
}

void turnLeftTick(int power, int tick){
	resetEncoders();
	turnInPlace("left", power);
	while(right_Encoder < tick){}
	linearMove(0);
}

void turnRightTick(int power, int tick){
	resetEncoders();
	LEFT_FRONT = power;
	LEFT_BACK = power;
	RIGHT_BACK = -power;
	LEFT_BACK = -power;
	while(left_Encoder < tick){}
	linearMove(0);
}

void strafeLeft(int power, int tick){
	RIGHT_BACK = -power;
	RIGHT_FRONT = power;
	LEFT_BACK = power;
	LEFT_FRONT = -power;
	wait1Msec(tick);
	linearMove(0);
}

void stafeRight(int power, int tick){
	lateralMove("right", power);
	wait1Msec(tick);
	linearMove(0);
}


void forwardTime(int power, int mSecs) {
	linearMove(power);
	wait1Msec(mSecs);
	linearMove(0);
}

void backwardTime(int power, int mSecs) {
	linearMove(-power);
	wait1Msec(mSecs);
	linearMove(0);
}

void leftMoveTime(int power, int mSecs) {
	lateralMove("left", power);
	wait1Msec(mSecs);
	linearMove(0);
}

void rightMoveTime(int power, int mSecs) {
	lateralMove("right", power);
	wait1Msec(mSecs);
	linearMove(0);
}

void holdArm(){
	RIGHT_LIFT_MOTOR1 = -40;
	RIGHT_LIFT_MOTOR2 = -40;
	LEFT_LIFT_MOTOR1 = 40;
	LEFT_LIFT_MOTOR2 = 40;
}


void turnForSeconds(const string direction, float seconds, int power){

	if(direction == "right") {
		LEFT_BACK = power;
		LEFT_FRONT = power;
		RIGHT_FRONT = -power;
		RIGHT_BACK = -power;
	}
	if(direction == "left") {
		LEFT_BACK = -power;
		LEFT_FRONT = -power;
		RIGHT_FRONT = power;
		RIGHT_BACK = power;
	}
	wait1Msec(seconds*1000 );
	LEFT_BACK = 0;
	LEFT_FRONT = 0;
	RIGHT_FRONT = 0;
	RIGHT_BACK = 0;
}


void turnAmount(const string direction, float amount, int power){
	resetEncoders();
	if(direction == "left"){
		turnInPlace(direction, power);
		waitForTruth(right_Encoder >= amount);
		} else {
		turnInPlace(direction, -power);
		waitForTruth(left_Encoder >= amount);
	}
	linearMove(0);
}

void forwardDistance(int power, int amount){
	linearMove(power);
	waitForTruth(right_Encoder >= amount && left_Encoder >= amount);
}

void forwardExact(float amount, int timeCap){
	resetEncoders();
	LEFT_FRONT = (amount-left_Encoder);
	LEFT_BACK = (amount-left_Encoder);
	RIGHT_FRONT = (amount-right_Encoder);
	RIGHT_BACK = (amount-right_Encoder);
	wait1Msec(timeCap);
	linearMove(0);
}

void backwardExact(float amount, int timeCap){
	resetEncoders();
	LEFT_FRONT = -(amount+left_Encoder);
	LEFT_BACK = -(amount+left_Encoder);
	RIGHT_FRONT = -(amount+right_Encoder);
	RIGHT_BACK = -(amount+right_Encoder);
	wait1Msec(timeCap);
	linearMove(0);
}

//Autonomous Programs

void blueRight(){
	controlClaw("down", 127, 200);
	wait1Msec(600);
	liftArm("up", 127, 100);
	holdArm();
	controlClaw("up", 127, 500);
	wait1Msec(100);
	forwardTick(127, 600);
	wait1Msec(600);
	controlClaw("up", 127, 800);
	turnRightTick(-127, 1000);
	controlClaw("down", 127, 5000);
}

void blueLeft(){
	//Unhook
	controlClaw("down", 127, 200);
	wait1Msec(600);
	liftArm("up", 127, 100);
	controlClaw("up", 127, 500);
	wait1Msec(100);
	forwardTick(127, 600);
	wait1Msec(600);
	controlClaw("up", 127, 800);
	wait1Msec(600);
	strafeLeft(-127, 500);
	wait1Msec(300);
	liftArm("up", 127, 2100);
	holdArm();
	wait1Msec(600);
	turnRightTick(-127, 400);
	wait1Msec(600);
	controlClaw("down",127, 10000);
}

void redRight(){
	controlClaw("down", 127, 200);
	wait1Msec(600);
	liftArm("up", 127, 100);
	controlClaw("up", 127, 500);
	wait1Msec(100);
	forwardTick(127, 600);
	wait1Msec(600);
	controlClaw("up", 127, 800);
	wait1Msec(600);
	strafeLeft(127, 500);
	wait1Msec(300);
	liftArm("up", 127, 2100);
	holdArm();
	wait1Msec(600);
	turnRightTick(127, 400);
	wait1Msec(600);
	controlClaw("down",127, 10000);
}

void redLeft(){
		controlClaw("down", 127, 200);
	wait1Msec(600);
	liftArm("up", 127, 100);
	holdArm();
	controlClaw("up", 127, 500);
	wait1Msec(100);
	forwardTick(127, 600);
	wait1Msec(600);
	controlClaw("up", 127, 800);
	turnRightTick(127, 1000);
	controlClaw("down", 127, 5000);
}

void challenge(){
}
