/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:38:20 by sihkang           #+#    #+#             */
/*   Updated: 2024/10/30 14:47:18 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"
#include "parsing.h"

int	minirt(t_vars *var, t_scene *scene, char *filename)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;

	read_rt_file(scene, filename);
	j = 0;
	while (j <= scene->canvas.height)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width);
			v = (double)j / (scene->canvas.height);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			put_color(var->image, i, WIN_HEIGHT - j, pixel_color);
			++i;
		}
		++j;
	}
	return (0);
}
