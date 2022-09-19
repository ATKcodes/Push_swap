/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:13:47 by amaso             #+#    #+#             */
/*   Updated: 2022/09/19 10:13:52 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting(t_push *push)
{
	int	i;

	push->c.array = malloc (sizeof(int) * push->a.size);
	push->c.array[push->a.size] = 0;
	i = -1;
	while (++i < push->a.size)
	{
		inserting(push, i);
	}
}

void	inserting(t_push *push, int i)
{
	int	d;

	d = -1;
	while (++d < i)
	{
		if (push->a.size[i] < )
	}
}

void	swap(t_push *push, int i, int d)
{

}
