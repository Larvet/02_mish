/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_09_main_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:21:00 by bchene            #+#    #+#             */
/*   Updated: 2024/04/27 17:42:26 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	main_test_env(t_mish *mish)
{
	printf("LOGNAME=%s\n",mish_env_get(mish, "LOGNAME"));

	printf("NO_ENV=%s\n",mish_env_get(mish, "NO_ENV"));
	mish_env_add(mish, "NO_ENV", "SET_ENV");
	printf("NO_ENV=%s\n",mish_env_get(mish, "NO_ENV"));
	mish_env_remove(mish, "NO_ENV");
	printf("NO_ENV=%s\n",mish_env_get(mish, "NO_ENV"));
	/* tester ajout nom particulier */

	printf("0=%s\n",mish_unset_get(mish, "0"));
	printf("NO_UNUSET=%s\n",mish_unset_get(mish, "NO_UNUSET"));
	mish_unset_set(mish, "NO_UNUSET", "SET_UNUSET");
	printf("NO_UNUSET=%s\n",mish_unset_get(mish, "NO_UNUSET"));
	mish_unset_remove(mish, "NO_UNUSET");
	printf("NO_UNUSET=%s\n",mish_env_get(mish, "NO_UNUSET"));
	/* tester ajout nom particulier */

	mish_exit_status_set(mish, 124);
	printf("EXIT_STATUS=%i\n",mish_exit_status_get(mish));
}
