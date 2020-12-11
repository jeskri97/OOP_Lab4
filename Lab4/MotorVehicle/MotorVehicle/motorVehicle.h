#pragma once

#include <iostream>
#include <string>

class Engine {
private:
	float sizeIntake;
	int cylinderAmount;
public:
	Engine(float sizeIntake, int cylinderAmount);
	Engine();
	float getSizeIntake();
	int getCylinderAmount();
};

class Body {
private:
	std::string color;
	float width, height;
public:
	Body(std::string color, float width, float height);
	Body();
	std::string getColor();
	float getWidth();
	float getHeight();
};

class Person {
private:
	std::string name;
	std::string address;
	bool allowedToDrive;
public:
	Person(std::string name, std::string address, bool allowedToDrive);
	Person();
	std::string getName();
	std::string getAddress();
	bool getAllowedToDrive();
};

class MotorVehicle {
private:
	Engine engine;
	Body body;
	Person owner;
	float* tireDiameter;
	int tireAmount;
public:
	MotorVehicle(Engine engine, Body body, Person owner, float* tireDiameter, int tireAmount);
};
