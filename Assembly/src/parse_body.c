/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:45:09 by arosset           #+#    #+#             */
/*   Updated: 2018/02/12 14:45:11 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void 	ft_parse_body(t_asm *param)
{
	char 	**tab;
	char 	*label;
	int 	i;

	i = 0;
	label = NULL;
	tab = NULL;
	while (param->body)
	{
		if ((i = is_label(param->body->line)))
		{
			label = ft_strsub(param->body->line, 0, i);
			ft_printf("label = %s\n", label);
		}
		tab = ft_strsplit(param->body->line + i, ' ');
		
		print_tab(tab);
		free_tab(tab);
		param->body = param->body->next;
	}
}
