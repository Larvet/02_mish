/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_fill_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:43:45 by locharve          #+#    #+#             */
/*   Updated: 2024/05/06 16:05:47 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/**/
/* adapter avec t_file */
/*
void	file_add_back(t_file **lst, t_file *new)
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			file_add_back(&(*lst)->next, new);
	}
}

static char	**strtab_get_io_files(char **split)
{
	char	**io_files;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = -1;
	while (split[++i])
		if (is_in_str("<>", split[i][0]))
			count++;
	io_files = ft_calloc(count + 1, sizeof(char *)); // malloc
	if (io_files)
	{
		i = -1;
		j = 0;
		while (split[++i])
			if (is_in_str("<>", split[i][0]))
			{
				io_files[j] = split[i];
				j++;
			}
	}
	return (io_files);
}

static t_tfile_type	t_file_line_get_type(char *line)
{
	if (!ft_strncmp(line, "<<", 2))
		return (tf_ifile_heredoc);
	else if (!ft_strncmp(line, "<", 1))
		return (tf_ifile_rdonly);
	else if (!ft_strncmp(line, ">>", 2))
		return (tf_ofile_append);
	else if (!ft_strncmp(line, ">", 1))
		return (tf_ofile_creat);
	else
		return (tf_none);
}

static char	*t_file_line_get_path(char *line)
{
	while (line && line[i]
			&& (is_in_str(WHITESPACES, line[i])
			|| is_in_str("<>", line[i])))
		i++;
	return (&line[i]);
}

static void	t_process_t_file_set(t_process *p, char **split)
{
	t_file	*tmp;
	int		i;
	int		count;

	count = ft_splitsize(split);
	i = 0;
	while (i < count)
	{
		if (t_process_line_to_file(p, split[i]))
			return (t_error_exist(mish->error)); /////
		*//*
		tmp = ft_calloc(1, sizeof(t_file));
		if (tmp)
		{
			tmp->line = split[i];
			if (tmp->line[0] == '<')
				file_add_back(&p->infiles, tmp);
			else if (tmp->line[0] == '>')
				file_add_back(&p->outfiles, tmp);
		}
		*//*
		i++;
	}
}

static void	t_process_fill_av(t_process *p, char **split)
{
	char	**av;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = -1;
	while (split[++i])
		if (!is_in_str("<>", split[i][0]))
			count++;
	av = ft_calloc(count + 1, sizeof(char *)); // malloc
	if (av)
	{
		i = -1;
		j = 0;
		while (split[++i])
			if (!is_in_str("<>", split[i][0]))
			{
				av[j] = split[i];
				j++;
			}
		p->av = av;
		p->ac = count;
	}
}

static t_err_type	t_process_fill(t_process *p)
{
	char	**split;
	char	**io_files;
	int		ret;

	ret = 0;
	split = t_process_split(p, WHITESPACES);
	if (split)
	{
		mish_substitute_vars(p->mish, split);
		mish_remove_quotes(p->mish, split);
		io_files = strtab_get_io_files(split);
		///////////////////
		if (io_files)
		{
			t_process_fill_io_files(p, io_files);
			free(io_files);
			t_process_fill_av(p, split);
		}
		else
			ret = err_malloc;
		free(split);
	}
	return (ret);
}

static void	t_process_t_file_set(t_process *p, char **split)
{
	char	**io_files;
	int	i;

	io_files = strtab_get_strs_if()
}

int	mish_fill_processes(t_mish *mish)
{
	char	**split;
	int		i;
	int		tmp;

	split = t_process_split(p, WHITESPACES);
	if (!split)
		return (mish_error_add(mish, err_malloc, errno, "mish_fill_processes");)
	i = 0;
	while (i < mish->nb)
	{
		// t_process_t_file_set(&mish->p[i], split);
		tmp = t_process_fill(mish, &mish->p[i]);
		if (tmp)
		{
			mish_error_add(mish, tmp, errno, "mish_fill_processes"); /////
			return (tmp);
		}
		i++;
	}
	return (0);
}
*/
