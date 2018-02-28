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

t_list 	*init_label(char *label)
{
	t_list	*new;

	if (label == NULL)
		return (NULL);
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		exit_msg_error(10, 0, NULL);
	new->content = label;
	new->next = NULL;
	return (new);
}

int 	save_label(t_asm *param, char *label)
{
	t_list	*new;

	if ((new = init_label(label)) == NULL)
		return (0);
	ft_lstaddtail(&param->labels, new);
	return (1);
}

int 	get_label(t_asm *param)
{
	t_file_list 	*files;
	int 			i;

	i = 0;
	files = param->body;
	while (files)
	{
		if ((i = is_label(files->line)))
		{
			if (!save_label(param, ft_strsub(files->line, 0, i - 1)))
				return (0);
		}
		files = files->next;
	}
	return (1);
}

int 	ft_parse_body(t_asm *param)
{
	int 	ret;

	ret = 0;
	//ft_printf("create list label\n");
	if (!get_label(param))
		return (0);
	//ft_printf("parse body\n");
	if (!check_body(param))
		return (0);
	return (1);
}
