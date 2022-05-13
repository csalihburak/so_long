/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:45:37 by eguler            #+#    #+#             */
/*   Updated: 2022/05/10 13:12:45 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*p;
	void	*wall;
	void	*coll;
	void	*exit;
	char	*map;
	int		sizex;
	int		sizey;
	int		fd;
	int		index;
	int		slen;
	int		cc;
	int		x;
	int		y;
	int		pindex;
	int		movecount;
}			t_list;

int		createmap(t_list *main, char *map);
int		ft_strchr(const char *s, int c);
int		checkmap(t_list *main);
char	*ft_read(int fd, char *left_str);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *s);
void	setup(t_list *stp);
void	putimage(t_list *put, int key);
void	moveup(t_list *main);
void	movedown(t_list *main);
void	moveright(t_list *main);
void	moveleft(t_list *main);
int		checkarray(t_list *main);
void	ft_exit(t_list *main);
int		ft_printf(const char *s, ...);
#endif
