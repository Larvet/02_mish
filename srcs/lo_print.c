/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:31:35 by locharve          #+#    #+#             */
/*   Updated: 2024/05/07 14:31:36 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	print_process_lines(t_process *p, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (p[i].line)
		{
			printf("p->line:\t%s\n", p[i].line);
			//free(p[i].line);
			//p[i].line = NULL;
		}
		else
			printf("error\n");
		i++;
	}
	//free(p);
	//p = NULL;
	return ;
}

void	print_files(t_file *lst)
{
	if (lst)
	{
		//if (lst->line)
		//	printf("line = %s\n", lst->line);
		printf("PRINT\ttype = %d\tpath = %s\n", lst->type, lst->path); ///
		//free(lst->line); ////////
		//lst->line = NULL;
		print_files(lst->next);
		//free(lst); //////////////
		//lst = NULL;
	}
}

void	print_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("\t%s\n", split[i]);
		//free(split[i]); /////////
		//split[i] = NULL;
		i++;
	}
	//free(split);
	//split = NULL;
}

void	mish_print_processes(t_mish *mish)
{
	int			i;

	i = 0;
	while (i < mish->nb)
	{
		printf("-------------------- PROCESS %d\n", i);
		printf("line = %s\n", mish->p[i].line);
		printf("ac = %d\n", mish->p[i].ac);
		printf("av =");
		print_split(mish->p[i].av);
		printf("---------- INFILES\n");
		print_files(mish->p[i].infiles);
		printf("---------- OUTFILES\n");
		print_files(mish->p[i].outfiles);

		//free(mish->p[i].line);
		//mish->p[i].line = NULL;
		i++;
	}
	//free(mish->p);
	//mish->p = NULL;
}
/*
void	first_substitution(t_mish *mish, char **line, char *var)
{
	if (var[1] == '0' || var[1] == '?')
		var = ft_strndup(var, 2);
	else
		var = ft_strndup(var, ft_strlen_while(&var[1],
				is_alphanum_underscore) + 1);
	if (!var)
	{
		mish_error_add(mish, err_malloc, errno, "first_substitution");
		return; //(NULL);
	}
	*line = substitute_hub(mish, *line, var);
	free(var);
	//return (line);
}
*/
/*
int	main(int argc, char **argv)
{
	t_mish	mish;
	t_error	*head;
	int		i;

	ft_bzero(&mish, sizeof(mish));
	if (argc == 2)
	{
		mish.line = ft_strdup(argv[1]);
		i = is_there_a_var(mish.line);
		if (i)
			mish_var_dup(&mish, &mish.line, &mish.line[i]);
		printf("check_unhandled : %d\nsyntax_error : %d\nopen_quotes : %d\n\n",
				mish_check_unhandled(&mish),
				mish_check_syntax_error(&mish),
				mish_check_open_quotes(&mish));
		head = mish.error;
		while (mish.error)
		{
			printf("error : %d\n", mish.error->type);
			if (mish.error->data)
				printf("\tdata : %s\n", mish.error->data);
			mish.error = mish.error->next;
		}
		mish.error = head;
		if (mish_separate_processes(&mish))
		{
			if (!mish_fill_processes(&mish)) ///////////
				mish_print_processes(&mish);
			//print_process_lines(mish.p, mish.nb);

		}
		t_error_lst_free(&mish.error);
		free(mish.line);
	}
	return (0);
}
*/
