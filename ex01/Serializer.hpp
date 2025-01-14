/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:39:10 by apintus           #+#    #+#             */
/*   Updated: 2025/01/14 14:52:38 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    private:
            Serializer();
            Serializer(const Serializer &copy);
            Serializer &operator=(const Serializer &assign);
            ~Serializer();
            
    public:
            static uintptr_t    serialize(Data* ptr);
            static Data*        deserialize(uintptr_t raw);
};

#endif