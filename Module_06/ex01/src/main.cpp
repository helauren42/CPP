/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:08:43 by helauren          #+#    #+#             */
/*   Updated: 2024/05/14 18:16:17 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"
#include "../incl/Data.hpp"


int	main(int ac, char **av)
{
	Data	*data = new Data(5645, "whatever");

	std::cout << *data;
	uintptr_t	ptr_val = Serializer::serialize(data);
	std::cout << ptr_val << std::endl;
	
	Data	*data_cpy = const_cast<Data*>(Serializer::deserialize(ptr_val));
	std::cout << *data_cpy;
}


// int	main(int ac, char **av)
// {
// 	Serializer	A;
// 	Data		*data = new Data(56, "ewriew", true);
// 	Damn		Here(data);

// 	Here.actionPlan();
// 	delete data;
// }
