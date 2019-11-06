#include "vehicle.h"

vehicle::vehicle() {
	this->has_name = false;
}

vehicle::vehicle(int a,int b) {
	this->wheel_number = a;
	this->max_speed = b;
}

vehicle::vehicle(int a,int b, bool has) {
        this->wheel_number = a;
        this->max_speed = b;
	this->has_name = has;
}

int vehicle::get_wheel_number() {
	return this->wheel_number;
}

int vehicle::get_max_speed() {
	return this->max_speed;
}

bool vehicle::get_has_name() {
	return this->has_name;
}

const char* vehicle::get_class_name() {
	return "vehicle";
}

void vehicle::set_wheel_number(int a) {
	this->wheel_number = a;
}

void vehicle::set_max_speed(int b) {
	this->max_speed = b;
}

void vehicle::set_has_name(bool c) {
	this->has_name = c;
}
