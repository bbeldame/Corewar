/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:20:54 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/05 00:31:57 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	init_curse_color(void)
{
	initscr();
	curs_set(FALSE);
	start_color();

	init_color(COLOR_WHITE, 220, 220, 220);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
}

void	print_curses(t_env *env, unsigned k, int y, int x)
{
	int				i;
	t_process		*tmp;

	i = 0;
	tmp = env->head;
	while (i < env->nb_processes)
	{
		if (tmp->pc == k)
			attron(COLOR_PAIR(7));
		tmp = tmp->next;
		i++;
	}
	mvprintw(y, x, "%02x ", LBYTE(env->arena[k]));
	x = x + 2;
	attron(COLOR_PAIR(1));
	mvprintw(y, x, " ");
	x++;
	if ((k + 1) % (64) == 0)
	{
		y++;
		x = 5;
	}
}

void	init_curses(t_env *env)
{
	unsigned int	k;
	int				y;
	int				x;

	k = 0;
	x = 5;
	y = 1;
	while (k < MEM_SIZE)
	{
		attron(COLOR_PAIR(1));
		print_curses(env, k, y, x);
		x = x + 3;
		if ((k + 1) % (64) == 0)
		{
			y++;
			x = 5;
		}
		k++;
	}
}

void	curses_players(t_env *env)
{
	int			i;
	int			x;
	int			y;
	int			color;

	y = 1;
	x = 205;
	i = 0;
	color = 3;
	while (i < env->nb_players)
	{
		attron(COLOR_PAIR(color));
		mvprintw(y, x, env->player[i].header->prog_name);
		mvprintw(y + 1, x + 1, "Lives : %d", env->player[i].live);
		y += 3;
		i++;
		color++;
	}
}

int		visu(t_env *env, int cycles_left)
{
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	if ((getch()) == 32)
	{
		sleep(5);
	}
	curses_players(env);
	attron(COLOR_PAIR(7));
	mvprintw(LINES - 5, 5, " Lives: %d ", env->nb_lives);
	mvprintw(LINES - 3, 5, " Cycles: %d / %d",
		env->cycle_to_die - cycles_left, env->cycle_to_die);
	mvprintw(LINES - 7, 5, " Total cycles : %d", env->cycle);
	refresh();
	return (0);
}
