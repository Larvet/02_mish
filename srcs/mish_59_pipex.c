/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_59_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:13:51 by bchene            #+#    #+#             */
/*   Updated: 2024/04/25 17:38:50 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/*
int	main(int ac, char **av, char **envp)
{
	static t_ppx	ppx;

	ppx.envp = envp;
	if (ac != 5)
	{
		write(2, "Error : Invalid number of arguments\n", 37);
		return (1);
	}
	ppx_parse_path(&ppx, envp);
	ppx_parse_av(&ppx, ac, av);
	ppx_process_root(&ppx);
	ppx_free(&ppx);
	close(0);
	close(1);
	close(2);
	exit(EXIT_SUCCESS);
}

void	ppx_process_printf(t_ppx_process *p)
{
	ft_printf("///// PPX_PROC\n");
	ft_printf("p.index = %d\n", p->index);
	ft_printf("p.ac = %d\n", p->ac);
	ft_printf("p.cmd = %s\n", p->cmd);
	ft_printf("p.av : \n");
	ft_print_split(p->av);
	ft_printf("///// PPX_PROC\n\n");
}

void	ppx_printf(t_ppx *ppx)
{
	int	i;

	ft_printf("///// PPX PRINTF\n");
	ft_printf("ppx.nb = %d\n", ppx->nb);
	ft_printf("ppx.fd_infile = %d\n", ppx->fd_infile);
	ft_printf("ppx.fd_outfile = %d\n", ppx->fd_outfile);
	ft_printf("ppx.pathlist = \n");
	ft_print_split(ppx->pathlist);
	ft_printf("///// PPX P PRINTF\n");
	i = -1;
	while (++i < ppx->nb)
		ppx_process_printf((ppx->p) + i);
	ft_printf("///// PPX PRINTF\n");
}

void	ppx_exit_error(t_ppx *ppx, char *message, int error)
{
	if (message)
		perror(message);
	else
		perror("");
	(void) error;
	ppx_free(ppx);
	exit(EXIT_FAILURE);
}

void	ppxp_free(t_ppx *ppx)
{
	int	i;

	i = -1;
	while ((++i < ppx->nb) && ((ppx->p) + i))
	{
		if (((ppx->p) + i)->av)
			ft_freesplit(((ppx->p) + i)->av);
		if (((ppx->p) + i)->cmd)
			free(((ppx->p) + i)->cmd);
	}
	if (ppx->p)
		free(ppx->p);
}

void	ppx_free(t_ppx *ppx)
{
	int				i;

	if (ppx->pathlist)
		ft_freesplit(ppx->pathlist);
	if (ppx->fd_infile)
		ppx_closefd(&(ppx->fd_infile));
	if (ppx->fd_outfile)
		ppx_closefd(&(ppx->fd_outfile));
	if (ppx->fds)
		ppx_closeallfds(ppx);
	i = -1;
	while (++i < ppx->nb)
		if (ppx->fds && (ppx->fds)[i])
			free((ppx->fds)[i]);
	if (ppx->fds)
		free(ppx->fds);
	if (ppx->pid)
		free(ppx->pid);
	if (ppx->p)
		ppxp_free(ppx);
}

*/
