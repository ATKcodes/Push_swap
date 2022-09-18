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

	i = 0;
	if (push->split.temp)
	{
		while (push->split.temp[i++])
			free(push->split.temp[i]);
		free (push->split.temp);
	}
}

void	not_int(t_push *push)
{
	if (push->a.array)
		free(push->a.array);
	if (push->pars.array)
		free(push->pars.array);
	ft_error("invalid input : int_max or int_min exceeded\n");
}

void	free_copy(t_push *push)
{
	if (push->a.array)
		free(push->a.array);
	ft_error("invalid input : repeating numbers.");
}