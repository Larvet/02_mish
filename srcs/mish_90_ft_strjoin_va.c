/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_90_ft_strjoin_va.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:53:34 by locharve          #+#    #+#             */
/*   Updated: 2024/04/25 17:38:45 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static size_t	len_sum(va_list param)
{
	char	*str;
	size_t	result;

	result = 0;
	str = va_arg(param, char *);
	while (str)
	{
		result += ft_strlen(str);
		str = va_arg(param, char *);
	}
	return (result);
}

static char	*ft_strcat_va(char *dst, va_list param)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = va_arg(param, char *);
	while (str)
	{
		j = 0;
		while (str[j])
		{
			dst[i + j] = str[j];
			j++;
		}
		i += j;
		j = 0;
		str = va_arg(param, char *);
	}
	return (dst);
}

char	*ft_strjoin_va(char *str, ...)
{
	va_list	param;
	va_list	p_cpy;
	char	*dst;
	size_t	total_len;

	dst = NULL;
	if (str)
	{
		va_start(param, str);
		va_copy(p_cpy, param);
		total_len = len_sum(p_cpy);
		va_end(p_cpy);
		dst = ft_calloc(total_len + 1, sizeof(char));
		if (dst)
			dst = ft_strcat_va(dst, param);
		va_end(param);
	}
	return (dst);
}
