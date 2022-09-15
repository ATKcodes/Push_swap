/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:37:32 by amaso             #+#    #+#             */
/*   Updated: 2022/07/04 14:47:24 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_pars{
	int	count;
}			t_pars;

typedef struct s_array{
	int	*array;
	int	size;
}			t_array;

typedef struct s_split{
	char	c;
}			t_split;

typedef struct s_push{
	t_array	a;
	t_array	b;
	t_pars	pars;
	t_split	split;
}			t_push;

void	ft_error(char *str);

int		ft_strlen(char *str);

char	*dfltcase(const *s, int start, int len);
char	*ft_substr(char *s, int start, int len);
char	**ft_countwords(char *s, char c, int i, int n);
char	**matrixgen(char *s, char c, int i, char **matrix);
char	**ft_split(char *s, t_push *push);

#endif
