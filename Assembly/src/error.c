/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:08:57 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:56:02 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	ft_error(char *s)
{
	ft_printf("Error: %s\n", s);
	exit(EXIT_FAILURE);
}

void	delete_asm(t_asm *param)
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

void	msg_header(int c_er, t_asm *param)
{
	if (c_er == 30)
		ft_printf("Error : Champion name too long (%d) max %d\n",
			ft_strlen(param->name_prg), PROG_NAME_LENGTH);
	else if (c_er == 31)
		ft_printf("Error : Champion comment too long (%d) max %d\n",
			ft_strlen(param->comment_prg), COMMENT_LENGTH);
}

char	*set_msg_error(int c_er)
{
	if (c_er == 10)
		return ("Malloc");
	else if (c_er == 11)
		return ("Open failure");
	else if (c_er == 12)
		return ("Invalide extension");
	else if (c_er == 13)
		return ("Unknow champ name");
	else if (c_er == 14)
		return ("Unknow champ comment");
	else if (c_er == 15)
		return ("Create failure");
	else if (c_er == 16)
		return ("Syntax header");
	else if (c_er == 20)
		return ("");
	else if (c_er == 21)
		return ("Bad body");
	else if (c_er == 22)
		return ("Unknow instruction");
	else
		return ("Unknow error");
}

/*
**			c_er : 1x => no num line
**				   2x => num line
**	L81 ft_print_asm() => fonction pour le debug peut provoquer des segfault
*/

void	exit_msg_error(int c_er, int n_line, t_asm *param)
{
	char	*msg;

	// if (c_er != 11)
	// 	ft_print_asm(param);
	if (c_er >= 30 && c_er < 40)
		msg_header(c_er, param);
	if (param)
		delete_asm(param);
	msg = set_msg_error(c_er);
	if (c_er >= 20 && c_er < 30)
		ft_printf("Error : %s at L%d\n", msg, n_line);
	else if (c_er >= 10 && c_er < 20)
		ft_printf("Error : %s\n", msg);
	else if (c_er >= 30 && c_er < 40)
		exit(EXIT_FAILURE);
	else
		ft_printf("Error : Unknow c_er\n");
	exit(EXIT_FAILURE);
}
