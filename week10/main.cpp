#include <iostream>
#include "car.h"
#include "bike.h"

int main() {
    car *c1 = new car(4, 100, "c1", true);
    std::cout << c1->get_class_name() << std::endl;
    std::cout << c1->get_car_name() << std::endl;
    std::cout << c1->get_wheel_number() << std::endl;
    std::cout << c1->get_max_speed() << std::endl;
    c1->set_max_speed(120);
    std::cout << c1->get_max_speed() << std::endl;
    std::cout << c1->get_has_name() << std::endl;

    bike *b1 = new bike(2, 80, "b1", 123);
    std::cout << b1->get_class_name() << std::endl;
    std::cout << b1->get_bike_name() << std::endl;
    std::cout << b1->get_wheel_number() << std::endl;
    std::cout << b1->get_max_speed() << std::endl;
    b1->set_max_speed(90);
    std::cout << b1->get_max_speed() << std::endl;
    std::cout << b1->get_bike_number() << std::endl;
    std::cout << b1->get_has_name() << std::endl;

    return 0;
}

