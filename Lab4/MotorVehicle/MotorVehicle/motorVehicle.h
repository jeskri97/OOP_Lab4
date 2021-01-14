#pragma once

#include <iostream>
#include <string>
#include <vector>

class Engine {
private:
	float sizeIntake;
	int cylinderAmount;
public:
	// Constructors
	Engine(float sizeIntake, int cylinderAmount);
	Engine();
	// Setters
	void setSizeIntake(float sizeIntake);
	void setCylinderAmount(int cylinderAmount);
	// Getters
	float getSizeIntake();
	int getCylinderAmount();
	// Print/Debug
	void print();
};

class Body {
private:
	std::string color;
	float width, height;
public:
	// Constructors
	Body(std::string color, float width, float height);
	Body();
	// Setters
	void setColor(std::string color);
	void setWidthHeight(float width, float height);
	// Getters
	std::string getColor();
	float getWidth();
	float getHeight();
	// Print/Debug
	void print();
};

class Person {
private:
	std::string name, address;
	bool allowedToDrive;
public:
	// Constructors
	Person(std::string name, std::string address, bool allowedToDrive);
	Person();
	// Setters
	void setName(std::string name);
	void setAddress(std::string address);
	void setAllowedToDrive(bool allowedToDrive);
	// Getters
	std::string getName();
	std::string getAddress();
	bool getAllowedToDrive();
	// Print/Debug
	void print();
};

class MotorVehicle {
private:
	Engine engine;
	Body body;
	Person owner;
	float* tireDiameters;
	//float* tireDiameters = new float[0];
	int tireAmount;
	std::string model;
	void fixTires();
public:
	// Constructors
	MotorVehicle(Engine engine, Body body, Person owner, int tireAmount, std::string model);
	MotorVehicle();
	// Destructor
	~MotorVehicle();
	// Setters
	void setEngine(Engine engine);
	void setBody(Body body);
	void setOwner(Person owner);
	void setTires(int tireAmount);
	void setModel(std::string model);
	// Getters
	Engine getEngine();
	Body getBody();
	Person getOwner();
	float* getTireDiameters();
	std::string getModel();
	// Print/Debug
	void print();
};

class VehicleLists {
public:
	std::vector<Engine> engineList;
	std::vector<Body> bodyList;
	std::vector<Person> ownerList;
	std::vector<MotorVehicle*> MVList;
	// Engine List
	void addEngine();
	void changeEngine();
	void deleteEngine();
	void printEngineList();
	// Body List
	void addBody();
	void changeBody();
	void deleteBody();
	void printBodyList();
	// Customer List
	void addCustomer();
	void changeCustomer();
	void deleteCustomer();
	void printCustomerList();
	// Vehicle List
	void addVehicle();
	void changeVehicle();
	void deleteVehicle();
	void printVehicleList();

	void exit();
};