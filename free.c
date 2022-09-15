/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:44:08 by amaso             #+#    #+#             */
/*   Updated: 2022/09/15 21:44:11 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_temp(t_push *push)
{
	int	i;

	i = -1;
	if (push->split.temp)
	{
		while (push->split.temp[++i])
			free(push->split.temp[i]);
		free (push->split.temp);
	}
}

void	free_stacks(t_push *push)
{
	int	i;

	i = -1;
	while (push->a.array[++i])
		free(push->a.array[i]);
	if (push->a.array)
		free(push->a.array);
	i = -1;
	while (push->b.array[++i])
		free(push->b.array[i]);
	if (push->b.array)
		free(push->b.array);
	i = -1;
	while (push->pars.array[++i])
		free(push->pars.array[i]);
	if (push->pars.array)
		free(push->pars.array);
	ft_error("invalid input : int_max or int_min exceeded");
}
