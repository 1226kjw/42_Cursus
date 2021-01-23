/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <marvin.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:09:13 by jinukim           #+#    #+#             */
/*   Updated: 2021/01/22 21:44:09 by jinukim          ###   ########.fr       */
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

int		scene_init(t_scene *sd)
{
	sd->x = 0;
	sd->y = 0;
	ncam = 0;
	nlight = 0;
	nsphere = 0;
}

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_data		img;
	t_scene		*sd;

	scene_init(sd);
	if (argc < 2 || argc > 3)
		print_err_exit(-2);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		print_err_exit(0);
	if ((i = parsing(fd, sd)))
		print_err_exit(i);
	close(fd);
	img.mlx = mlx_init();
}
