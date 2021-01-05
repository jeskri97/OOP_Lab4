
#include <iostream>
#include <string>

#include "motorVehicle.h"

// -----< Constructors >---------------------------------------------------------------------------------------------------------
Engine::Engine(float sizeIntake, int cylinderAmount) {
	this->sizeIntake = sizeIntake;
	this->cylinderAmount = cylinderAmount;
}
Engine::Engine() {
	this->sizeIntake = 0;
	this->cylinderAmount = 0;
}
// -----< Setters >--------------------------------------------------------------------------------------------------------------
void Engine::setSizeIntake(float sizeIntake) {
	this->sizeIntake = sizeIntake;
}
void Engine::setCylinderAmount(int cylinderAmount) {
	this->cylinderAmount = cylinderAmount;
}
// -----< Getters >--------------------------------------------------------------------------------------------------------------
float Engine::getSizeIntake() {
	return this->sizeIntake;
}
int Engine::getCylinderAmount() {
	return this->cylinderAmount;
}
// -----< Print/Debug >----------------------------------------------------------------------------------------------------------
void Engine::print() {
	printf("Size of intake: %g\nCylinder Amount: %i\n", this->sizeIntake, this->cylinderAmount);
}

// -----< Constructors >---------------------------------------------------------------------------------------------------------
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
// -----< Setters >--------------------------------------------------------------------------------------------------------------
void Body::setColor(std::string color) {
	this->color = color;
}
void Body::setWidthHeight(float width, float height) {
	this->width = width;
	this->height = height;
}
// -----< Getters >--------------------------------------------------------------------------------------------------------------
std::string Body::getColor() {
	return this->color;
}
float Body::getWidth() {
	return this->width;
}
float Body::getHeight() {
	return this->height;
}
// -----< Print/Debug >----------------------------------------------------------------------------------------------------------
void Body::print() {
	printf("Color: %s\nWidth / Height: %g / %g\n", this->color.c_str(), this->width, this->height);
}

// -----< Constructors >---------------------------------------------------------------------------------------------------------
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
// -----< Setters >--------------------------------------------------------------------------------------------------------------
void Person::setName(std::string name) {
	this->name = name;
}
void Person::setAddress(std::string address) {
	this->address = address;
}
void Person::setAllowedToDrive(bool allowedToDrive) {
	this->allowedToDrive = allowedToDrive;
}
// -----< Getters >--------------------------------------------------------------------------------------------------------------
std::string Person::getName() {
	return this->name;
}
std::string Person::getAddress() {
	return this->address;
}
bool Person::getAllowedToDrive() {
	return this->allowedToDrive;
}
// -----< Print/Debug >----------------------------------------------------------------------------------------------------------
void Person::print() {
	printf("Name: %s\nAddress: %s\n", this->name.c_str(), this->address.c_str());
	if (this->allowedToDrive)
		printf("Is allowed to drive: YES\n");
	else 
		printf("Is allowed to drive: NO\n");
}

// -----< Constructors >---------------------------------------------------------------------------------------------------------
MotorVehicle::MotorVehicle(Engine engine, Body body, Person owner, float* tireDiameters, int tireAmount, std::string model) {
	this->engine = engine;
	this->body = body;
	this->owner = owner;
	this->tireDiameters = tireDiameters;
	this->tireAmount = tireAmount;
	this->model = model;
}
MotorVehicle::MotorVehicle() {
	this->tireDiameters = NULL;
	this->tireAmount = 0;
}
// -----< Destructor >-----------------------------------------------------------------------------------------------------------
MotorVehicle::~MotorVehicle() {
	delete this->tireDiameters;
}
// -----< Setters >--------------------------------------------------------------------------------------------------------------
void MotorVehicle::setEngine(Engine engine) {
	this->engine = engine;
}
void MotorVehicle::setBody(Body body) {
	this->body = body;
}
void MotorVehicle::setOwner(Person owner) {
	this->owner = owner;
}
void MotorVehicle::setTires(int tireAmount) {
	this->tireAmount = tireAmount;
	this->tireDiameters = (float*)malloc(tireAmount * sizeof(float));
	for (int i = 0; i < tireAmount; i++) {
		float diameter = 0.0f;
		printf("Insert the diameter of tire %i: ", i + 1);
		std::cin >> diameter;
		this->tireDiameters[i] = diameter;
	}
}
void MotorVehicle::setModel(std::string model) {
	this->model = model;
}
// -----< Getters >--------------------------------------------------------------------------------------------------------------
Engine MotorVehicle::getEngine() {
	return this->engine;
}
Body MotorVehicle::getBody() {
	return this->body;
}
Person MotorVehicle::getOwner() {
	return this->owner;
}
float* MotorVehicle::getTireDiameters() {
	return this->tireDiameters;
}
std::string MotorVehicle::getModel() {
	return this->model;
}
// -----< Print/Debug >----------------------------------------------------------------------------------------------------------
void MotorVehicle::print() {
	printf("\tMotor Vehicle\nModel: %s\n\tEngine\n", this->model.c_str());
	this->engine.print();
	printf("\tBody\n");
	this->body.print();
	printf("\tOwner\n");
	this->owner.print();
	printf("Amount of tires: %i\n", this->tireAmount);
	for (int i = 0; i < this->tireAmount; i++) {
		printf("Tire %i diameter: %g\n", i + 1, this->tireDiameters[i]);
	}
}

