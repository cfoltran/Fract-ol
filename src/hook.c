/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:07:28 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/07 13:54:40 by clfoltra         ###   ########.fr       */
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
	"Hide info	    I");
}

int		keylogger(int code, t_env *env)
{
	(code == ESC) ? exit(0) : 0;
	env->pannel = (code == I) ? !env->pannel : 0;
	mlx_clear_window(env->mlx, env->window);
	if (refresh(env))
		return (1);
	return (0);
}
