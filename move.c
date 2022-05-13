/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:04:29 by scoskun           #+#    #+#             */
/*   Updated: 2022/05/07 17:52:03 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex - main->slen - 1] != '1' \
		&& main->map[main->pindex - main->slen - 1] == '0')
	{
		main->map[main->pindex - main->slen - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
	}
	if (main->map[main->pindex - main->slen - 1] == 'C')
	{
		main->map[main->pindex - main->slen - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
	}
	if (main->map[main->pindex - main->slen - 1] == 'E' && main->cc == 0)
	{
		ft_printf("%sCongratulations, you killed all the Wolves and found the exit. \
		\nYou won!\nIs %d moves really the best you can do?\n", "\x1B[35m", \
		main->movecount);
		ft_exit(main);
	}
}

void	movedown(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex + main->slen + 1] != '1' \
		&& main->map[main->pindex + main->slen + 1] == '0')
	{
		main->map[main->pindex + main->slen + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
	}
	if (main->map[main->pindex + main->slen + 1] == 'C')
	{
		main->map[main->pindex + main->slen + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
	}
	if (main->map[main->pindex + main->slen + 1] == 'E' && main->cc == 0)
	{
		ft_printf("%sCongratulations, you killed all the Wolves and found the exit. \
		\nYou won!\nIs %d moves really the best you can do?\n", "\x1B[35m", \
		main->movecount);
		ft_exit(main);
	}
}

void	moveright(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex + 1] != '1' \
		&& main->map[main->pindex + 1] == '0')
	{
		main->map[main->pindex + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
	}
	if (main->map[main->pindex + 1] == 'C')
	{
		main->map[main->pindex + 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
	}
	if (main->map[main->pindex + 1] == 'E' && main->cc == 0)
	{
		ft_printf("%sCongratulations, you killed all the Wolves and found the exit. \
		\nYou won!\nIs %d moves really the best you can do?\n", "\x1B[35m", \
		main->movecount);
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
		ft_exit(main);
	}
}

void	moveleft(t_list *main)
{
	checkarray(main);
	if (main->map[main->pindex - 1] != '1' \
		&& main->map[main->pindex - 1] == '0')
	{
		main->map[main->pindex - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
	}
	if (main->map[main->pindex - 1] == 'C')
	{
		main->map[main->pindex - 1] = 'P';
		main->map[main->pindex] = '0';
		main->movecount++;
		ft_printf("%sYour moved %d times\n", "\x1B[34m", main->movecount);
	}
	if (main->map[main->pindex - 1] == 'E' && main->cc == 0)
	{
		ft_printf("%sCongratulations, you killed all the Wolves and found the exit. \
		\nYou won!\nIs %d moves really the best you can do?\n", "\x1B[35m", \
		main->movecount);
		ft_exit(main);
	}
}
