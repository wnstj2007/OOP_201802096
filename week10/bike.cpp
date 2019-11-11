#include "bike.h"

bike::bike() : vehicle() {}

bike::bike(int a, int b) : vehicle(a,b) {}

bike::bike(int a, int b, char* c) : vehicle(a,b) {
	this->bike_name = c;
}

bike::bike(int a, int b, char* c, int d) : vehicle(a,b) {
        this->bike_name = c;
	this->bike_number = d;
}

bike::bike(int a, int b, char* c, int d, bool has) : vehicle(a,b,has) {
        this->bike_name = c;
	this->bike_number = d;
}

char* bike::get_bike_name() {
	return this->bike_name;
}

int bike::get_bike_number() {
	return this->bike_number;
}

const char* bike::get_class_name() {
	return "bike";
}

void bike::set_bike_name(char* c) {
	this->bike_name = c;
}

void bike::set_bike_number(int d) {
	this->bike_number = d;
}
