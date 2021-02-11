#include "minirt.h"

void	my_pixel_put(t_cam *cam, int x, int y, int color)
{
	char	*p;

	p = cam->addr;
	p += y * cam->lsize + x * cam->bpp / 8;
	*p = (color >> 16) & 0xff;
	*(p + 1) = (color >> 8) & 0xff;
	*(p + 2) = color & 0xff;
}

void	make_img(t_data *mlx, t_scene *sn, t_arg *args)
{
	t_list	*cam;

	cam = sn->cams;
	while (cam)
	{
		args_set(mlx, sn, (t_cam*)cam->obj, args);
		multithreading(args);
		cam = cam->next;
	}
}
