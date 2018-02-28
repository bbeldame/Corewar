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

void 	print_header(t_asm *param)
{
	int 	len;

	len = ft_strlen(param->name_prg);
	write(param->fd, param->name_prg, ft_strlen(param->name_prg));
	while (++len <= PROG_NAME_LENGTH)
		write(param->fd, "\0", 1);
	write(param->fd, "\0\0\0\0\0\0\0\0", 8);
	len = ft_strlen(param->comment_prg);
	write(param->fd, param->comment_prg, ft_strlen(param->comment_prg));
	while (++len <= COMMENT_LENGTH)
		write(param->fd, "\0", 1);
}

void 	print_magic(int fd)
{
	int 	magic[4];
	int 	mag;
	int 	i;

	i = -1;
	mag = COREWAR_EXEC_MAGIC;
	while (++i < 4)
	{
		magic[i] = (unsigned char)mag;
		mag >>= 8;
	}
	while (--i >= 0)
		write(fd, &magic[i], 1);
}

void 	finalize_asm(t_asm *param)
{
	if ((param->fd = open(param->file_cor, O_CREAT | O_RDWR | O_TRUNC, 0755)) == -1)
		exit_msg_error(15, 0, param);
	print_magic(param->fd);
	print_header(param);
	ft_printf("header PRINT\n");
}
