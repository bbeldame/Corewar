/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:28:40 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/21 22:19:03 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "limits.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"

typedef struct		s_player
{
	int				nb;
	int				file_pos;
	int				live;
	int				start_pos;
	char			*code;
	t_header		*header;
}					t_player;

typedef struct		s_env
{
	int				cycle_to_die;
	int				nb_players;
	int				dump;
	char			*arena;
	t_player		player[MAX_PLAYERS + 1];
}					t_env;

void				init_arena(t_env *env);
void				init(t_env *env);
void				parse_args(t_env *env, int argc, char **argv);
void				ft_exit(int i, char *str);
void				parse_files(t_env *e, char **argv);
void				check_number(char *nb);
void				check_dup_number(t_env *env, int nb);
void				parse_players(t_env *e);

#endif
