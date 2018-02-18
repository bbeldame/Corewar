/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:28:40 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/18 16:54:24 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../../op.h"
# include "limits.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"

typedef struct		s_env
{
	int			cycles_to_die;
	char		*arena;
}					t_env;

void	init_arena(t_env *env);

#endif