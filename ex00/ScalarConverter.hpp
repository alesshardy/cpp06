/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:11:17 by apintus           #+#    #+#             */
/*   Updated: 2025/01/14 11:31:44 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iomanip>
# include <iostream>
# include <limits>
# include "ConvertLib.hpp"

enum TypeInput
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LIT,
    WRONG
};

class ScalarConverter
{
    private:
            ScalarConverter();
            ScalarConverter(const ScalarConverter &copy);
            ~ScalarConverter();
            
            ScalarConverter &operator=(const ScalarConverter &assign);
            
    public:
            static void convert(const std::string &input);
};

#endif