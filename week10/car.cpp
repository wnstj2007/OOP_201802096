#include "car.h"

car::car() : vehicle() {}

car::car(int a, int b) : vehicle(a,b) {}

car::car(int a, int b, char* c) : vehicle(a,b) {
	this->car_name = c;
}

car::car(int a, int b, char* c, bool has) : vehicle(a,b,has) {
        this->car_name = c;
}

char* car::get_car_name() {
	return this->car_name;
}

const char* car::get_class_name() {
	return "car";
}

void car::set_car_name(char* c) {
	this->car_name = c;
}
