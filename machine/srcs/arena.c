/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 16:54:20 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	 init_arena(t_env *env)
{
	env->arena = ft_strnew(MEM_SIZE);
	ft_printf("arena = %s\n", env->arena);
	ft_printf("cycles = %d\n", env->cycle_to_die);
	ft_strdel(&env->arena);
}
