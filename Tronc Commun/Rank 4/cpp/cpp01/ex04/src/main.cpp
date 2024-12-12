/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:07:38 by basverdi          #+#    #+#             */
/*   Updated: 2024/12/12 17:37:04 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replaceAllOccurrences(const std::string &str, const std::string &s1, const std::string &s2)
{
	std::string result;
	size_t pos = 0;
	size_t foundPos;

	if (s1.empty())
		return (str);

	while ((foundPos = str.find(s1, pos)) != std::string::npos) {
		result.append(str, pos, foundPos - pos);
		result.append(s2);
		pos = foundPos + s1.length();
	}

	result.append(str, pos, str.length() - pos);
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Usage: ./program <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);

	if (s1.empty()) {
		std::cerr << "s1 can't be empty" << std::endl;
		return (1);
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << filename + " can't be open" << std::endl;
		return (1);
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << filename + ".replace can't be created" << std::endl;
		inputFile.close();
		return (1);
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		outputFile << replaceAllOccurrences(line, s1, s2);
		if (!inputFile.eof())
			outputFile << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return (0);
}
