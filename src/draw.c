/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:12:36 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/11 14:18:46 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <pthread.h>

void	*thread_task(void *arg)
{
	printf("COUCOU\n");
	return (arg);
}

int		draw(t_env *env)
{
	pthread_t	threads[THREADS];
	t_env		tab[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		pthread_create(&threads[i], NULL, thread_task, &tab[i]);
	}
	while (i--)
		pthread_join(threads[i], NULL);
	if (!(mlx_put_image_to_window(env->mlx, env->window, env->img->image, 0, 0)))
		return (errors(MLX));
	return (0);
}