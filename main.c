/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:35:51 by amaso             #+#    #+#             */
/*   Updated: 2022/07/04 14:49:40 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_parsing(int argc, char *argv[], t_push *push)
{
	int	i;
	int	c;

	i = 0;
	while (++i < argc)
	{
		c = -1;
		push->split.n = 1;
		while (++c < ft_strlen(argv[i]))
		{
			if (c != 0 && argv[i][c] == 32)
				count_spaces(push, argv[i]);
			else if (argv[i][c] == 45)
			{
				while (argv[i][++c] == 32)
					;
				if (argv[i][c] > 57 || argv[i][c] < 48)
					ft_error("invalid input : no number after minus sign");
			}
			if ((argv[i][c] > 57 || argv[i][c] < 48) && argv[i][c] != 32)
				ft_error("invalid input : forbidden char");
		}
		push->pars.count += push->split.n;
	}
}

//Filling the stack in case there are two or more numbers in a single argv
void	fill_long(t_push *push)
{
	int	i;

	i = -1;
	while (push->split.temp[++i])
		push->pars.array[push->pars.pos + i]
			= ft_atolong(push->split.temp[i], push);
	push->pars.pos = (push->pars.pos + i);
	free_temp(push);
}

//Creating the stack A and creating and filling the temporary long stack.
void	ft_stackgen(int argc, char *argv[], t_push *push)
{
	int	c;
	int	i;

	i = 0;
	push->a.array = malloc (sizeof(int) * push->pars.count);
	push->pars.array = malloc (sizeof(long) * push->pars.count);
	push->pars.pos = 0;
	while (++i < argc)
	{
		c = -1;
		while (argv[i][++c])
		{
			if (c != 0 && argv[i][c] == 32)
			{
				count_spaces(push, argv[i]);
				fill_long(push);
				while (argv[i][c])
					c++;
			}
			else
			{
				push->pars.array[push->pars.pos] = ft_atolong(argv[i], push);
			}
		push->pars.pos++;
		}
	}
	ft_fillstack_a(push);
}

void	ft_fillstack_a(t_push *push)
{
	int	i;

	i = -1;
	while (++i < push->pars.count)
		push->a.array[i] = (int)push->pars.array[i];
	push->a.size = push->pars.count;
	free(push->pars.array);
}

int	main(int argc, char *argv[])
{
	t_push	push;

	push.split.temp = NULL;
	push.pars.count = 0;
	ft_parsing(argc, argv, &push);
	ft_stackgen(argc, argv, &push);
	is_copy(&push);
	sorting(&push);
	for (int c = 0; c < push.c.size; c++)
		printf("%d\n", push.c.array[c]);
}
