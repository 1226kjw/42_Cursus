#include "minirt.h"

void	obj_hub(t_data *mlx, t_scene *sn, int keycode)
{
	if (keycode == UP)
		obj_next(sn);
	else if (keycode == DOWN)
		obj_bef(sn);
	else if (keycode == NUM1)
		obj_left(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM2)
		obj_backward(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM3)
		obj_right(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM4)
		obj_down(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM5)
		obj_forward(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM6)
		obj_up(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM7)
		obj_rotx(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM8)
		obj_roty(mlx, sn, sn->baseobj->obj);
	else if (keycode == NUM9)
		obj_rotz(mlx, sn, sn->baseobj->obj);
}

void	obj_next(t_scene *sn)
{
	if (sn->baseobj->next)
		sn->baseobj = sn->baseobj->next;
	else
		sn->baseobj = sn->objs;
}

void	obj_bef(t_scene *sn)
{
	if (sn->baseobj->bef)
		sn->baseobj = sn->baseobj->bef;
	else
		sn->baseobj = ft_lstlast(sn->objs);
}

void	obj_left(t_data *mlx, t_scene *sn, void *obj)
{
	t_v3	v;

	v = ((t_cam*)sn->basecam->obj)->hor;
	if (sn->baseobj->type == SP)
		((t_sp*)obj)->o = vadd(((t_sp*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->o = vadd(((t_pl*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->o = vadd(((t_sq*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->o = vadd(((t_cy*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vadd(((t_tr*)obj)->a, vmul(v, -SCALE));
		((t_tr*)obj)->b = vadd(((t_tr*)obj)->b, vmul(v, -SCALE));
		((t_tr*)obj)->c = vadd(((t_tr*)obj)->c, vmul(v, -SCALE));
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->o = vadd(((t_ci*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->o = vadd(((t_co*)obj)->o, vmul(v, -SCALE));
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	obj_backward(t_data *mlx, t_scene *sn, void *obj)
{
	t_v3	v;

	v = ((t_cam*)sn->basecam->obj)->d;
	if (sn->baseobj->type == SP)
		((t_sp*)obj)->o = vadd(((t_sp*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->o = vadd(((t_pl*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->o = vadd(((t_sq*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->o = vadd(((t_cy*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vadd(((t_tr*)obj)->a, vmul(v, -SCALE));
		((t_tr*)obj)->b = vadd(((t_tr*)obj)->b, vmul(v, -SCALE));
		((t_tr*)obj)->c = vadd(((t_tr*)obj)->c, vmul(v, -SCALE));
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->o = vadd(((t_ci*)obj)->o, vmul(v, -SCALE));
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->o = vadd(((t_co*)obj)->o, vmul(v, -SCALE));
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}
