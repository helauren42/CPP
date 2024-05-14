/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:41:41 by helauren          #+#    #+#             */
/*   Updated: 2024/02/24 20:59:40 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimals.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	AAnimal animal;
}

// int	main(void)
// {
// 	AAnimal** objects = new AAnimal*[20];
// 	AAnimal*	test;

// 	std::cout << "Allocation / Initialization Section\n";
// 	for (int i = 0; i < 10; i++)
// 		objects[i] = new Cat();
// 	for (int i = 10; i < 20; i++)
// 		objects[i] = new Dog();

// 	test = objects[15];
// 	std::cout << "\nTest operator=\n";
// 	std::cout << "Animal Type = " << test->getType() << "\n";
// 	std::cout << "Animal Sound = ";
// 	test->makeSound();
// 	std::cout << "\n";
// 	std::cout << "\n\nChecking the Animals\n";
// 	for (int i = 0; i < 20; i++)
// 	{
// 		std::cout << "Animal Type = " << objects[i]->getType() << "\n";
// 		std::cout << "Animal Sound = ";
// 		objects[i]->makeSound();
// 		std::cout << "\n";
// 	}
	
// 	std::cout << "\n";
// 	std::cout << "DEEP COPY TEST\n\n";
	
// 	Dog	*dogOg = new Dog();
// 	Dog	*dogCopy = new Dog(*dogOg);
	
// 	std::cout << "OG DOG\n";
// 	std::cout << "\n";
// 	dogOg->setTinyIdea();
// 	dogOg->callBrainOutput();
// 	std::cout << "\n";
// 	std::cout << "DOG COPY\n\n";
// 	std::cout << "\n";
// 	dogCopy->callBrainOutput();
	
// 	delete(dogOg);
// 	delete(dogCopy);

// 	std::cout << "\nFREEING AKA DESTROYING\n\n";

// 	for(int i = 0; i < 20; i++)
// 		delete(objects[i]);
// 	delete[] objects;
// 	return (0);
// }
