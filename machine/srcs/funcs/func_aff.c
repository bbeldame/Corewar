/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/03 20:39:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_aff(t_env *env, t_process *current)
{
	int		reg;
	int		i;

	i = 0;
	current->buffer = malloc(sizeof(char) * 10);
	reg = get_reg(env, current, current->pc + 2) % 256;
	printf("%c", reg);
//	if (reg != '\0')
//		current->buffer[i] = reg;
//	else
//		printf("im buffer %s\n", current->buffer);
	return (3);
}