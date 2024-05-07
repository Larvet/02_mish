/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_proto_5.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:11:01 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 17:12:16 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_PROTO_5_H
# define MISH_PROTO_5_H

/*						*/
/* 50_process			*/
void		t_process_free(t_process *process);
void		t_process_print(t_process *p);

char		*t_process_set_cmd(t_process *process);

/*						*/
/* 52_process_pipe		*/
void		close_reset_fd(int *fd);
t_err_type	t_process_pipe_fds(t_process *process);
t_err_type	t_process_dup_io(t_process *p);

/*						*/
/* 53_process_exec		*/
t_err_type	mish_create_process(t_mish *mish);
void		t_process_fork_child(t_process *p);
t_err_type	mish_fork_parent(t_mish *mish);

#endif
