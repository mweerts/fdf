/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:21:43 by maxweert          #+#    #+#             */
/*   Updated: 2025/01/17 18:48:14 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	leave(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		leave(data);
	else if (keycode == K_AR_L || keycode == K_AR_R
		|| keycode == K_AR_U || keycode == K_AR_D)
		move(data, keycode);
	else if (keycode == K_NP_PLU || keycode == K_NP_MIN)
		zoom(data, keycode);
	else if (keycode == K_NP_1 || keycode == K_NP_3 || keycode == K_NP_4
		|| keycode == K_NP_6 || keycode == K_NP_7 || keycode == K_NP_9)
		rotate(data, keycode);
	else if (keycode == K_PG_UP || keycode == K_PG_DOWN)
		flatten(data, keycode);
	else if (keycode == K_I)
		data->cam.projection = ISOMETRIC;
	else if (keycode == K_P)
		data->cam.projection = PARALLEL;
	else if (keycode == K_SP)
		reset(data);
	else
		return (0);
	draw_map(data);
	return (0);
}
