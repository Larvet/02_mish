/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:12:03 by bchene            #+#    #+#             */
/*   Updated: 2024/04/25 18:09:45 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_STRUCTS_H
# define MISH_STRUCTS_H

typedef struct s_mish		t_mish;
typedef struct s_process	t_process;
typedef struct s_file		t_file;
typedef struct s_error		t_error;
typedef struct s_env		t_env;

/*
env -i bash
recuperer les varialble envirenement au denbut et emuler les unset et set
*/

typedef struct s_mish
{
	t_error		*error;
	char		*prompt;
	char		*line;
	char		**splitline;
	int			nb;
	t_process	*p;
	int			**fds;
	int			*pid;
	t_env		*env;
	t_env		*unset;
	char		**pathlist;
}	t_mish;

typedef struct s_process
{
	t_mish		*mish;
	int			index;
	char		*line;
	int			ac;
	char		**av;
	char		*cmd;
	t_file		*infiles;
	t_file		*outfiles;
}	t_process;

typedef struct s_file
{
	int				fd;
	char			*line;
	char			*path;
	t_tfile_type	type;
	t_file			*next;
}	t_file;

typedef struct s_error
{
	t_err_type	type;
	int			err_no;
	char		*data;
	t_error		*next;
}	t_error;

typedef struct s_env
{
	char	*str;
	t_env	*next;
}	t_env;

#endif
