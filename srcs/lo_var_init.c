/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_var_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:34:19 by locharve          #+#    #+#             */
/*   Updated: 2024/05/08 16:45:11 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	is_valid_var_name(char *str)
{
	int	i;

	if (str && !ft_isdigit(str[0]))
	{
		i = 1;
		while (str[i] && is_alphanum_underscore(str[i]))
			i++;
		return (i);
	}
	return (0);
}

int	is_var_init(char *str)
{
	int	i;

	i = is_valid_var_name(str);
	if (i && str[i] == '=')
		return (i);
	else
		return (0);
}

t_err_type	t_process_var_init_unset(t_process *p)
{
	// check AVANT si la variable existe deja ; si oui remplacer la valeur
	//		-> dans une autre fonction : mish_env_change_value

	// pas entre d/quotes
	
	// apres export : mish_env_set
	// sinon (commande seule) : mish_unset_set

	// tout ca APRES la substitution, APRES t_process_split

	// si unset:	si la variable a ete export (donc est dans env),
	//					supprimer la variable et sa valeur
	//				sinon rien (?)

	char	*var;
	char	*value;
	int		eq_index;

	eq_index = is_var_init(p->av[0]);
	if (eq_index)
	{
		var = ft_strndup(p->av[0], eq_index);
		if (var)
		{
			value = ft_strdup(&p->av[0][eq_index]);
			if (value)
			{
				mish_unset_set(mish, var, value);
				free(value);
			}
			free(var);
		}
	}
	return (t_error_exist(mish->error));
}
