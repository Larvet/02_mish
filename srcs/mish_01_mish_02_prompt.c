/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_02_prompt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/04/27 16:55:12 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	mish_prompt(t_mish *mish)
{
	if (mish->prompt == NULL)
	{
		mish_prompt_start(mish);
		mish->prompt = ft_strempty(mish->prompt);
		mish_prompt(mish);
		return ;
	}
	else
	{
		if (mish->line)
		{
			add_history(mish->line);
			free(mish->line);
		}
		free(mish->prompt);
		mish_prompt_set(mish);
	}
	if (mish->prompt == NULL)
		mish_error_add(mish, err_malloc, errno, "mish->prompt is NULL");
	else
	{
		mish->line = readline(mish->prompt);
	}
}

void	mish_prompt_set(t_mish *mish)
{
	char	*str;

	str = mish_env_get(mish, "SESSION_MANAGER");
	str = ft_strchr(str, '/');
	str = ft_strndup(str + 1, ft_strchr(str, '.') - (str + 1));
	if (!str)
		return ;
	mish->prompt = ft_strjoin_va("", 
	"\001\e[0;32m\002", mish_env_get(mish, "LOGNAME"), 
	"\001\e[2;32m\002", " @", 
	str, " ", 
	"\001\e[0;32m\002", ft_strnrchr(mish_env_get(mish, "PWD"), 1, '/') + 1, "/", 
	"\001\e[0m\002 $>", 
	NULL);
	free(str);
}

/*
static void	mish_setprompt(t_mish *mish)
{
	mish->prompt = ft_strjoin(mish->prompt, "\033[0;31m:>user");
}
*/


/* https://patorjk.com/software/taag/#p=display&f=Graffiti&t=minishell */
void	mish_prompt_start(t_mish *mish)
{
	char *str;

	str = ft_strjoin_va("", \
	"\001\e[0;32m\002        .__       .__       .__           .__  .__   \n",
	"\001\e[0;32m\002  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  \n",
	"\001\e[0;32m\002 /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |  \n",
	"\001\e[0;32m\002|  Y Y  \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__\n",
	"\001\e[0;32m\002|__|_|  /__|___|  /__/____  >___|  /\\___  >____/____/\n",
	"\001\e[0;32m\002      \\/        \\/        \\/     \\/     \\/           \n",
	"\001\e[0;32m\002                       Louis Charvet & Benjamin Chêne\n\n\n",	
	NULL);
	if (str)
	{
		printf("%s", str);
		free(str);		
	}
	else
		mish_error_add(mish, err_malloc, errno, "malloc mish_prompt_start");
}
