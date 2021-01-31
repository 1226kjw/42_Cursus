/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:09:13 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/25 20:03:14 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_err_exit(int n)
{
	if (n == 0)
		printf("Error: %s\n", strerror(errno));
	else if (n == -1)
		printf("Error: gnl errors.\n");
	else if (n == -2)
		printf("Error: # of args.\n");
	else if (n == -3)
		printf("Error: Unknown type exists in .rt file.\n");
	else if (n == -4)
		printf("Error: Dup type.\n");
	else if (n == -5)
		printf("Error: Too much elements.\n");
	else if (n == -6)
		printf("Error: Invalid elements.\n");
	else if (n == -7)
		printf("Error: Limit excess.\n");
	exit(n);
}

void	scene_init(t_scene *sd)
{
	sd->x = 0;
	sd->y = 0;
	sd->ncam = 0;
	sd->nlight = 0;
	sd->nsphere = 0;
	sd->nth = 0;
}

int		key_handle(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_data		data;
	t_scene		sd;

	scene_init(&sd);
	if (argc < 2 || argc > 3)
		print_err_exit(-2);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		print_err_exit(0);
	if ((i = parsing(fd, &sd)))
		print_err_exit(i);
	close(fd);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, sd.x, sd.y, "miniRT");
	i = -1;
	while (++i < sd.ncam)
	{
		sd.cam[i].img.img = mlx_new_image(data.mlx, sd.x, sd.y);
		sd.cam[i].img.addr = mlx_get_data_addr(sd.cam[i].img.img, &sd.cam[i].img.bits_per_pixel, &sd.cam[i].img.bytes_per_line, &sd.cam[i].img.endian);
		make_image(&sd);
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, sd.cam[0].img.img, 0, 0);
	mlx_hook(data.mlx_win, KEY_PRESS, 0, key_handle, 0);
	mlx_loop(data.mlx);
}
