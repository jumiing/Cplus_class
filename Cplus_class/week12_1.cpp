#include <iostream>

class Car {
public : 
	virtual void startEngine() {
		std::cout << "Starting the car engine..." << std::endl;
	}
};

class Sedan : public Car {
public :
	void startEngine() override {
		std::cout << "Starting the sedan engine..." << std::endl;
	}
};

int main() {
	Car* carPtr;
	Sedan mySedan;

	carPtr = &mySedan;

	carPtr->startEngine();// sedan EngineÃâ·ÂµÊ

	return 0;
}