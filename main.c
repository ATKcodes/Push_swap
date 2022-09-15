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
//Parsing TIPS : - Numeri da min int a max int, Lo spazio è il separatore, quindi "50 51" sono due numeri, 
//Una volta che so quanti numeri ho posso iniziare a inserirlo nello A stack
//Continua qui, inserisci e gestisci lo split dell'input, ricorda che quando vai a splittare il count sarà già ad uno, quindi aumenta il count di pars.push di N-1.
void	ft_parsing(int argc, char *argv[], t_push *push)
{
	int	i;
	int	c;

	i = 0;
	c = -1;
	push->pars.count = 0;
	while (++i < argc)
	{
		while (++c < ft_strlen(argv[i]))
		{
			if (c != 0 && argv[i][c] == 32)
				argv[i] = ft_split(argv[i], push); // UPDATA Push->pars.count per ogni spazio dio stronzo
			else if (argv[i][c] == 45)
			{
				while (argv[i][++c] == 32)
					i = i + 1 - 1;
				if (argv[i][c] > 57 || argv[i][c] < 48)
					ft_error("invalid input : no number after minus sign");
			}
			if (argv[i][c] > 57 || argv[i][c] < 48)
				ft_error("invalid input : forbidden char");
		}
		push->pars.count++;
		c = -1;
	}
}
//cosi non puo andare, probabilmente devo inserire l'input man mano che checko l'input, o fare lo split dopo salvandosi le posizioni di dove trova spazi fuori posto.
void	ft_InputAtoi(int argc, char *argv[], t_push *push)
{
	int	i;

	i = -1;
	push->a.array = malloc (sizeof(int) * (push->pars.count + 1));
	while(++i < push->pars.count)
	{
		push->a.array[i] = ft_atoi(argv[])
	}

}

int	main(int argc, char *argv[])
{
	t_push	push;

	ft_parsing(argc, argv, &push);
	ft_InputAtoi(argv, argv, &push);
}
