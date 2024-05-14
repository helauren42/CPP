/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:03:41 by helauren          #+#    #+#             */
/*   Updated: 2024/02/06 03:50:59 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	parseFileContent(std::ifstream &file, std::string& fileContent)
{
	std::string	buffer;
	std::string	s1;
	std::string	s2;

	while(1)
	{
		std::getline(file, buffer, '\n');
		fileContent.append(buffer);
		if(file.eof() == 0)
			fileContent.append("\n");
		else
			break ;
	}
}

int cpp_strstr(std::string stack, std::string needle, int i)
{
	while(stack[i])
	{
		if (stack.compare(i, needle.length(), needle) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	replace_needle(std::string& fileContent, int pos, std::string needle, std::string replacement)
{
	std::string	pre;
	std::string	post;

	(void) needle;
	pre = fileContent.substr(0, pos);
	post = fileContent.substr(pos + replacement.length(), fileContent.length());
	fileContent = pre + replacement + post;
}

void	ditch_s1_for_s2(std::string& fileContent, std::string s1, std::string s2)
{
	int		pos;
	std::string	caught;

	pos = cpp_strstr(fileContent, s1, 0);
	while(pos >= 0)
	{
		replace_needle(fileContent, pos, s1, s2);
		pos = cpp_strstr(fileContent, s1, pos +1);
	}
};

int	main(int ac, char **av)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	file;
	std::ofstream	outputFile;
	std::string		fileContent;

	if(ac != 4)
	{
		std::cerr << "wrong number of arguments, needed 3 !!!!!\n";
		return (1);
	}
	filename = av[1];
	file.open(filename.c_str());
	s1 = av[2];
	s2 = av[3];
	if(file.is_open() == 0)
	{
		std::cerr << "could not read from file : " << filename << " double check name and location\n";
		return (1);
	}
	parseFileContent(file, fileContent);
	if(DEBUG)
		std::cout << "PARSE FILE CONTENT :\n" << fileContent;
	ditch_s1_for_s2(fileContent, s1, s2);
	file.close();
	if(DEBUG)
		std::cout << "POST MOD FILE CONTENT :\n" << fileContent;
	outputFile.open("new");
	if(outputFile.is_open() == 0)
		std::cerr << "could not create output file : " << filename << "\n";
	outputFile << fileContent;
	return (0);
}
