
#include <iostream>
#include <string>

#include "motorVehicle.h"

Engine::Engine(float sizeIntake, int cylinderAmount) {
	this->sizeIntake = sizeIntake;
	this->cylinderAmount = cylinderAmount;
}
Engine::Engine() {
	this->sizeIntake = 0;
	this->cylinderAmount = 0;
}
float Engine::getSizeIntake() {
	return this->sizeIntake;
}
int Engine::getCylinderAmount() {
	return this->cylinderAmount;
}

Body::Body(std::string color, float width, float height) {
	this->color = color;
	this->width = width;
	this->height = height;
}
Body::Body() {
	this->color = "[COLOR]";
	this->width = 0;
	this->height = 0;
}
std::string Body::getColor() {
	return this->color;
}
float Body::getWidth() {
	return this->width;
}
float Body::getHeight() {
	return this->height;
}

Person::Person(std::string name, std::string address, bool allowedToDrive) {
	this->name = name;
	this->address = address;
	this->allowedToDrive = allowedToDrive;
}
Person::Person() {
	this->name = "[NAME]";
	this->address = "[ADDRESS]";
	this->allowedToDrive = false;
}
std::string Person::getName() {
	return this->name;
}
std::string Person::getAddress() {
	return this->address;
}
bool Person::getAllowedToDrive() {
	return this->allowedToDrive;
}

MotorVehicle::MotorVehicle(Engine engine, Body body, Person owner, float* tireDiameter, int tireAmount) {
	this->engine = engine;
	this->body = body;
	this->owner = owner;
	this->tireDiameter = tireDiameter;
	this->tireAmount = tireAmount;
}

int main(void) {

}