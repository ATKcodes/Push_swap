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
	int		count;
	int		pos;
	long	*array;
}			t_pars;

typedef struct s_array{
	int	*array;
	int	size;
}			t_array;

typedef struct s_split{
	char	c;
	char	**temp;
	int		n;
}			t_split;

typedef struct s_push{
	t_array	a;
	t_array	b;
	t_array	c;
	t_pars	pars;
	t_split	split;
}			t_push;

void	ft_fillstack_a(t_push *push);
void	ft_stackgen(int argc, char *argv[], t_push *push);
void	fill_long(t_push *push);
void	ft_parsing(int argc, char *argv[], t_push *push);
void	is_copy(t_push *push);

void	ft_error(char *str);

void	not_int(t_push *push);
void	free_temp(t_push *push);
void	free_copy(t_push *push);

long	ft_atolong(char *str, t_push *push);
int		ft_strlen(char *str);
int		ft_putstr(char *str);

void	count_spaces(t_push *push, char *str);
char	*cut_spaces(char *str, int d);

void	swap(t_push *push, int i);
void	sorting(t_push *push);

char	*dfltcase(char *s, int start, int len);
char	*ft_substr(char *s, int start, int len);
char	**ft_countwords(char *s, t_push *push, int i, int n);
char	**matrixgen(char *s, t_push *push, int i, char **matrix);
char	**ft_split(char *s, t_push *push);

#endif
