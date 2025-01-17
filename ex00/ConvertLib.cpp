/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:22:27 by apintus           #+#    #+#             */
/*   Updated: 2025/01/14 13:30:46 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvertLib.hpp"

ConvertLib::ConvertLib()
{
}

ConvertLib::ConvertLib(const ConvertLib &copy)
{
    (void)copy;
}

ConvertLib::~ConvertLib()
{
}

ConvertLib  &ConvertLib::operator=(const ConvertLib &assign)
{
    (void)assign;
    return (*this);
}

//Library Functions
int ConvertLib::ft_stoi(const std::string &input)
{
    int ret;

    std::istringstream iss(input);
    
    iss >> ret;
    if (iss.fail())
    {
        throw std::invalid_argument("stoi");
    }
    
    return ret;
}

float   ConvertLib::ft_stof(const std::string &input)
{
    float   ret;
    std::string modifiedInput = input;

    //to remove 'f' at the end if here
    if (!input.empty() && input[input.size() - 1] == 'f')
        modifiedInput.erase(modifiedInput.size() - 1);
    
    std::istringstream iss(modifiedInput);

    iss >> ret;
    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("stof");
    return (ret);
}

double  ConvertLib::ft_stod(const std::string &input)
{
    double ret;
    std::istringstream iss(input);

    iss >> ret;
    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("stod");
    return (ret);
}

//Convert Functions
void    ConvertLib::convertChar(const std::string &input)
{
    char    c;

    c = input.at(0);
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    ConvertLib::convertInt(const std::string &input)
{
    int i;

    i = ft_stoi(input);
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(i)))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void    ConvertLib::convertFloat(const std::string &input)
{
    float   f;

    f = ft_stof(input);
    if (f < -std::numeric_limits<char>::max() || f > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "Int: ";
    if (f < -std::numeric_limits<int>::max() || f > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    
    if (f == static_cast<int>(f))
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
}


void    ConvertLib::convertDouble(const std::string &input)
{
    double  d;
    
    d = ft_stod(input);
    if (d < -std::numeric_limits<char>::max() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    std::cout << "float: ";
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else
    {
        if (d == static_cast<float>(d))
            std::cout << std::fixed << std::setprecision(1);
        std::cout << static_cast<float>(d) << "f" << std::endl;
    }
    if (d == static_cast<float>(d))
        std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << d << std::endl;
}

void    ConvertLib::convertPseudoLiteral(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (input == "nan" || input == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input == "-inff" || input == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    (void)input;
}