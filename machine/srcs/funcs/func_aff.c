/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/24 22:09:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_aff(t_env *env, t_process *current)
{
	int		reg;
	int		i;

	i = 0;
	current->buffer = malloc(sizeof(char) * 10);
	reg = get_reg(env, current, 2) % 256;
	current->buffer[i] = reg;
	printf("im buffer %s\n", current->buffer);
	printf("BONOUR\n");
	return(1);
}