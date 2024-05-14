/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:37:04 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 00:25:12 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat& originalCat);
		Cat&	operator=(const Cat& copy);
		~Cat();
		void	makeSound() const;
};
