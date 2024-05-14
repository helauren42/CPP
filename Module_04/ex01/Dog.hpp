/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:51:00 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 00:45:09 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog& originalDog);
		Dog&	operator=(const Dog& copy);
		~Dog();
		void	makeSound() const;
		void	setTinyIdea();
		void	callBrainOutput();
	private:
		Brain	*brainny;
};