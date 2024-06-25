/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:28:05 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/25 13:46:50 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void printColor(int colorCode)
{
	std::cout << "\033[38;5;" << colorCode << "m" << "\u2588" << "\033[0m";
}

void calcColor(int intensity)
{
	double x = intensity / 255.0;
	double r, g, b;

	if (x < 0.5)
	{
		r = 1.0 - 2.0 * x;
		g = 2.0 * x;
		b = 0.0;
	}
	else
	{
		r = 0.0;
		g = 1.0 - 2.0 * (x - 0.5);
		b = 2.0 * (x - 0.5);
	}

	int r_index = static_cast<int>(r * 5);
	int g_index = static_cast<int>(g * 5);
	int b_index = static_cast<int>(b * 5);
	int colorCode = 16 + r_index * 36 + g_index * 6 + b_index;
	printColor(colorCode);
}

void printVisibleSpectrum()
{
	for (int i = 0; i < 256; ++i) {
		calcColor(i);
	}
	for (int gray = 232; gray <= 255; ++gray) {
		printColor(gray);
	}
	std::cout << std::endl;
}

int main()
{
	printVisibleSpectrum();
	return 0;
}