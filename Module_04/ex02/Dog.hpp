/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:51:00 by helauren          #+#    #+#             */
/*   Updated: 2024/02/24 20:51:58 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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