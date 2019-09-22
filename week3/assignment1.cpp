#include <iostream>

int data = 5;
int bss;

int main() {
	int* stack = new int[2];
	stack[0] = 0;
	char *rodata = "ABC";

	std::cout << "code\t" << (void*) main << std::endl;
	std::cout << "Rodata\t" << (void*) rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "HEAP\t" << stack << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
}
