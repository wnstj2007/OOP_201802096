#ifndef h
#define h
class vehicle {
protected:
	bool has_name;
	int wheel_number;
	int max_speed;
public:
	vehicle();
	vehicle(int,int);
	vehicle(int,int,bool);
	int get_wheel_number();
	int get_max_speed();
	bool get_has_name();
	const char* get_class_name();
	void set_wheel_number(int);
        void set_max_speed(int);
        void set_has_name(bool);
};
#endif
