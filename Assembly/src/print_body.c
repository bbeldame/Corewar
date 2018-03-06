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

int 	jump_nextline(char *str, int i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int 	get_label_pos(t_asm *param, t_inst *ins, int i)
{
	t_list	*tmp;
	t_label	*content;
	int 	x;

	tmp = param->labels;
	while (tmp)
	{
		content = tmp->content;
		x = ft_strlen(content->label);
		ft_printf("label = %s x = %d|| content = %sEND\n", content->label,x, param->f_content + i);
		if (ft_strncmp(content->label, param->f_content + i, x))
		{
			//ft_printf("LABEL : >%s<\n", param->f_content[i + x]);
			if (param->f_content[i + x - 1] != LABEL_CHAR)
				return (i);
			ft_printf("add addr\n");
			content->addr = ins->octet + 1;
			return (get_label_pos(param, ins, x + i));
		}
		tmp = tmp->next;
	}
	return (i);
}

void 	print_body(t_asm *param, char *f_content, int i)
{
	t_inst 		ins;

	ins.octet = 0;
	ft_printf("print body\n");
	while (f_content[i])
	{
		if ((f_content[i] == COMMENT_CHAR) && (i = jump_nextline(f_content, i)))
			continue;
		if (!is_white_space(f_content[i]))
		{
			i = get_label_pos(param, &ins, i);
			while (is_white_space(f_content[i]))
				i++;
			while (f_content[i] == COMMENT_CHAR)
				i = jump_nextline(f_content, i);
			while (is_white_space(f_content[i]))
				i++;
			ft_printf("on envoi %s\n", f_content + i);
			break;
		}
		else
			i++;
	}
}
