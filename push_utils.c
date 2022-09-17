/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:53:55 by amaso             #+#    #+#             */
/*   Updated: 2022/09/15 15:53:59 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atolong(char *str, t_push *push)
{
	long	c;
	long	i;
	long	r;

	r = 0;
	c = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		c = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && '0' <= str[i])
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (r * c < -2147483648 || r * c > 2147483647)
		not_int(push);
	return (r * c);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	c;

	c = 0;
	if (str)
	{
		while (str[c] != '\0')
		{
			write(1, &str[c], 1);
			c++;
		}
		return (c);
	}
	write (1, "(null)", 6);
	return (6);
}