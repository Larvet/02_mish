/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_60_t_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/07 14:25:38 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

// ajouter des argument pour le constructeur
// mieux definir la structure
// a suivre

/*
char **unxp_token;
unxp_token = {"||", "\\", "<>", "<&", ";", "&",}
<> < > <<< <<> 
echo <      > file
*/

t_file	*t_file_new(t_mish *mish, char *path, t_tfile_type type)
{
	t_file	*tf;

	tf = malloc(sizeof(t_file));
	if (tf == NULL)
	{
		mish_error_add(mish, err_malloc, errno, "t_file_new");
		return (NULL);
	}
	tf->fd = -1;
	tf->path = ft_strdup(path);
	tf->type = type;
	tf->next = NULL;
	return (tf);
}
void	t_file_free(t_file *tf)
{
	if (tf)
	{
		if (tf->next)
			t_file_free(tf->next);
		t_file_del(tf);
	}
}

void	t_file_del(t_file	*tf)
{
	if (tf)
	{
		if(tf->path)
			free(tf->path);
		free(tf);
	}
}

t_file	*t_process_line_to_file(t_process *p, char *line)
{
	t_file			*file;
	char			*path;
	t_tfile_type	file_type;
	
	// a faire
	//t_file	*t_file_new(t_mish *mish, char *path, t_tfile_type type)
	
	path = t_file_line_get_path(line);
	file_type = t_file_line_get_type(line);
	//file = t_file_new(p->mish, path, file_type); ///
	file = t_process_add_file(p, path, file_type);
	return (file);
}

void	t_file_add_back_rec(t_file **lst, t_file *new) ////////
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			t_file_add_back_rec(&(*lst)->next, new);
	}
}

t_file	*t_process_add_file(t_process *p, char *path, t_tfile_type type)
{
	t_file	*new;
	t_file	*current;

	printf("path = %s\tftype = %d\n", path, type); /////
	if (type == tf_ifile_rdonly || type == tf_ifile_heredoc)
		current = p->infiles;
	else if (type != tf_none)
		current = p->outfiles;
	else
		return (NULL);
	new = t_file_new(p->mish, path, type);
/*	if (new)
	{
		if (type == tf_ifile_rdonly || type == tf_ifile_heredoc)
			t_file_add_back_rec(&(*p)->infiles, new);
		else if (type != tf_none)
			t_file_add_back_rec(&(*p)->outfiles, new);
		else
		{
			free(new->path);
			free(new);
			return (NULL);
		}
	}
*/	while (current)
		current = current->next;
	current = new;
	return (new);
}

/* inorout : ==0 IN - !=0 OUT */
int	t_process_get_iofd(t_process *process, int inorout)
{
	t_file	*tf;

	if (inorout == 0)
	{
		if (process == NULL || process->infiles == NULL)
			return (0);
		tf = process->infiles;
	}
	else
	{
		if (process == NULL || process->outfiles == NULL)
			return (1);
		tf = process->outfiles;
	}
	while (tf->next)
		tf = tf->next;
	return(tf->fd);
}
