/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:37:04 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 05:02:36 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(Cat& originalCat);
		Cat&	operator=(const Cat& copy);
		~Cat();
		void	makeSound() const;
		void	callBrainOutput();
	private:
		Brain	*brainny;
};
