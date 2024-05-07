/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_53_process_exec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:28:12 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 20:45:53 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_err_type	mish_create_process(t_mish *mish)
{
	int	i;

	mish_p_malloc(mish);
	if (mish->error->err_no)
		mish_fds_malloc(mish);
	if (mish->error->err_no)
	{
		i = -1;
		while(++i < mish->nb && mish->error->err_no)
		{
			//t_process_set(mish, i, (mish->line)[i]);
			//t_process_get_iofiles((mish->p)[i]);
			//t_process_get_cmd((mish->p)[i]);
		}
	}
	return (mish->error->err_no);
}

void	t_process_fork_child(t_process *p)
{
	(void) p;
	/*
	int	i;

	i = p->index;
	while (--i >= 0)
		waitpid(ppx->pid[i], NULL, 0);
	ppx_child_pipe(ppx, p->index);
	if (execve(p->cmd, p->av, ppx->envp) == -1)
		ppx_exit_error(ppx, "execve error", errno);
	exit (EXIT_FAILURE);
	*/
}

t_err_type	mish_fork_parent(t_mish *mish)
{
	int			i;
	t_process	*p;

	// piping mish fds
	i = -1;
	while (++i < mish->nb)
		if (pipe((mish->fds)[i]) == -1)
			mish_error_add(mish, err_pipe, errno, "pipe(fds[i])==-1");
	// forking
	i = -1;
	p = mish->p;
	while (++i < mish->nb)
	{
		mish->pid[i] = fork();
		if (mish->pid[i] == -1)
			mish_error_add(mish, err_fork, errno, "fork() == -1");
		if (mish->pid[i] == 0)
			t_process_fork_child((mish->p) + i);
	}
	mish_fds_close(mish);
	i = mish->nb;
	while (--i >= 0)
		waitpid((mish->pid)[i], NULL, 0);
	return (t_error_exist(mish->error));
}
