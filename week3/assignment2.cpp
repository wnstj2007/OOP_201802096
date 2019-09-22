#include <iostream>

int main() {
	char *a = "ABC";
	char b[] = "ABC";

	a[0] = 'b';
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}

