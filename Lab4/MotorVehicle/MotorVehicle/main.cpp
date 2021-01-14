
#include <iostream>
#include <vector>
#include "motorVehicle.h"

void engineMenu(VehicleLists* lists) {
	char input;
	bool inMenu = true;
	while (inMenu) {
		printf("\nEngine Menu\n1: Add new engine to list\n2: Print engine list\n3: Change existing engine\n4: Delete an engine\n0: Back\n\ninput> ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			lists->addEngine();
			break;
		case '2':
			lists->printEngineList();
			break;
		case '3':
			lists->printEngineList();
			lists->changeEngine();
			break;
		case '4':
			lists->printEngineList();
			lists->deleteEngine();
			break;
		case '0':
		case '\0':
			inMenu = false;
			break;
		default:
			break;
		}
	}
}

void bodyMenu(VehicleLists* lists) {
	char input;
	bool inMenu = true;
	while (inMenu) {
		printf("\nCar Body Menu\n1: Add new car body\n2: Print car body list\n3: Change existing car body\n4: Delete a car body\n0: Back\n\ninput> ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			lists->addBody();
			break;
		case '2':
			lists->printBodyList();
			break;
		case '3':
			lists->printBodyList();
			lists->changeBody();
			break;
		case '4':
			lists->printBodyList();
			lists->deleteBody();
			break;
		case '0':
		case '\0':
			inMenu = false;
			break;
		default:
			break;
		}
	}
}

void ownerMenu(VehicleLists* lists) {
	char input;
	bool inMenu = true;
	while (inMenu) {
		printf("\nOwner Menu (Customers)\n1: Add a new Customer to list\n2: Print Customer list\n3: Change existing Customer\n4: Delete a Customer\n0: Back\n\ninput> ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			lists->addCustomer();
			break;
		case '2':
			lists->printCustomerList();
			break;
		case '3':
			lists->printCustomerList();
			lists->changeCustomer();
			break;
		case '4':
			lists->printCustomerList();
			lists->deleteCustomer();
			break;
		case '0':
		case '\0':
			inMenu = false;
			break;
		default:
			break;
		}
	}
}

void vehicleMenu(VehicleLists* lists) {
	char input;
	bool inMenu = true;
	while (inMenu) {
		printf("\nVehicle Menu\n1: Add new vehicle to list\n2: Print vehicle list\n3: Change existing vehicle\n4: Delete an vehicle\n0: Back\n\ninput> ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		switch (input)
		{
		case '1':
			lists->addVehicle();
			break;
		case '2':
			lists->printVehicleList();
			break;
		case '3':
			lists->printVehicleList();
			lists->changeVehicle();
			break;
		case '4':
			lists->printVehicleList();
			lists->deleteVehicle();
			break;
		case '0':
		case '\0':
			inMenu = false;
			break;
		default:
			break;
		}
	}
}

void test() {
	MotorVehicle testMotor;
	testMotor.setTires(4);
	testMotor.print();
}

void mainMenu(VehicleLists* lists) {
	char input;
	bool programOn = true;
	while (programOn) {
		printf("\nMain Menu\n1: Engine Menu\n2: Car Body Menu\n3: Owner Menu (Customers)\n4: Vehicle Menu\n0: End\n\ninput> ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			engineMenu(lists);
			break;
		case '2':
			bodyMenu(lists);
			break;
		case '3':
			ownerMenu(lists);
			break;
		case '4':
			vehicleMenu(lists);
			break;
		case 't':
			test();
			break;
		case '0':
		//case '\0':
			printf("\nGood Bye\n");
			lists->exit();
			programOn = false;
			break;
		default:
			break;
		}
	}
}

int main(void) {
	Engine e1(0.8, 8), e2(0.9, 6);
	Body b1("Blue", 1.2, 0.8), b2("Green", 1.5, 1.7);
	Person p1("Kalle", "Frö 8", false), p2("Sven", "Gatangatan 3", true);
	//MotorVehicle m1(e1, b1, p1, 4, "Kool Kar");
	VehicleLists lists;
	lists.engineList.push_back(e1);
	lists.engineList.push_back(e2);
	lists.bodyList.push_back(b1);
	lists.bodyList.push_back(b2);
	lists.ownerList.push_back(p1);
	lists.ownerList.push_back(p2);
	//lists.MVList.push_back(m1);
	mainMenu(&lists);
}