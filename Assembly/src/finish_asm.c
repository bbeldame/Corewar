/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:58:37 by arosset           #+#    #+#             */
/*   Updated: 2018/02/28 16:58:39 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void 	print_label_addr(t_asm *param, t_labdir *labdir)
{
	t_list 	*tmp;
	t_label	*label;
	int 	val;

	tmp = param->labels;
	while (tmp)
	{
		label = tmp->content;
		if (!ft_strcmp(labdir->label, label->label))
		{
			val = label->addr - labdir->instr_addr;
			ft_putchar_fd(val >> 8, param->fd);
			ft_putchar_fd(val, param->fd);
			if (lseek(param->fd, -(labdir->addr + 1), SEEK_CUR) == -1)
				return ;
			return ;
		}
		tmp = tmp->next;
	}
}

void 	complete_file(t_asm *param)
{
	t_list 		*tmp;
	t_labdir	*content;

	ft_printf("complete size = %d\n", param->prog_size);
	if (lseek(param->fd, PROG_NAME_LENGTH + 8, SEEK_SET) == -1)
		return ;
	ft_putchar_fd((unsigned)param->prog_size >> 24, param->fd);
	ft_putchar_fd(param->prog_size >> 16, param->fd);
	ft_putchar_fd(param->prog_size >> 8, param->fd);
	ft_putchar_fd(param->prog_size, param->fd);
	if (lseek(param->fd, COMMENT_LENGTH + 4, SEEK_CUR) == -1)
		return ;
	tmp = param->labdirs;
	while (tmp)
	{
		content = tmp->content;
		if (lseek(param->fd, content->addr - 1, SEEK_CUR) == -1)
			return ;
		print_label_addr(param, content);
		tmp = tmp->next;
	}
}

void 	print_label_debug(t_asm *param)
{
	t_list 	*tmp;
	t_labdir *content;

	tmp = param->labdirs;
	while (tmp)
	{
		content = tmp->content;
		ft_printf("label = >%s< addr = >%d< instr_addr >%d<\n", content->label, content->addr, content->instr_addr);
		tmp = tmp->next;
	}

}

void 	finalize_asm(t_asm *param)
{
	if ((param->fd = open(param->file_cor, O_CREAT | O_RDWR | O_TRUNC, 0755)) == -1)
		exit_msg_error(15, 0, param);
	print_magic(param->fd);
	print_header(param);
	ft_printf("header PRINT\n");
	print_body(param);
	print_label_debug(param);
	complete_file(param);
}
