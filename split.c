#include "push_swap.h"

char	*dfltcase(char *s, t_push push, int start, int len)
{
	char	*sub;
	int		i;
	int`	c;

	i = 0;
	c = (ft_strlen(s) -  start);
	if (ft_strlen(s) - start > len)
		sub = (char *) malloc((sizeof(char) * (len + 1)));
	else
		sub = (char *) malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && i < c)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char *s, t_push push, int start, int len)
{
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) > start)
		return (dfltcase(s, push, start, len));
	else
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
}


char	**ft_countwords(char *s, t_push push, int i, int n)
{
	char	**matrix;

	matrix = NULL;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] != push->split.c && i < ft_strlen(s))
				i++;
			n++;
			i--;
		}
		i++;
	}
	matrix = (char **) malloc (sizeof(char *) * (n + 1));
	if (matrix == NULL)
		return (NULL);
	matrix[n] = NULL;
	return (matrix);
}

char	**matrixgen(char *s, t_push push, int i, char **matrix)
{
	int		n;
	int		len;

	len = 0;
	n = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i + len] != push->split.c && i + len < ft_strlen(s))
				len++;
			matrix[n] = ft_substr(s, push, i, len);
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
		return (NULL);
	matrix = NULL;
	n = 0;
	i = 0;
	matrix = ft_countwords(s, push, i, n);
	if (matrix == NULL)
		return (NULL);
	return (matrixgen(s, push, i, matrix));
}
