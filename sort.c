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

	push->c.size = push->a.size;
	push->c.array = malloc (sizeof(int) * push->a.size);
	i = -1;
	while (++i < push->a.size)
		push->c.array[i] = push->a.array[i];
	i = -1;
	while (++i < push->a.size)
	{
		if (i + 1 < push->a.size && push->c.array[i] > push->c.array[i + 1])
			swap(push, i);
	}
}

void	swap(t_push *push, int i)
{
	int	temp;

	temp = push->c.array[i];
	push->c.array[i] = push->c.array[i + 1];
	push->c.array[i + 1] = temp;
}
