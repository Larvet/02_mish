/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_52_process_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:17:07 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 20:45:52 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	close_reset_fd(int *fd)
{
	if (*fd > 2)
	{
		close(*fd);
		*fd = -1;
	}
}

t_err_type	t_process_pipe_fds(t_process *process)
{
	int		i;
	t_mish	*mish;

	i = process->index;
	mish = process->mish;
	if (i == 0)
	{
		if (pipe((mish->fds)[0]) == -1)
			mish_error_add(mish, err_pipe, errno, "pipe 0 == -1");
	}
	else
	{
		close_reset_fd((mish->fds)[i - 1] + 0);
		close_reset_fd((mish->fds)[i - 1] + 1);
	}
	if (pipe((mish->fds)[i + 1]) == -1)
		mish_error_add(mish, err_pipe, errno, "pipe index == -1");
	return (mish->error->type);
}

t_err_type	t_process_dup_io(t_process *p)
{
	if (t_process_get_iofd(p, 0) == 0)
	{
		if (p->index > 0)
			if (dup2((p->mish->fds)[p->index][0], STDIN_FILENO) == -1)
				mish_error_add(p->mish, err_dup2, errno, "dup2[i][0]");
	}
	else
	{
		if (dup2(t_process_get_iofd(p, 0), STDIN_FILENO) == -1)
			mish_error_add(p->mish, err_dup2, errno, "dup2 fd_in");
	}
	if (t_process_get_iofd(p, 1) == 1)
	{
		if (p->index < p->mish->nb)
			if (dup2((p->mish->fds)[p->index + 1][1], STDOUT_FILENO) == -1)
				mish_error_add(p->mish, err_dup2, errno, "dup2[i][1]");
	}
	else
	{
		if (dup2(t_process_get_iofd(p, 1), STDOUT_FILENO) == -1)
			mish_error_add(p->mish, err_dup2, errno, "dup2 fd_out");
	}
	return (p->mish->error->type);
}
