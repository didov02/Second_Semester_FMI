#include <iostream>
#include "Pair.hpp"

int main()
{
	Pair<int> p1;
	int element1, element2;
	std::cout << "First element of first pair: ";
	std::cin >> element1;

	std::cout << "Second element of first pair: ";
	std::cin >> element2;

	p1.setFirstElement(element1);
	p1.setSecondElement(element2);
	
	std::cout << p1.getFirstElement() << std::endl;
	std::cout << p1.getSecondElement() << std::endl;

	std::cout << "Biggest element in first pair: ";
	std::cout << p1.getMaxElement() << std::endl;


	Pair<int> p2;
	int element3, element4;
	std::cout << "First element of second pair: ";
	std::cin >> element3;

	std::cout << "Second element of second pair: ";
	std::cin >> element4;

	p2.setFirstElement(element3);
	p2.setSecondElement(element4);

	std::cout << p2.getFirstElement() << std::endl;
	std::cout << p2.getSecondElement() << std::endl;

	std::cout << "Biggest element in second pair: ";
	std::cout << p2.getMaxElement() << std::endl;
	
	std::cout << "Are pairs different? " << std::boolalpha << (p1 != p2) << std::endl;
	std::cout << "Are pairs equal? " << std::boolalpha << (p1 == p2) << std::endl;
	
}