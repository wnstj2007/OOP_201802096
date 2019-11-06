#include "vehicle.h"

class car : public vehicle {
private:
	char* car_name;
public:
	car();
	car(int,int);
	car(int,int,char*);
	car(int,int,char*,bool);
	char* get_car_name();
	const char* get_class_name();
	void set_car_name(char*);
};
