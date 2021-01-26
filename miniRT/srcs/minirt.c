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
	t_data		img;
	t_scene		sd;

	scene_init(&sd);
	if (argc < 2 || argc > 3)
		print_err_exit(-2);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		print_err_exit(0);
	if ((i = parsing(fd, &sd)))
		print_err_exit(i);
	close(fd);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, sd.x, sd.y, "miniRT");
	img.img = mlx_new_image(img.mlx, sd.x, sd.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.bytes_per_line, &img.endian);
	make_image(&img, &sd);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, KEY_PRESS, 0, key_handle, 0);
	mlx_loop(img.mlx);
}
