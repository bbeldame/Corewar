/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:34:47 by arosset           #+#    #+#             */
/*   Updated: 2018/02/16 10:34:48 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

// void put_hexa(long code, int fd)
// {
// 	if (code >= 16 * 16)
// 	{
// 		put_hexa(code / (16 * 16), fd);
// 		put_hexa(code % (16 * 16), fd);
// 	}
// 	else
// 		ft_putchar_fd(code, fd);
// }
//
// void	print_magic(int fd)
// {
// 	long 	nb;
// 	int 	count;
//
// 	count = 0;
// 	nb = COREWAR_EXEC_MAGIC;
// 	while (nb != 0)
// 	{
// 		nb = nb / 256;
// 		count++;
// 	}
// 	while (4 - count)
// 	{
// 		ft_printf("put\n");
// 		ft_putchar_fd(0x0, fd);
// 		count++;
// 	}
// 	// ft_putchar_fd(0x0, fd);
// 	put_hexa(COREWAR_EXEC_MAGIC, fd);
// }
//
// void 	print_header(t_asm *param)
// {
// 		int 	fd;
// 		int 	i;
//
// 		i = -1;
// 		fd = open(param->file_cor, O_CREAT | O_RDWR | O_TRUNC, 0755);
// 		print_magic(fd);
// 		while (param->name_prg[i++])
// 			ft_putchar_fd(param->name_prg[i], fd);
// 		while (++i < PROG_NAME_LENGTH + 1)
// 			ft_putchar_fd(0x0, fd);
// 		i = -1;
//
// 		put_hexa(15, fd);
// 		while (param->comment_prg[i++])
// 			ft_putchar_fd(param->comment_prg[i], fd);
// 		while (++i < COMMENT_LENGTH + 5)
// 			ft_putchar_fd(0x0, fd);
//
// }
