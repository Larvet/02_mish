/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_91_ft_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:29:31 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 18:32:22 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/*  */
char	*ft_strnrchr(char *str, int n, char c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0 && n > 0)
	{
		i--;
		if (str[i] == c)
			n--;
	}
	return (&str[i]);
}

/* free str and return empty char* "" */
char	*ft_strempty(char *str)
{
	if (str)
		free(str);
	str = malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = 0;
	return (str);
}

/* printf split parts */
void	ft_print_split(char **pathlist)
{
	int	j;

	if (pathlist)
	{
		j = -1;
		while (pathlist[++j])
			ft_printf("%s\n", pathlist[j]);
	}
	else
	{
		ft_printf("(null)\n");
	}
}

void	ft_printf_strtab(char **str, int size, const char *sep)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (i != 0)
			write(1, sep, ft_strlen(sep));
		if (str[i])
			write(1, str[i], ft_strlen(str[i]));
		i++;
	}
}

int	is_alphanum_underscore(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	else
		return (0);
}

size_t	ft_strlen_while(char *str, int f(char))
{
	size_t	i;

	i = 0;
	while (str && str[i] && f(str[i]))
		i++;
	return (i);
}

int		char_count(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

// equivaux a ft_freesplit ?
void	strtab_free(char **strtab)
{
	int	i;

	i = 0;
	if (strtab)
	{
		while (strtab[i])
		{
			free(strtab[i]);
			i++;
		}
		free(strtab);
	}
	return ;
}

