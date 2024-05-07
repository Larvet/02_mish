/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_proto_9.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:11:01 by bchene            #+#    #+#             */
/*   Updated: 2024/04/25 19:32:28 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_PROTO_9_H
# define MISH_PROTO_9_H

/* 90_ft_strjoin_va */
char	*ft_strjoin_va(char *str, ...);

/* 91_ft utils */
/* ft a trier / renommer? / transfert vers libft? */
/* ajouter entete pour description */
char	*ft_strnrchr(char *str, int n, char c);
char	*ft_strempty(char *str);
void	ft_print_split(char **pathlist);
void	ft_printf_strtab(char **str, int size, const char *sep);
int		is_alphanum_underscore(char c);
size_t	ft_strlen_while(char *str, int f(char));
int		char_count(char *str, char c);
void	strtab_free(char **strtab);

#endif
