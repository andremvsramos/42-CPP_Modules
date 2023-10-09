/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:07:48 by andvieir          #+#    #+#             */
/*   Updated: 2023/10/09 11:27:26 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Please input a filename and two strings\n", 1);

	std::string	line;

	std::string	filename(av[1]);
	std::string	s1(av[2]);
	std::string	s2(av[3]);

	std::string	output(filename);
	output.append(".replace");

	const char	*file_in = filename.c_str();
	const char	*file_out = output.c_str();

	std::ifstream	in(file_in);
	std::ofstream	out(file_out);

	if (in.is_open() && out.is_open())
	{
		while (getline(in, line))
		{
			if (line.find(s1) != std::string::npos)
			{
				size_t	pos = 0;
				while (true)
				{
					pos = line.find(s1, pos);
					if (pos == std::string::npos)
						break ;
					line.erase(pos, s1.length());
					line.insert(pos, s2);
					pos += s2.length();
				}
			}
			out << line << "\n";
		}
		in.close();
		out.close();
	}
	if (in.is_open())
		in.close();
	if (out.is_open())
		out.close();
	return (0);
}
