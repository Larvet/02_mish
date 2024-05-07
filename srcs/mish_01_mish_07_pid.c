/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_07_pid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 20:12:38 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	mish_pid_print(t_mish *mish)
{
	int	i;

	if (mish && mish->pid)
	{
		printf("{");
		i = -1;
		while (++i < mish->nb)
		{
			printf("%i ", (mish->pid)[i]);
			if (i == mish->nb - 1)
				printf("}\n");
			else
				printf(",");
		}
	}
	else
		printf("(null)\n");
}
