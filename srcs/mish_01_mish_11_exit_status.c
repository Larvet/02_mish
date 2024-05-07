/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_11_exit_status.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/04/27 14:28:57 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	mish_exit_status_set(t_mish *mish, int value)
{
	char *str;

	str = ft_itoa(value);
	mish_unset_set(mish, "?", str);
	free (str);
}

int		mish_exit_status_get(t_mish *mish)
{
	char	*s;
	int 	ret;

	s = mish_unset_get(mish, "?");
	if (s == NULL || ft_strlen(s) == 0)
	{
		mish_exit_status_set(mish, 0);
		return (0);
	}
	ret = ft_atoi(s);
	return (ret);
}
