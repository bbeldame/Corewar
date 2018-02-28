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

void 	finalize_asm(t_asm *param)
{
	if ((param->fd = open(param->file_cor, O_CREAT | O_RDWR | O_TRUNC, 0755)) == -1)
		exit_msg_error(15, 0, param);
	print_magic(param->fd);
	print_header(param);
	ft_printf("header PRINT\n");
}
