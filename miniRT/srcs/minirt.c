/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:57:52 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 16:56:20 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	errmsg(t_scene *sn, char *str)
{
	if (sn)
	{
		ft_lstclear(&sn->cams, free);
		ft_lstclear(&sn->lights, free);
		ft_lstclear(&sn->p_lights, free);
		ft_lstclear(&sn->objs, free);
		free(sn->a_light);
	}
	if (str)
		printf("Error : %s\n", str);
	exit(1);
}

void	scene_init(t_scene *sn)
{
	ft_memset(sn, 0x00, sizeof(t_scene));
}

void	my_mlx_loop(t_data *mlx)
{
	mlx_key_hook(mlx->win, key_handle, mlx);
	mlx_mouse_hook(mlx->win, button_handle, mlx);
	mlx_hook(mlx->win, DESTROYNOT, 1L << 17, close_program, mlx);
	mlx_loop(mlx->mlx);
}

void	my_mlx_init(t_data *mlx, t_scene *sn)
{
	t_list	*caml;
	t_cam	*cam;
	int		r[2];

	mlx->mlx = mlx_init();
	mlx_get_screen_size(mlx->mlx, &r[0], &r[1]);
	g_x = g_x > r[0] ? r[0] : g_x;
	g_y = g_y > r[1] ? r[1] : g_y;
	mlx->win = mlx_new_window(mlx->mlx, g_x, g_y, "miniRT");
	if (!sn->cams)
		errmsg(sn, "no cam");
	sn->basecam = sn->cams;
	sn->baseobj = sn->objs;
	caml = sn->basecam;
	while (caml)
	{
		cam = (t_cam*)caml->obj;
		cam->img = mlx_new_image(mlx->mlx, g_x, g_y);
		cam->addr = mlx_get_data_addr(cam->img,
				&cam->bpp, &cam->lsize, &cam->endian);
		caml = caml->next;
	}
	mlx->sn = sn;
}

int		main(int argc, char **argv)
{
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
	my_mlx_init(&mlx, &sn);
	sn.x = g_x;
	sn.y = g_y;
	make_img(&mlx, &sn);
	if (argc == 3)
		save_file(argv[1], &sn);
	mlx_put_image_to_window(mlx.mlx, mlx.win,
			((t_cam*)(sn.basecam->obj))->img, 0, 0);
	my_mlx_loop(&mlx);
	return (0);
}
