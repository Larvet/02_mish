/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_handle_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:38 by locharve          #+#    #+#             */
/*   Updated: 2024/04/25 17:11:53 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	handle_quotes(char *str, int i, char q)
{
	int	j;

	j = 1;
	while (str[i + j] && str[i + j] != q)
		j++;
	return (j + 1);
}

int	handle_redirections(char *str, int i, char r)
{
	int	j;

	j = 1;
	if (str[i + j] == r)
		j++;
	while (is_in_str(WHITESPACES, str[i + j]))
		j++;
	while (str[i + j] && !is_in_str(WHITESPACES, str[i + j])
			&& !is_in_str(SPECIAL_SEP, str[i + j]))
		j++;
	return (j);
}

int	handle_specials(char *str, int i)
{
	char	c;

	c = str[i];
	if (is_in_str("\'\"", c))
		return (handle_quotes(str, i, c));
	else if (is_in_str("<>", c))
		return (handle_redirections(str, i, c));
	else if (c == '|')
		return (1);
	else
		return (-1);
}

int	handle_word(char *str, char *sep, int i)
{
	int	j;

	j = 0;
	if (is_in_str(SPECIAL_SEP, str[i]) || is_in_str("\'\"", str[i]))
		j = handle_specials(str, i);
	else
		while (str[i + j] && !is_in_str(sep, str[i + j])
				&& !is_in_str(SPECIAL_SEP, str[i + j]))
			j++;
	return (j);
}
