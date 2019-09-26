#include "set.h"
#include <iostream>
#include <iomanip>

int main(void)
{
	std::cout << "\tTest Set" << std::endl;

	Set s{};
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.remove(3);

	Set s2{};
	s2.insert(5);
	s2.insert(4);

	std::cout << " s: " << s << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	std::cout << std::endl;

	std::cout << "s.isContain(s2): " << std::boolalpha << s.isContain(s2) << std::endl;
	std::cout << " s.length(): " << s.length() << std::endl;
	std::cout << "s2.lenght(): " << s2.length() << std::endl;
	std::cout << std::endl;

	Set s3 = intersection(s, s2);
	std::cout << "Intersection(s, s2): " << s3 << std::endl;

	s3 = association(s, s2);
	std::cout << "Association(s, s2): " << s3 << std::endl;

	s3 = difference(s, s2);
	std::cout << "Differense(s, s2): " << s3 << std::endl;

	std::cin.clear();
	while (std::cin.get() != '\n');
	std::cin.get();
}