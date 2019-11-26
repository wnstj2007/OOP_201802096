#include <iostream>

int fib(int i) {
	if(i == 0 || i == 1) return i;
	if(i==2) return 1;
	return fib(i-1)+fib(i-2);
}

int main() {
	int i;
	std::cin >> i;
	int val = fib(i);

	std::cout << val << std::endl;
	return 0;
}
