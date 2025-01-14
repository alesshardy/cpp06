/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertLib.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:22:39 by apintus           #+#    #+#             */
/*   Updated: 2025/01/14 13:04:30 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTLIB_HPP
# define CONVERTLIB_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <iomanip>

class ConvertLib
{
    private :
            ConvertLib();
            ConvertLib(const ConvertLib &copy);
            ~ConvertLib();
            
            ConvertLib &operator=(const ConvertLib &assign);

    public:
            static void convertPseudoLiteral(const std::string &input);
            static void convertChar(const std::string &input);
            static void convertInt(const std::string &input);
            static void convertFloat(const std::string &input);
            static void convertDouble(const std::string &input);

            static int  ft_stoi(const std::string &input);
            static float ft_stof(const std::string &input);
            static double ft_stod(const std::string &input);
};

#endif