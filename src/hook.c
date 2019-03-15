/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:07:28 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/15 16:14:30 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keymap.h"
#include "mlx.h"

void	display_usage(t_env *env)
{
	int x;
	int y;

	x = WINDOW_W - 230;
	y = 20;
	mlx_string_put(env->mlx, env->window, x + 40, y, 0xFFFFFF,
	"--- COMMANDS ---");
	mlx_string_put(env->mlx, env->window, x + 40, y + 30, 0xFFFFFF,
	"Exit      Escape");
	mlx_string_put(env->mlx, env->window, x + 40, y + 60, 0xFFFFFF,
	"Move      Arrows");
	mlx_string_put(env->mlx, env->window, x + 40, y + 90, 0xFFFFFF,
	"Zoom      SCROLL");
	mlx_string_put(env->mlx, env->window, x + 40, y + 120, 0xFFFFFF,
	"Color    	    C");
	mlx_string_put(env->mlx, env->window, x + 40, y + 150, 0xFFFFFF,
	"View threads T");
	mlx_string_put(env->mlx, env->window, x + 40, y + 180, 0xFFFFFF,
	"Hide info	    I");
}

int		print_iterations(t_env *env)
{
	char *c_it;
	char *str_it;

	if (!(c_it = ft_itoa(env->it_max)))
		return (0);
	if (!(str_it = ft_strjoin("Iterations : ", c_it)))
		return (0);
	mlx_string_put(env->mlx, env->window, 10, 10, 0xFFFFFF, str_it);
	// ft_strdel(&str_it);
	// ft_strdel(&c_it);
	return (1);
}

int		keylogger(int code, t_env *env)
{
	(code == ESC) ? exit(0) : 0;
	env->th_test = (code == T) ? !env->th_test : 0;
	env->pannel = (code == I) ? !env->pannel : 0;
	env->x1 += (code == RIGHT) ? 1 : 0;
	env->x1 -= (code == LEFT) ? 1 : 0;
	env->y1 += (code == DOWN) ? 1 : 0;
	env->y1 -= (code == UP) ? 1 : 0;
	mlx_clear_window(env->mlx, env->window);
	if (refresh(env))
		return (1);
	return (0);
}
