/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/09 22:41:05 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		anounce_the_winner(t_env *env)
{
	ft_printf("Contestant 1, \"%s\", has won !\n",
		env->player[env->winner].header->prog_name);
}

int				main(int argc, char **argv)
{
	t_env	env;

	init(&env);
	parse_args(&env, argc, argv);
	parse_files(&env, argv);
	init_arena_and_processes(&env);
	if (env.visu)
		init_curses(&env);
	launch_lifecycle(&env);
	anounce_the_winner(&env);
	return (0);
}
