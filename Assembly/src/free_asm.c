/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:59:21 by arosset           #+#    #+#             */
/*   Updated: 2018/02/11 16:59:23 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
**		free tout les elements des t_file_list
*/

void 	free_file_list(t_file_list **list)
{
	t_file_list *cp_list;

	cp_list = (*list);
	while (cp_list)
	{
		cp_list = (*list)->next;
		if ((*list)->line)
			ft_strdel(&(*list)->line);
		free(*list);
		*list = cp_list;
	}
}
