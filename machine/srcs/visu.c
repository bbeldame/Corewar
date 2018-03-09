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

void	curse_color()
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
}

void	init_curses(t_env *env)
{
	unsigned int			k;
	int			hex;
	int			x;
	int			y;
	t_process	*tmp;

	x = 5;
	y = 1;
	hex = 0;
	k = 0;
	initscr();
	curs_set(FALSE);
	start_color();
	curse_color();
	while (k < MEM_SIZE)
	{
		attron(COLOR_PAIR(1));
		tmp = env->head;
		while (tmp)
		{
			if (tmp->pc == k)
			{
				attron(COLOR_PAIR(1));
			}
			tmp = tmp->next;
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
			hex += 64;
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
	int			max_color;

	y = 1;
	x = 205;
	i = 0;
	color = 3;
	max_color = env->nb_players;
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

int		visu(t_env *env, int i)
{
	curses_players(env);
	attron(COLOR_PAIR(7));
    mvprintw (LINES - 5, 5, " Lives: %d ", env->nb_lives);
	mvprintw (LINES - 3, 5, " Cycles: %d ", i);
    refresh();
	sleep(1);
    endwin();
	return(0);
}