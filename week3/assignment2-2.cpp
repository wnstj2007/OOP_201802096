#include <iostream>

int main() {
	char *a = "ABC";
	char b[] = "ABC";

	b[0] = 'a';
	std::cout << b << std::endl;
}
