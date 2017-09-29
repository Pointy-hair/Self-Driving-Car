#include "UltrasonicSensor.h"
#include <serial.h>

UltrasonicSensor::UltrasonicSensor(int pin) {
	sensorPin = pin;
	voltage = analogRead(sensorPin);
}

UltrasonicSensor::~UltrasonicSensor() {}

double UltrasonicSensor::getDistance()
{
	int voltage = analogRead(sensorPin); //0 - 1023
	double distance = voltage * (4650.0 / 1023.0) + 350; //Converting 0 - 1023 to 350mm - 5000mm
	return distance;
}

int UltrasonicSensor::getVoltage()
{
	return voltage;
}