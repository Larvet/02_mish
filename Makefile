# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchene <bchene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 16:18:12 by bchene            #+#    #+#              #
#    Updated: 2024/05/07 14:40:36 by locharve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRCS_DIR =	./srcs
OBJS_DIR =	./objs

CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror -g

HEADERS = 	-I ./includes -I ./libs/libft
LIBS = 		./libs/libft/libft.a

# lister les fichier sous forme de colone a partir de srcs/ : 
# ls -1 *.c | sed -z 's/\n/ \\\n\t\t\t/g'
# - lo_mish_split.c
# + lo_mish_parse_line.c	lo_t_process_split.c	lo_set_processes.c	lo_strtab_if.c

SRCS =		lo_check_syntax_error.c \
			lo_check_unhandled.c \
			lo_fill_processes.c \
			lo_handle_word.c \
			lo_mish_check_line.c \
			lo_parsing.c \
			lo_print.c \
			lo_separate_processes.c \
			lo_set_processes.c \
			lo_strtab_if.c \
			lo_substitute.c \
			lo_substitute_vars.c \
			lo_t_process_split.c \
			mish_00_main.c \
			mish_01_mish_00.c \
			mish_01_mish_01_error.c \
			mish_01_mish_02_prompt.c \
			mish_01_mish_03_line.c \
			mish_01_mish_04_splitline.c \
			mish_01_mish_05_p.c \
			mish_01_mish_06_fds.c \
			mish_01_mish_07_pid.c \
			mish_01_mish_08_env.c \
			mish_01_mish_09_unset.c \
			mish_01_mish_10_env_unset.c \
			mish_01_mish_11_exit_status.c \
			mish_01_mish_12_pathlist.c \
			mish_02_t_error_00.c \
			mish_02_t_error_01.c \
			mish_03_t_env.c \
			mish_09_main_test.c \
			mish_50_process.c \
			mish_52_process_pipe.c \
			mish_53_process_exec.c \
			mish_59_pipex.c \
			mish_60_t_file.c \
			mish_90_ft_strjoin_va.c \
			mish_91_ft_00.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: libft $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -lreadline
	
libft:
	make --no-print-directory -C ./libs/libft

gdb: all
	gdb -tui $(NAME)

valgrind: all
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --suppressions=vsupp ./$(NAME)

run: all
	./$(NAME)

clean:
	rm -rf $(OBJS_DIR)
	make --no-print-directory -C ./libs/libft clean

fclean: clean
	rm -rf $(NAME)
	make --no-print-directory -C ./libs/libft fclean

re: clean all

.PHONY: all, clean, fclean, re, libft, gdb, valgrind, run
