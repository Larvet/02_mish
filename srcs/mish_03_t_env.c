/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_03_t_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:07:17 by bchene            #+#    #+#             */
/*   Updated: 2024/04/26 21:51:11 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_env	*t_env_new(char *str)
{
	t_env   *new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_env	*t_env_add(t_env **env, char *str)
{
	t_env   *new;
	t_env	*cur;

	new = t_env_new(str);
	if (new == NULL)
		return (NULL);
	if (*env == NULL)
	{
		*env = new;
		return (new);
	}
	cur = *env;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (new);
}

void	t_env_del(t_env *env)
{
	if (env->str)
		free (env->str);
	free (env);
}

void	t_env_free(t_env *env)
{
	if (env)
	{
		if (env->next)
			t_env_free(env->next);
		t_env_del(env);
	}
}

int	t_env_remove(t_env **env, t_env *to_remove)
{
	t_env	*cur;

	if (env == NULL || to_remove == NULL)
		return (-1);
	cur = *env;
	if (cur == to_remove)
	{
		*env = cur->next;
		t_env_del(to_remove);
		return (0);
	}
	while (cur->next && (cur->next != to_remove))
		cur = cur->next;
	if (cur->next == to_remove)
	{
		cur->next = to_remove->next;
		t_env_del(to_remove);
		return (0);
	}
	return (1);
}

t_env	*t_env_getvar(t_env *tenv, char *var)
{
	t_env	*env;

	env = tenv;
	if (env == NULL || var == NULL)
		return (NULL);
	while (env)
	{
		if (ft_strncmp(env->str, var, ft_strlen(var)) == 0 && 
		ft_strncmp((env->str) + ft_strlen(var), "=", 1) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*t_env_getdata(t_env *env, char *var)
{
	t_env	*varenv;

	if (env == NULL || var == NULL)
		return (NULL);
	varenv = t_env_getvar(env, var);
	if (varenv)
		return (varenv->str + ft_strlen(var) + 1);
	return (NULL);
}

int	t_env_setstr(t_env *env, char *var, char *value)
{
	t_env	*varenv;
	char	*str;

	if (env == NULL || var == NULL || value == NULL)
		return (-1);
	str = ft_strempty(NULL);
	str = ft_strjointo(str, var);
	str = ft_strjointo(str, "=");
	str = ft_strjointo(str, value);
	varenv = t_env_getvar(env, var);
	if (varenv && varenv->str )
	{
		free(varenv->str);
		varenv->str = strdup(str);
	}
	else
		t_env_add(&env, str);
	free(str);
	return (0);
}

void	t_env_print(t_env *tenv)
{
	while (tenv)
	{
		printf("%s\n", tenv->str);
		tenv = tenv->next;
	}
}