// -----< Engine List >----------------------------------------------------------------------------------------------------------
void VehicleLists::addEngine() {
	float sizeIntake;
	int cylinderAmount;
	printf("Size of the intake: ");
	std::cin >> sizeIntake;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	printf("Amount of cylinders: ");
	std::cin >> cylinderAmount;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	engineList.push_back(Engine(sizeIntake, cylinderAmount));
}
void VehicleLists::changeEngine() {
	int index;
	float sizeIntake;
	int cylinderAmount;
	if (engineList.size() > 0) {
		printf("Choose an engine to change: ");
		std::cin >> index;
		if (index > engineList.size() || index < 0)
			printf("\nINVALID INDEX: Index outside scope\n");
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Size of the intake: ");
			std::cin >> sizeIntake;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Amount of cylinders: ");
			std::cin >> cylinderAmount;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			engineList[index - 1].setSizeIntake(sizeIntake);
			engineList[index - 1].setCylinderAmount(cylinderAmount);
			printf("Engine %i changed\n", index);
		}
	}
	else
		printf("\nERROR: List empty\n");
}
void VehicleLists::deleteEngine() {
	int index;
	if (engineList.size() > 0) {
		printf("Choose an engine to delete: ");
		std::cin >> index;
		if (index > engineList.size() || index < 0)
			printf("\nINVALID INDEX: Index outside scope\n");
		else {
			engineList.erase(engineList.begin() + index - 1);
			printf("Engine %i removed\n", index);
		}
	}
	else
		printf("\nERROR: List empty\n");
}
void VehicleLists::printEngineList() {
	printf("\n--------------------------------------------------\n");
	for (int i = 0; i < engineList.size(); i++) {
		printf("\tEngine %i\n", i + 1);
		engineList[i].print();
	}
	printf("--------------------------------------------------\n");
}
// -----< Body List >------------------------------------------------------------------------------------------------------------
void VehicleLists::addBody() {
	std::string color;
	float width, height;
	printf("Car body color: ");
	std::getline(std::cin, color);
	printf("Width: ");
	std::cin >> width;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	printf("Height: ");
	std::cin >> height;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	bodyList.push_back(Body(color, width, height));
}
void VehicleLists::changeBody() {
	int index;
	std::string color;
	float width, height;
	if (bodyList.size() > 0) {
		printf("Choose an car body to change: ");
		std::cin >> index;
		if (index > bodyList.size() || index < 0)
			printf("\nINVALID INDEX: Index outside scope\n");
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Car body color: ");
			std::getline(std::cin, color);
			printf("Width: ");
			std::cin >> width;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Height: ");
			std::cin >> height;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			bodyList[index - 1].setColor(color);
			bodyList[index - 1].setWidthHeight(width, height);
			printf("Car body %i changed\n", index);
		}
	}
	else
		printf("\nERROR: List empty\n");
}
void VehicleLists::deleteBody() {
	int index;
	if (bodyList.size() > 0) {
		printf("Choose an car body to delete: ");
		std::cin >> index;
		if (index > bodyList.size() || index < 0)
			printf("\nINVALID INDEX: Index outside scope\n");
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			bodyList.erase(bodyList.begin() + index - 1);
			printf("Car body %i removed\n", index);
		}
	}
	else
		printf("\nERROR: List empty\n");
}
void VehicleLists::printBodyList() {
	printf("\n--------------------------------------------------\n");
	for (int i = 0; i < bodyList.size(); i++) {
		printf("\tCar body %i\n", i + 1);
		bodyList[i].print();
	}
	printf("--------------------------------------------------\n");
}
// -----< Customer List >--------------------------------------------------------------------------------------------------------
void VehicleLists::addCustomer() {
	std::string name, address;
	bool allowedToDrive;
	printf("Customer Name: ");
	std::getline(std::cin, name);
	printf("Customer Address: ");
	std::getline(std::cin, address);
	printf("Customer allowed to drive\n(1: YES, 0: NO)\ninput: ");
	std::cin >> allowedToDrive;
	ownerList.push_back(Person(name, address, allowedToDrive));
}
void VehicleLists::changeCustomer() {
	int index;
	std::string name, address;
	bool allowedToDrive;
	if (ownerList.size() > 0) {
		printf("Choose a customer to change: ");
		std::cin >> index;
		if (index > ownerList.size() || index < 0)
			printf("\nINVALID INDEX: Index outside scope\n");
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Customer Name: ");
			std::getline(std::cin, name);
			printf("Customer Address: ");
			std::getline(std::cin, address);
			printf("Customer allowed to drive\n(1: YES, 0: NO)\ninput: ");
			std::cin >> allowedToDrive;
			ownerList[index - 1].setName(name);
			ownerList[index - 1].setAddress(address);
			ownerList[index - 1].setAllowedToDrive(allowedToDrive);
			printf("Customer %i changed\n", index);
		}
	}
	else
		printf("\nERROR: List empty\n");
}
void VehicleLists::deleteCustomer() {
	int index;
	if (ownerList.size() > 0) {
		printf("Choose an customer to delete: ");
		std::cin >> index;
		if (index > ownerList.size() || index < 0)
			printf("\nINVALID INDEX: Index outside scope\n");
		else {
			ownerList.erase(ownerList.begin() + index - 1);
			printf("Customer %i removed\n", index);
		}
	}
	else
		printf("\nERROR: List empty\n");
}
void VehicleLists::printCustomerList() {
	printf("\n--------------------------------------------------\n");
	for (int i = 0; i < ownerList.size(); i++) {
		printf("\Customer %i\n", i + 1);
		ownerList[i].print();
	}
	printf("--------------------------------------------------\n");
}
// -----< Vehicle List >---------------------------------------------------------------------------------------------------------
void VehicleLists::addVehicle() {
	char input;
	int index;
	Engine engine;
	Body body;
	Person owner;
	float* tireDiameters;
	int tireAmount;
	std::string model;
	printf("\n1: Add existing Engine\n2: Create and add new Engine\n\ninput> ");
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (input)
	{
	case '1':
		this->printEngineList();
		printf("Select an Engine number: ");
		std::cin >> index;
		engine = engineList[index - 1];
		break;
	case '2':
		this->addEngine();
		engine = engineList.back();
		break;
	default:
		printf("invalid choice\n");
		break;
	}
	input = '\0';
	printf("\n1: Add existing car body\n2: Create and add new car body\n\ninput> ");
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (input)
	{
	case '1':
		this->printBodyList();
		printf("Select an car body number: ");
		std::cin >> index;
		body = bodyList[index - 1];
		break;
	case '2':
		this->addBody();
		body = bodyList.back();
		break;
	default:
		printf("invalid choice\n");
		break;
	}
	input = '\0';
	printf("\n1: Add existing Customer\n2: Create and add new Customer\n\ninput> ");
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (input)
	{
	case '1':
		this->printCustomerList();
		printf("Select an Customer number: ");
		std::cin >> index;
		owner = ownerList[index - 1];
		break;
	case '2':
		this->addCustomer();
		owner = ownerList.back();
		break;
	default:
		printf("invalid choice\n");
		break;
	}
	printf("\nInsert tire amount: ");
	std::cin >> tireAmount;

	tireDiameters = (float*)malloc(tireAmount * sizeof(float));
	for (int i = 0; i < tireAmount; i++) {
		float diameter = 0.0f;
		printf("Insert the diameter of tire %i: ", i + 1);
		std::cin >> diameter;
		tireDiameters[i] = diameter;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	printf("\nName of car Model: ");
	std::getline(std::cin, model);

	MVList.push_back(MotorVehicle(engine, body, owner, tireDiameters, tireAmount, model));
}
void VehicleLists::changeVehicle() {
	std::cout << "changeVehicle()\n";
}
void VehicleLists::deleteVehicle() {
	std::cout << "deleteVehicle()\n";
}
void VehicleLists::printVehicleList() {
	printf("\n--------------------------------------------------\n");
	for (int i = 0; i < engineList.size(); i++) {
		printf("\Vehicle %i\n", i + 1);
		MVList[i].print();
	}
	printf("--------------------------------------------------\n");
}