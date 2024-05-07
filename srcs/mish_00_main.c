/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_00_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:21:00 by bchene            #+#    #+#             */
/*   Updated: 2024/05/07 14:41:28 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	g_signal;
/*
t_err_type	mish_check_line(t_mish *mish)
{
	return (t_error_exist(mish->error));
}
t_err_type	mish_parse_process_line(t_mish *mish)
{
	return (t_error_exist(mish->error));
}
*/
t_err_type	mish_pipex(t_mish *mish)
{
	return (t_error_exist(mish->error));
}

int		mish_continue(t_mish *mish)
{
	if(mish_exit_status_get(mish) == 42)
	{
		return (0);
	}
	if (t_error_exist(mish->error))
	{
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_mish	mish;

	(void) argv;
	if (argc != 1)
		return (2); //exit status qd je fait ls -z
	mish_init(&mish, env);
	while (mish_continue(&mish))
	{
		mish_prompt(&mish);
		//mish_error_add(&mish, err_other, errno, "TEST"); // TEST 
		if (mish_continue(&mish))
			mish_check_line(&mish);				// only check
		if (mish_continue(&mish))
			mish_parse_process_line(&mish);		// parse
		if (mish.line && mish.line[0] && mish_continue(&mish))
			mish_print_processes(&mish);	// print
		//if (mish_continue(&mish))
		//	mish_pipex(&mish);
	}
	main_test_env(&mish); // TEST
	g_signal = mish_exit_status_get(&mish);
	mish_free(&mish);
	rl_clear_history();
	return (g_signal);
}


/* 24/04/24 					*/
/* Louis						*/
/* main pour tester le parsing 	*/
/*
int	main(int argc, char **argv, char **env)
{
	t_mish	mish;

	//mish_arg_check();
	// gestion si argc != 1
	mish_init(&mish, env);
	if (argc == 2)
	{
		mish.line = ft_strdup(argv[1]);
		if (mish.line)
		{
			//printf("mish line OK\n");
			if (!mish_check_line(&mish))
			{
				//printf("mish check line OK\n");
				if (!mish_parse_process_line(&mish))
				{
					//printf("mish parse process line OK\n");
					//mish_print_processes_free(&mish); ///
					//mish_print(&mish);
					mish_print_processes_free(&mish); //
					t_error_lst_free(&mish.error);
					//mish_free(&mish);
					//free(mish.line);
				}
			}
		}
	}
	mish_free(&mish);
	return (0);
}
*/
