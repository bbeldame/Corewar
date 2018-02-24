/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/24 19:49:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		main(int argc, char **argv)
{
	t_env	env;

	init(&env);
	parse_args(&env, argc, argv);
	parse_files(&env, argv);
	printf("hello\n");
	init_arena_and_processes(&env);
	return (0);
}
