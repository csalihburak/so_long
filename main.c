/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:03:37 by scoskun           #+#    #+#             */
/*   Updated: 2022/05/10 14:05:59 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_list *main)
{
	mlx_destroy_image(main->mlx, main->wall);
	mlx_destroy_image(main->mlx, main->p);
	mlx_destroy_image(main->mlx, main->coll);
	mlx_destroy_image(main->mlx, main->exit);
	mlx_destroy_window(main->mlx, main->win);
	free(main->map);
	free(main);
	exit(0);
}

int	move(int keycode, t_list *main)
{
	if (keycode == 13 || keycode == 126)
		moveup(main);
	if (keycode == 1 || keycode == 125)
		movedown(main);
	if (keycode == 2 || keycode == 124)
		moveright(main);
	if (keycode == 0 || keycode == 123)
		moveleft(main);
	if (keycode == 53)
	{
		ft_printf("%sGame closed by player\n", "\x1B[31m");
		ft_exit(main);
	}
	mlx_clear_window(main->mlx, main->win);
	putimage(main, keycode);
	if (main->movecount > 498)
	{
		ft_printf("%sIs this game so hard for you!\n", "\x1B[31m");
		ft_exit(main);
	}
	return (1);
}

int	bercheck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i < 4)
		return (0);
	if (s[i - 1] != 'r' || s[i - 2] != 'e' || s[i - 3] != 'b' || \
		s[i - 4] != '.')
	{
		ft_printf("%sError\nWrong file name!\n", "\x1B[31m");
		return (0);
	}
	return (1);
}

int	xbutton(t_list *main)
{
	(void)main;
	ft_printf("%sGame closed by player!\n", "\x1B[31m");
	ft_exit(main);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*main;

	if (ac == 2)
	{
		main = malloc(sizeof(t_list));
		if (!bercheck(av[1]))
		{
			ft_printf("Map name has to end with .ber extension!\n");
			return (0);
		}
		if (!(createmap(main, av[1])))
		{
			ft_printf("Error\nYour map is wrong\n");
			return (0);
		}
		mlx_hook(main->win, 2, 1L << 0, move, main);
		mlx_hook(main->win, 17, 0, xbutton, main);
		mlx_loop(main->mlx);
	}
	else
	{
		ft_printf("%sError\nWrong Argument Number!\n", "\x1B[31m");
		exit(0);
	}
}
