#include "DynamicArray.h"
#include <iostream>

int main() {
	DynamicArray<int> arr = DynamicArray<int>();

	arr.push(5);
	arr.push(6);
	arr.push(7);
	arr.push(8);

	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr.at(i) << "\n";
	}
	for (int i = 0; i < 40; ++i) {
		std::cout << "#";
	}
	std::cout << "\n";

	arr.prepend(120);
	arr.push(10);

	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr.at(i) << "\n";
	}

	for (int i = 0; i < 40; ++i) {
		std::cout << "#";
	}
	std::cout << "\n";

	arr.del(5);
	arr.remove(8);
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr.at(i) << "\n";
	}
}