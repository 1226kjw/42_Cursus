/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:52 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/15 23:22:35 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	errmsg(t_scene *sn, char *str)
{
	if (sn)
	{
		ft_lstclear(&sn->cams, free);
		ft_lstclear(&sn->lights, free);
		ft_lstclear(&sn->objs, free);
		free(sn->a_light);
	}
	printf("Error : %s\n", str);
	exit(1);
}

void	scene_init(t_scene *sn)
{
	ft_memset(sn, 0x00, sizeof(t_scene));
}

void	my_mlx_init(t_data *mlx, t_scene *sn)
{
	t_list	*caml;
	t_cam	*cam;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, g_x, g_y, "miniRT");
	if (!sn->cams)
		errmsg(sn, "no cam");
	sn->basecam = sn->cams;
	caml = sn->basecam;
	while (caml)
	{
		cam = (t_cam*)caml->obj;
		cam->img = mlx_new_image(mlx->mlx, g_x, g_y);
		cam->addr = mlx_get_data_addr(cam->img,
				&cam->bpp, &cam->lsize, &cam->endian);
		caml = caml->next;
	}
}

int		main(int argc, char **argv)
{
	t_arg	*args;
	int		fd;
	t_data	mlx;
	t_scene	sn;

	if (argc < 2 || argc > 3 || (argc == 3 && ft_strcmp(argv[2], "--save")))
		errmsg(0, "# of args or wrong option");
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		errmsg(0, "cannot open file");
	scene_init(&sn);
	if (parsing(fd, &sn))
		errmsg(&sn, "parsing error");
	printf("parsing complete!\n");
	my_mlx_init(&mlx, &sn);
	args = (t_arg*)ft_calloc(g_y, sizeof(t_arg));
	make_img(&mlx, &sn, args);
	mlx_put_image_to_window(mlx.mlx, mlx.win,
			((t_cam*)(sn.basecam->obj))->img, 0, 0);
	mlx_hook(mlx.win, KEY_PRESS, 0, key_handle, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
