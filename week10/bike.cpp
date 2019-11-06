#include "bike.h"

bike::bike() {
	
}

bike::bike(int a, int b) {
	this->wheel_number = a;
	this->max_speed = b;
}

bike::bike(int a, int b, char* c) {
	this->wheel_number = a;
	this->max_speed = b;
	this->bike_name = c;
}

bike::bike(int a, int b, char* c, int d) {
        this->wheel_number = a;
        this->max_speed = b;
        this->bike_name = c;
	this->bike_number = d;
}

bike::bike(int a, int b, char* c, int d, bool has) {
        this->wheel_number = a;
        this->max_speed = b;
        this->bike_name = c;
	this->bike_number = d;
	this->has_name = has;
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
