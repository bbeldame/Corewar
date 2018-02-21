/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:28:40 by msakwins          #+#    #+#             */
/*   Updated: 2018/02/21 20:06:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "limits.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"

# define TOTAL_SIZE		(PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE + 4)
# define OFFSET_NAME	4
# define OFFSET_COMMENT (PROG_NAME_LENGTH + 12)
# define GOOD_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0\
	123456789'+-*/=_.,"

typedef struct		s_player
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				nb;
	int				file_pos;
	int				len;
	int				live;
	char			string[TOTAL_SIZE + 1];
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
