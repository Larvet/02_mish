/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_separate_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:12:20 by bchene            #+#    #+#             */
/*   Updated: 2024/05/06 17:14:36 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mish.h"

void	process_init_line(t_process **p, char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		(*p + i)->line = split[i];
		i++;
	}
	return ;
}

void	mish_init_p_mish(t_mish *mish)
{
	int	i;

	i = 0;
	while (i < mish->nb)
	{
		mish->p[i].mish = mish;
		i++;
	}
	return ;
}

/**/
/* a adapter avec t_process */
/**/

int	mish_separate_processes(t_mish *mish)
{
	int	i;

	mish->nb = char_count(mish->line, '|') + 1;
	printf("nb = %d\n", mish->nb); /////////
	if (!mish_p_malloc(mish))
	{
		mish->splitline = ft_split(mish->line, '|'); // malloc
		if (mish->splitline)
		{
			i = 0;
			while (i < mish->nb)
			{
				printf("splitline %d : %s\n", i, mish->splitline[i]); /////
				if (mish_p_init(mish, i, mish->splitline[i]))
					break ; ////////
				i++;
			}
			//process_init_line(&mish->p, mish->splitline, mish->nb);
			//mish_init_p_mish(mish);
		}
	}
	return (t_error_exist(mish->error)); // erreur de malloc ?
}
