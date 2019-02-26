/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:53:47 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/26 15:16:29 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractol(int arg)
{
	t_env	env;

	env.fractal = arg;
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_putendl_fd("Usage : ./fractol <fractal id> <help>", 2);
		return (1);
	}
	else if (ft_strcmp("help", argv[1]) == 0)
		ft_putstr("1 : Suite de Mandelbrot\n2 : Suite de Julia\n");
	else if (fractol(ft_atoi(argv[1])))
		return (1);
	return (0);
}
