/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_50_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:49:39 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 20:45:46 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	t_process_free(t_process *process)
{
	if (process == NULL)
		return ;
	ft_freesplit(process->av);
	if (process->cmd)
		free(process->cmd);
	t_file_free(process->infiles);
	t_file_free(process->outfiles);
}

char	*t_process_set_cmd(t_process *process)
{
	int		i;
	char	*str;
	char	**path;

	path = (process->mish)->pathlist;
	i = 0;
	while (path && path[i])
	{
		str = ft_strjoin(path[i], (process->av)[0]);
		if (access(str, X_OK) == 0)
			return (str);
//		command not found
//		else
//			mish_error_add(process->mish, err_access, errno, "accesspath");
		free(str);
		i++;
	}
	str = ft_strdup((process->av)[0]);
	return (str);
}

void	t_process_print(t_process *p)
{
	if (p == NULL)
	{
		printf("(null)\n");
		return ;
	}
	printf("|||| T_PROCESS\n");
	printf("index = %d\n", p->index);
	printf("line = %s\n", p->line);
	printf("ac = %d\n", p->ac);
	printf("av = ");
	ft_printf_strtab(p->av, p->ac, "\\-\\");
	printf("\n");
	printf("cmd = %s\n", p->cmd);
	printf("|||| T_PROCESS\n");
}
