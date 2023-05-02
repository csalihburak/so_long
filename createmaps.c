/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:03:57 by scoskun           #+#    #+#             */
/*   Updated: 2023/05/02 20:19:42 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizexy(t_list *main)
{
	int	i;

	i = 0;
	while (main->map[i] != '\0')
	{
		if (main->map[i] != '\n' && main->sizey == 0)
			main->sizex += 64;
		if (main->map[i] == '\n')
			main->sizey += 64;
		i++;
	}
	main->sizey += 64;
}

void	putimage2(t_list *main, int i, int key)
{
	int	a;

	a = 65;
	if (main->map[i] == 'P')
	{
		if (key == 0 || key == 123)
			main->p = mlx_xpm_file_to_image(main->mlx, "a.xpm", &a, &a);
		else if (key == 2 || key == 124)
			main->p = mlx_xpm_file_to_image(main->mlx, "p.xpm", &a, &a);
		mlx_put_image_to_window(main->mlx, main->win, main->p, \
		main->x, main->y);
		main->x += 64;
	}
	if (main->map[i] == 'E')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->exit, \
		main->x, main->y);
		main->x += 64;
	}
	if (main->map[i] == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->coll, \
		main->x, main->y);
		main->x += 64;
	}
}

void	putimage(t_list *main, int key)
{
	int	i;

	i = 0;
	main->x = 0;
	main->y = 0;
	while (main->map[i])
	{
		if (main->map[i] == '1')
		{
			mlx_put_image_to_window(main->mlx, main->win, main->wall, \
			main->x, main->y);
			main->x += 64;
		}
		if (main->map[i] == '0')
			main->x += 64;
		if (main->map[i] == '\n')
		{
			main->x = 0;
			main->y += 64;
		}
		if (main->map[i] == 'E' || main->map[i] == 'P' || main->map[i] == 'C')
			putimage2(main, i, key);
		i++;
	}
}

void	setup(t_list *main)
{
	int	a;
	int	b;

	a = 65;
	b = 65;
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, main->sizex, main->sizey, "so_long");
	main->wall = mlx_xpm_file_to_image(main->mlx, "wall.xpm", &a, &b);
	main->exit = mlx_xpm_file_to_image(main->mlx, "exit.xpm", &a, &b);
	main->p = mlx_xpm_file_to_image(main->mlx, "p.xpm", &a, &b);
	main->coll = mlx_xpm_file_to_image(main->mlx, "coll.xpm", &a, &b);
	main->sizex = 0;
	main->sizey = 0;
	putimage(main, 5);
}

int	createmap(t_list *main, char *file)
{
	main->fd = open(file, O_RDONLY);
	if (main->fd < 0)
		return (0);
	main->map = ft_read(main->fd, main->map);
	int res = checkmap(main);
	printf("%d\n", res);
	if (res != 1)
	{
		free(main->map);
		return (0);
	}
	sizexy(main);
	setup(main);
	return (1);
}
