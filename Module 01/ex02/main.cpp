#include "Weapon.hpp"

int	main(void)
{
	std::string		s = "hi this is brain";
	std::string*	ptr = &s;
	std::string&	ref = s;

	std::cout << "Address using pointer : " << std::hex << ptr << std::endl;
	std::cout << "Address using reference : " << std::hex << &ref << std::endl;
	std::cout << "Value using pointer : " << *ptr << std::endl;
	std::cout << "Value using reference : " << ref << std::endl;
	return (0);
}
