/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:47:02 by amaso             #+#    #+#             */
/*   Updated: 2022/09/18 11:47:04 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	count_spaces(t_push *push, char *str)
{
	int	i;
	int	d;
	int	c;

	i = -1;
	d = 0;
	while (str[++i])
	{
		c = 0;
		if (str[i] == 45)
		{
			while (str[i + c + 1] == 32)
				c++;
		}
		d = d + c;
	}
	str = cut_spaces(str, d);
	push->split.temp = ft_split(str, push);
}

char	*cut_spaces(char *str, int d)
{
	char	*new;
	int		c;
	int		i;

	new = malloc (ft_strlen(str) - d + 1);
	c = 0;
	i = -1;
	while (str[++i])
	{
		d = 1;
		if (str[i] == 45 && str[i + d] == 32)
		{	
			while (str[i + d] == 32)
				d++;
			new[c] = 45;
			c++;
			i = i + d;
		}
		new[c] = str[i];
		c++;
	}
	new[c] = 0;
	return (new);
}

void	is_copy(t_push *push)
{
	int	i;
	int d;

	i = 0;
	if (push->a.size > 1)
	while (++i < push->a.size)
	{
		d = -1;
		while (++d < i)
		{
			if(push->a.array[d] == push->a.array[i])
				free_copy(push);
		}
	}
}