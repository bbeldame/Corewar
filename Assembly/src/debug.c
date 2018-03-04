/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:42:16 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 16:08:30 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	ft_print_file_list(t_file_list *list)
{
	while (list)
	{
		ft_printf("line[%d] = >%s<\n", list->num_l, list->line);
		list = list->next;
	}
}

void	debug_print_list(t_asm *param)
{
	if (param->header != NULL)
	{
		ft_printf("\n\033[33m== List Header ==\033[32m\n");
		ft_print_file_list(param->header);
	}
	else
		ft_printf("\n\033[33m== List Header ==\033[32m\nparam->header NULL\
				\n\n");
	if (param->body != NULL)
	{
		ft_printf("\n\033[33m== List Body ==\033[32m\n");
		ft_print_file_list(param->body);
	}
	else
		ft_printf("\n\033[33m== List Body ==\033[32m\nparam->body NULL\n");
}

/*
**		print struct asm
**		ft_print_asm(&param);
*/

void	ft_print_asm(t_asm *param)
{
	ft_printf(" \033[31m=== START DEBUG === \033[32m\n");
	if (param->name_prg != NULL)
		ft_printf("param->name_prg = >%s<\n", param->name_prg);
	else
		ft_printf("param->name_prg NULL\n");
	if (param->comment_prg != NULL)
		ft_printf("param->comment_prg = >%s<\n", param->comment_prg);
	else
		ft_printf("param->comment_prg NULL\n");
	if (param->file_s != NULL)
		ft_printf("param->file_s = >%s<\n", param->file_s);
	else
		ft_printf("param->file_s NULL\n");
	if (param->file_cor != NULL)
		ft_printf("param->file_cor = >%s<\n", param->file_cor);
	else
		ft_printf("param->file_cor NULL\n");
	debug_print_list(param);
	ft_printf(" \033[31m=== END DEBUG === \033[00m\n");
}

void	print_tab(char **tab)
{
	int i;

	i = 0;
	ft_printf("\n Print tab \n");
	while (tab[i])
	{
		ft_printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
	ft_printf("\n --- \n");
}

void	print_label(t_asm *param)
{
	ft_printf("\nPrint Label\n");
	while (param->labels)
	{
		ft_printf("label = %s\n", param->labels->content);
		param->labels = param->labels->next;
	}
}
