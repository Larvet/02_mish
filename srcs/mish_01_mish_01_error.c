/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_01_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:26:04 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 20:45:39 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

// si erreur de malloc dans erreur comment sortir
t_err_type	mish_error_add(t_mish *mish, t_err_type t, int en, char *d)
{
	t_error	*new;

	new = t_error_new(t, en, d);
	if (new)
		t_error_add(&(mish->error), new);
	else
		return (err_malloc);
	return (t);
}
