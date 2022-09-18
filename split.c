/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:22:42 by amaso             #+#    #+#             */
/*   Updated: 2022/09/15 11:22:45 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_pars{
// 	int	count;
// }			t_pars;

// typedef struct s_array{
// 	int	*array;
// 	int	size;
// }			t_array;

// typedef struct s_split{
// 	char	c;
// 	int		n;
// }			t_split;

// typedef struct s_push{
// 	t_array	a;
// 	t_array	b;
// 	t_pars	pars;
// 	t_split	split;
// }			t_push;

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		;
// 	return (i);
// }

char	*dfltcase(char *s, int start, int len)
{
	char	*sub;
	int		i;
	int		c;

	i = 0;
	c = (ft_strlen(s) - start);
	if (ft_strlen(s) - start > len)
		sub = (char *) malloc((sizeof(char) * (len + 1)));
	else
		sub = (char *) malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (!sub)
		return (0);
	while (i < len && i < c)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) > start)
		return (dfltcase(s, start, len));
	else
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == 0)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
}

char	**ft_countwords(char *s, t_push *push, int i, int n)
{
	char	**matrix;

	matrix = NULL;
	while (i < ft_strlen(s))
	{
		if (s[i] != push->split.c)
		{
			while (s[i] != push->split.c && i < ft_strlen(s))
				i++;
			n++;
			i--;
		}
		i++;
	}
	matrix = (char **) malloc (sizeof(char *) * (n + 1));
	if (!matrix)
		return (0);
	push->split.n = n;
	matrix[n] = 0;
	return (matrix);
}

char	**matrixgen(char *s, t_push *push, int i, char **matrix)
{
	int		n;
	int		len;

	len = 0;
	n = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != push->split.c)
		{
			while (s[i + len] != push->split.c && i + len < ft_strlen(s))
				len++;
			matrix[n] = ft_substr(s, i, len);
			n++;
			i = i + len;
			len = 0;
			i--;
		}
		i++;
	}
	return (matrix);
}

char	**ft_split(char *s, t_push *push)
{
	char	**matrix;
	int		i;
	int		n;

	push->split.c = ' ';
	if (!s)
		return (0);
	matrix = 0;
	n = 0;
	i = 0;
	matrix = ft_countwords(s, push, i, n);
	if (!matrix)
		return (0);
	return (matrixgen(s, push, i, matrix));
}

// int	main(void)
// {
// 	char	*str;
// 	char	**matrix;
// 	int		i;
// 	int		d;
// 	t_push	push;

// 	i = -1;
// 	d = 0;
// 	push.pars.count = 0;
// 	str = "-1 2    3     4";
// 	matrix = ft_split(str, &push);
// 	while (++i < 4)
// 		printf("%s\n", matrix[i]);
// 	printf("%d\n", push.pars.count);
// 	return (0);
// }
