/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:07:55 by apintus           #+#    #+#             */
/*   Updated: 2025/01/14 12:05:45 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [input]" << std::endl;
        return (1);
    }

    ScalarConverter::convert(av[1]);


	// Show class non instanciable
    // ScalarConverter converter;
    
    return (0);
}