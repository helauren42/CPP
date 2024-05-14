/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:49:44 by helauren          #+#    #+#             */
/*   Updated: 2024/05/14 18:22:06 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdint.h>
#include <stdlib.h>

	// Base *ret;
	// Base	*ptr = new Base();
	// uintptr_t rand;
	// static	uintptr_t previous = 0;
	// static	uintptr_t preprevious = 0;

	// rand = reinterpret_cast<uintptr_t>(ptr);
	// rand -= 1;
	// rand = (rand / 12) * 17 ;
	// rand -= 1;
	// if((int)previous == (int)rand)
	// {
	// 	rand = rand % 1000;
	// 	rand--;
	// 	rand = rand * 5;
	// }
	// if((int)preprevious == (int)rand)
	// {
	// 	rand = rand % 50;
	// 	rand++;
	// 	rand = rand *7;
	// }

Base *generate(uintptr_t addr)
{
	Base				*ret;
	static uintptr_t	incr = 0;

	srand(addr + incr);
	switch (rand() % 3)
	{
		case 0:
			std::cout << "created A class\n";
			ret = new A();
			break;
		case 1:
			std::cout << "created B class\n";
			ret = new B();
			break;
		case 2:
			std::cout << "created C class\n";
			ret = new C();
			break;
		default :
			std::cerr << "class creation error\n";
			ret = NULL;
			break ;
	}
	incr++;
	return(ret);
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "It is an A class\n";
	else if(dynamic_cast<B*>(p))
		std::cout << "It is a B class\n";
	else if(dynamic_cast<C*>(p))
		std::cout << "It is a C class\n";
	else
		std::cout << "apparently it's not any class\n";
}

void identify(Base& p)
{
	try
	{
		if(dynamic_cast<A*>(&p))
			std::cout << "It is an A class\n";
		else if(dynamic_cast<B*>(&p))
			std::cout << "It is a B class\n";
		else if(dynamic_cast<C*>(&p))
			std::cout << "It is a C class\n";
		else
			std::cout << "apparently it's not any class\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(int ac, char **av, char **env)
{
	std::cout << "POINTER\n";

	uintptr_t	addr = reinterpret_cast<uintptr_t>(env);
	Base *p = generate(addr);
	identify(p);
	delete p;
	std::cout << std::endl;
	
	p = generate(addr);
	identify(p);
	delete p;
	std::cout << std::endl;
	
	p = generate(addr);
	identify(p);
	delete p;
	std::cout << std::endl;
	
	p = generate(addr);
	identify(p);
	delete p;
	std::cout << std::endl;

	p = generate(addr);
	identify(p);
	delete p;
	std::cout << std::endl;

	std::cout << "REFERENCE\n";

	p = generate(addr);
	identify(*p);
	delete p;
	std::cout << std::endl;

	p = generate(addr);
	identify(*p);
	delete p;
	std::cout << std::endl;

	p = generate(addr);
	identify(*p);
	delete p;
	std::cout << std::endl;

	p = generate(addr);
	identify(*p);
	delete p;
	std::cout << std::endl;

	p = generate(addr);
	identify(*p);
	delete p;
	std::cout << std::endl;

	p = generate(addr);
	identify(*p);
	delete p;
	std::cout << std::endl;

	return (0);
}