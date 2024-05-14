/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:53:53 by helauren          #+#    #+#             */
/*   Updated: 2023/12/11 18:53:36 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int		i = 1;
	int		j = 0;
	char	c;

	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			c = std::toupper(av[i][j]);
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << '\n';
	return (0);
}
