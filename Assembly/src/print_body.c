/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:34:02 by arosset           #+#    #+#             */
/*   Updated: 2018/02/28 17:34:07 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

// int 	verif_comment(char *str)
// {
// 	int i;
//
// 	i = 0
// 	while (is_white_space(str[i]))
// 		i++;
// 	if (str[i] == COMMENT_CHAR || str[i] == '\0')
// 		return (0);
// 	return (i);
// }
//
// int 	get_label_pos(t_asm *param, t_inst *ins, char *line)
// {
// 	t_list	*tmp;
// 	t_label	*content;
// 	int 	x;
//
// 	tmp = param->labels;
// 	while (tmp)
// 	{
// 		content = tmp->content;
// 		x = ft_strlen(content->label)
// 		if (!ft_strncmp(content->label, line, x))
// 		{
//
// 		}
// 	}
// }
//
// void 	print_body(t_asm *param, t_file_list *line)
// {
// 	t_inst 	ins;
// 	int 	i;
//
// 	ins.octet = 0;
// 	while (line)
// 	{
// 		if ((i = verif_comment(line->line)))
// 		{
// 			i = get_label_pos(param, &ins, line + i);
// 		}
// 		line = line->next;
// 	}
// }
