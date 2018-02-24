/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/24 21:22:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		init_arena_and_processes(t_env *env)
{
	int			i;

	ft_bzero(env->arena, sizeof(unsigned char) * MEM_SIZE);
	i = env->nb_players - 1;
	printf("i is %d\n", i);
	while (i >= 0)
	{
		env->player[i].live = 0;
		ft_memcpy(&(env->arena[i * MEM_SIZE / env->nb_players]),
			env->player[i].code, env->player[i].header->prog_size);
		ft_strdel(&(env->player[i].code));
		i--;
	}
	printf("ca va etre moche : %X\n", env->arena);
}
