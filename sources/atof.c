/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:25:42 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 16:58:06 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	parse_decimal(const char *str)
{
	double	decimal;
	int		len;

	decimal = 0.0;
	len = 0;
	while (ft_isdigit(*str))
	{
		decimal = decimal * 10.0 + (*str - '0');
		str++;
		len++;
	}
	while (len-- > 0)
		decimal /= 10.0;
	return (decimal);
}

double	ft_atof(const char *str)
{
	double	integer_part;
	double	decimal_part;
	int		sign;

	integer_part = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') * -2 + 1;
	while (ft_isdigit(*str))
		integer_part = integer_part * 10.0 + (*str++ - '0');
	decimal_part = 0.0;
	if (*str == '.')
		decimal_part = parse_decimal(++str);
	return ((integer_part + decimal_part) * sign);
}
