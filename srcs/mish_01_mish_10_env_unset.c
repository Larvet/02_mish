/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_10_env_unset.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/04/27 17:42:21 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	mish_env_unset_init(t_mish *mish, char **envp)
{
	int i;

	i = 0;
	while (envp && envp[i])
	{
		t_env_add(&(mish->env), envp[i]);
		i++;
	}
	t_env_add(&(mish->unset), "?=0");
	t_env_add(&(mish->unset), "0=minishell");
}

void	mish_env_unset_free(t_mish *mish)
{
	t_env_free(mish->env);
	t_env_free(mish->unset);
}

// a tester
int		mish_env_unset_export(t_mish *mish, char* var, char *value)
{
	if (mish_unset_get(mish, var))
	{
		mish_unset_remove(mish, var);
	}
	if (mish_env_get(mish, var))
	{
		mish_env_set(mish, var, value);
		return (2);
	}
	else
	{
		if(mish_env_add(mish, var, value))
			return (1);
	}
	return (0);
}

// a tester
int		mish_env_unset_unset(t_mish *mish, char* var)
{
	if (mish_unset_get(mish, var))
	{
		mish_unset_remove(mish, var);
		return (2);
	}
	if (mish_env_get(mish, var))
	{
		mish_env_remove(mish, var);
		return (1);
	}
	return (0);
}

void	mish_env_unset_print(t_mish *mish)
{
	t_env	*tmp;

	printf("///   env :\n");
	tmp = mish->env;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	printf("///   unset :\n");
	tmp = mish->unset;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}
