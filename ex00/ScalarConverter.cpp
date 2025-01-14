/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:11:14 by apintus           #+#    #+#             */
/*   Updated: 2025/01/14 11:38:04 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign)
{
    (void)assign;
    return (*this);
}

//Checker Functions

static bool isPseudoLiteral(const std::string &input)
{
    if (!input.compare("nan") || !input.compare("nanf") || !input.compare("inf") || !input.compare("inff") ||!input.compare("+inf") || !input.compare("+inff") || !input.compare("-inf") || !input.compare("-inff"))
        return (true);
    return (false);
}

static bool isChar(const std::string &input)
{
    if (input.length() == 1 && !std::isdigit(input.at(0)))
        return (true);
    return (false);
}

static bool isInt(const std::string &input)
{
    size_t i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    for (size_t j = i; j < input.length(); j++)
    {
        if (!std::isdigit(input[j]))
            return (false);
    }
    try {
        double d = ConvertLib::ft_stod(input);
        if ( d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            return (false);
    } catch (std::exception &e) {
        return (false);
    }

    return (true);
}

static bool isFloat(const std::string &input)
{
    size_t i = 0;
    int dot = 0;

    if (!input.compare("nanf") || !input.compare("inff") || !input.compare("+inff") || !input.compare("-inff"))
        return (true);
    if (input.at(input.length() - 1) != 'f')
        return (false);
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (size_t j = i; j < input.length(); j++)
    {
        if (input[j] == '.')
            dot++;
        else if (!std::isdigit(input[j]) && j != input.size() - 1)
            return (false);
    }
    if (dot == 1)
        return (true);
    return (false);
}

static bool isDouble(const std::string &input)
{
    size_t i = 0;
    int dot = 0;

    if (!input.compare("nan") || !input.compare("inf") || !input.compare("+inf") || !input.compare("-inf"))
        return (true);
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (size_t j = i; j < input.length(); j++)
    {
        if (input[j] == '.')
            dot++;
        else if (!std::isdigit(input[j]))
            return (false);
    }
    if (dot == 1)
        return (true);
    return (false);
}

TypeInput   getType(const std::string &input)
{
    if (isPseudoLiteral(input))
        return (PSEUDO_LIT);
    else if (isChar(input))
        return (CHAR);
    else if (isInt(input))
        return (INT);
    else if (isFloat(input))
        return (FLOAT);
    else if (isDouble(input))
        return (DOUBLE);
    return (WRONG);
}

void    ScalarConverter::convert(const std::string &input)
{
    TypeInput   typeInput;

    typeInput = getType(input);
    switch (typeInput)
    {
        case PSEUDO_LIT:
            ConvertLib::convertPseudoLiteral(input);
            break;
        case CHAR:
            ConvertLib::convertChar(input);
            break;
        case INT:
            ConvertLib::convertInt(input);
            break;
        case FLOAT:
            ConvertLib::convertFloat(input);
            break;
        case DOUBLE:
            ConvertLib::convertDouble(input);
            break;
        case WRONG:
            std::cout << "Wrong input" << std::endl;
            break;
        default:
            break;
    }
}
