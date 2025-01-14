/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:44:41 by apintus           #+#    #+#             */
/*   Updated: 2025/01/14 14:55:38 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
    (void)copy;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &assign)
{
    (void)assign;
    return (*this);
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    uintptr_t raw;

    raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data*      Serializer::deserialize(uintptr_t raw)
{
    Data*   ptr;

    ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}