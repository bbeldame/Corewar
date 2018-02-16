/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:08:57 by arosset           #+#    #+#             */
/*   Updated: 2018/01/26 15:08:58 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void 	ft_error(char *s)
{
	ft_printf("Error: %s\n", s);
	exit(EXIT_FAILURE);
}

void 	delete_asm(t_asm *param)
{
	if (param->name_prg)
		ft_strdel(&param->name_prg);
	if (param->comment_prg)
		ft_strdel(&param->comment_prg);
	if (param->file_cor)
		ft_strdel(&param->file_cor);
	if (param->header)
		free_file_list(&param->header);
	// if (param->body)
	// 	free_file_list(&param->body);
	// free(param);
}

char 	*set_msg_error(int c_er)
{
	if (c_er == 10)
		return ("malloc error");
	else if (c_er == 11)
		return ("open failure");
	else if (c_er == 12)
		return ("invalide extension");
	else if (c_er == 20)
		return ("bad header");
	else if (c_er == 21)
		return ("bad body");
	else
		return ("Unknow error");
}

/*
**			c_er : 1x => no num line
**				   2x => num line
*/

void 	exit_msg_error(int c_er, int n_line, t_asm *param)
{
	char 	*msg;


	ft_print_asm(param);
	if (param)
		delete_asm(param);
	msg = set_msg_error(c_er);
	if (c_er >= 20 && c_er < 30)
		ft_printf("Error : %s at L%d\n", msg, n_line);
	else if (c_er >= 10 && c_er < 20)
		ft_printf("Error : %s\n", msg);
	else
		ft_printf("Error : Unknow c_er\n");
	exit(EXIT_FAILURE);
}
