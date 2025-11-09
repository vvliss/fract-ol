/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:25:42 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/08 20:53:09 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	parse_fraction(const char *str)
{
    double	fraction;
    double	divisor;

    fraction = 0.0;
    divisor = 10.0;
    while (*str >= '0' && *str <= '9')
    {
        fraction += (*str - '0') / divisor;
        divisor *= 10.0;
        str++;
    }
    return (fraction);
}

double	ft_atof(const char *str)
{
    double	integer;
    double	result;
    int		sign;

    integer = 0.0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        integer = integer * 10.0 + (*str - '0');
        str++;
    }
    result = integer;
    if (*str == '.')
    {
        str++;
        result += parse_fraction(str);
    }
    return (result * sign);
}
