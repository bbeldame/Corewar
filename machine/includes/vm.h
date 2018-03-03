/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:28:40 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/03 23:18:03 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "limits.h"
# include "ncurses.h"
# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"

# define LBYTE(x)	(x & 0xFF)
# define M(x)	(x % MEM_SIZE)

# define LIVE 0x01
# define ZJMP 0x09
# define FORK 0x0C
# define LFORK 0x0F

typedef struct		s_ocp
{
	char			one;
	char			two;
	char			three;
}					t_ocp;

typedef struct		s_player
{
	int				nb;
	int				file_pos;
	int				live;
	int				start_pos;
	char			*code;
	t_header		*header;
}					t_player;

typedef struct		s_process
{
	struct s_process		*prev;
	struct s_process		*next;
	int						reg[REG_NUMBER];
	int						id_champion;
	unsigned int			live;
	char					*buffer;
	unsigned int			pc;
	unsigned char			opcode;
	char					carry;
	int						wait;
}					t_process;

typedef struct		s_env
{
	int				visu;
	int				cycle;
	int				cycle_to_die;
	int				nb_lives;
	int				nb_players;
	int				dump;
	int				winner;
	int				nb_checks;
	unsigned char	arena[MEM_SIZE];
	t_player		player[MAX_PLAYERS + 1];
	t_process		*head;
}					t_env;

typedef struct		s_op
{
	int				(*func)();
	char			name[PROG_NAME_LENGTH];
	int				nb_params;
	char			params_type[3];
	int				id;
	int				cycles;
	char			description[50];
	int				acb;
	int				label_size;
}					t_op;

typedef struct		s_visu
{
	WINDOW			*win;
}					t_visu;

void				init_arena_and_processes(t_env *env);
void				init(t_env *env);
void				parse_args(t_env *env, int argc, char **argv);
void				ft_exit(int i, char *str);
void				parse_files(t_env *e, char **argv);
void				check_number(char *nb);
void				check_dup_number(t_env *env, int nb);
void				parse_players(t_env *e);
void				init_reg(t_process *process);
void				launch_lifecycle(t_env *env);
void				load_all_opcode(t_env *env);
void				get_opcode(t_env *env, t_process *current);
unsigned int		get_data_dir(t_env *e, int idx, int label_size);
t_ocp				get_ocp(t_env *env, t_process *current);
int					get_reg(t_env *e, t_process *current, int idx);
unsigned int		get_size_param(char param_type, int dir);
unsigned int		get_data_ind(t_env *e, int idx, int restr);
unsigned int		get_value(t_env *e, int idx);
unsigned int		get_jumper(t_env *e, int idx, int restr);
int					verify_reg(int r1, int r2, int r3);
unsigned int		get_data_all_types(t_env *env, t_process *current,
	int idx, char param_type);
void				print_dump(t_env *e);
int					func_add(t_env *env, t_process *current);
int					func_aff();
int					func_and(t_env *env, t_process *current, t_ocp ocp);
int					func_fork();
int					func_ld(t_env *env, t_process *current, t_ocp ocp);
int					func_ldi();
int					func_lfork();
int					func_live(t_env *env, t_process *curr);
int					func_lld(t_env *env, t_process *current, t_ocp ocp);
int					func_lldi();
int					func_or(t_env *env, t_process *current, t_ocp ocp);
int					func_st(t_env *env, t_process *current, t_ocp ocp);
int					func_sti();
int					func_sub(t_env *env, t_process *current);
int					func_xor(t_env *env, t_process *current, t_ocp ocp);
int					func_zjmp();
int					visu();

static const t_op	g_op[17] =
{
	{0, {0}, 0, {0}, 0, 0, {0}, 0, 0},
	{&func_live, "live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{&func_ld, "ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{&func_st, "st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{&func_add, "add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{&func_sub, "sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{&func_and, "and", 3,
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{&func_or, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{&func_xor, "xor", 3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{&func_zjmp, "zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{&func_ldi, "ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{&func_sti, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{&func_fork, "fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{&func_lld, "lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{&func_lldi, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1},
	{&func_lfork, "lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{&func_aff, "aff", 1, {T_REG}, 16, 2, "aff", 1, 0}
};

#endif
