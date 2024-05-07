/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_05_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 20:45:41 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_err_type	mish_p_malloc(t_mish *mish)
{
	// gerer erreur vide
	if (mish == NULL && mish->nb < 1)
		return (t_error_exist(mish->error));
	mish->p = ft_calloc(mish->nb, sizeof(t_process));
	if (mish->p == NULL)
		mish_error_add(mish, err_malloc, errno, "mish->p == NULL");
	return (t_error_exist(mish->error));
}

void	mish_p_free(t_mish *mish)
{
	int	i;

	if (mish && mish->nb > 0 && mish->p)
	{
		i = -1;
		while(++i < mish->nb)
			t_process_free((mish->p) + i);
		free(mish->p);
	}
}

t_err_type	mish_p_init(t_mish *mish, int index, char *line)
{
	t_process	*process;

	process = (mish->p) + index;
	if (process == NULL)
	{
		mish_error_add(mish, err_other, errno, "t_process_new == NULL");
		return (t_error_exist(mish->error));
	}
	process->mish = mish;
	process->index = index;
	process->line = line;
	process->ac = 0;
	process->av = NULL;
	process->cmd = NULL;
	process->infiles = NULL;
	process->outfiles = NULL;
	return (t_error_exist(mish->error));
}

void	mish_p_print(t_mish *mish)
{
	int	i;

	if (mish && mish->nb > 0 && mish->p)
	{
		i = -1;
		while(++i < mish->nb)
			t_process_print((mish->p) + i);
	}
	else
		printf("(null)\n");
}
