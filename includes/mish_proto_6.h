/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_proto_6.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:11:01 by bchene            #+#    #+#             */
/*   Updated: 2024/05/07 14:24:26 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_PROTO_6_H
# define MISH_PROTO_6_H

/*						*/
/* 60_t_file    		*/
t_file	*t_file_new(t_mish *mish, char *path, t_tfile_type type);
void	t_file_free(t_file *tf);
void	t_file_del(t_file *tf);
t_file	*t_process_line_to_file(t_process *p, char *line);
void	t_file_add_back_rec(t_file **lst, t_file *new);
t_file	*t_process_add_file(t_process *p, char *path, t_tfile_type type);
int		t_process_get_iofd(t_process *process, int inorout);

#endif
