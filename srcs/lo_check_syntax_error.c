/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:39:36 by locharve          #+#    #+#             */
/*   Updated: 2024/04/26 20:45:07 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static int	is_special_token(char *line, int i)
{
	char	r;

	if (is_in_str("<>", line[i]))
	{
		r = line[i];
		if (line[i + 1] == r)
			return (2);
		else
			return (1);
	}
	else if (line[i] == '|')
		return (1);
	else
		return (0);
}

static char	*next_char_addr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_in_str(WHITESPACES, str[i]))
		i++;
	if (str[i])
		return (&str[i]);
	else
		return (NULL);
}

static int	dup_err_str(t_mish *mish, char *src, int n, t_err_type err)
{
	char	*dst;
	int		result;

	dst = ft_strndup(src, n);
	result = mish_error_add(mish, err, errno, dst);
	free(dst);
	return (result);
}

int	mish_check_syntax_error(t_mish *mish)
{
	int		i;
	int		tmp[2];

	i = 0;
	while (mish->line && mish->line[i])
	{
		tmp[0] = is_special_token(mish->line, i);
		if (tmp[0])
		{
			i += tmp[0];
			tmp[1] = is_special_token(mish->line, i);
			if (tmp[1] && !is_between_quotes(mish, mish->line, i)
					&& (mish->line[i - tmp[0]] != '|' || mish->line[i] == '|')) ////
				return (dup_err_str(mish, &mish->line[i],
						tmp[1], err_token_unexpected));
			else if (!next_char_addr(&mish->line[i]))
				return (dup_err_str(mish, "newline", 7, err_token_unexpected));
			else
				i += tmp[1];
			tmp[0] = 0;
		}
		else
			i++;
	}
	return (0);
}

int	mish_check_open_quotes(t_mish *mish)
{
	int		i;
	char	q;

	i = 0;
	q = 0;
	while (mish->line && mish->line[i])
	{
		if (mish->line[i] == '\'' || mish->line[i] == '\"')
		{
			q = mish->line[i];
			i++;
			while (mish->line[i] && mish->line[i] != q)
				i++;
			if (!mish->line[i])
			{
				if (q == '\'')
					return (dup_err_str(mish, "", 0, err_quote_open));
				else if (q == '\"')
					return (dup_err_str(mish, "", 0, err_dquote_open));
			}
		}
		i++;
	}
	return (0);
}
