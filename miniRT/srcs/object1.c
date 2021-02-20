#include "minirt.h"

void	obj_right(t_data *mlx, t_scene *sn, void *obj)
{
	t_v3	v;

	v = ((t_cam*)sn->basecam->obj)->hor;
	if (sn->baseobj->type == SP)
		((t_sp*)obj)->o = vadd(((t_sp*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->o = vadd(((t_pl*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->o = vadd(((t_sq*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->o = vadd(((t_cy*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vadd(((t_tr*)obj)->a, vmul(v, SCALE));
		((t_tr*)obj)->b = vadd(((t_tr*)obj)->b, vmul(v, SCALE));
		((t_tr*)obj)->c = vadd(((t_tr*)obj)->c, vmul(v, SCALE));
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->o = vadd(((t_ci*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->o = vadd(((t_co*)obj)->o, vmul(v, SCALE));
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	obj_down(t_data *mlx, t_scene *sn, void *obj)
{
	t_v3	v;

	v = ((t_cam*)sn->basecam->obj)->ver;
	if (sn->baseobj->type == SP)
		((t_sp*)obj)->o = vadd(((t_sp*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->o = vadd(((t_pl*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->o = vadd(((t_sq*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->o = vadd(((t_cy*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vadd(((t_tr*)obj)->a, vmul(v, SCALE));
		((t_tr*)obj)->b = vadd(((t_tr*)obj)->b, vmul(v, SCALE));
		((t_tr*)obj)->c = vadd(((t_tr*)obj)->c, vmul(v, SCALE));
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->o = vadd(((t_ci*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->o = vadd(((t_co*)obj)->o, vmul(v, SCALE));
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	obj_forward(t_data *mlx, t_scene *sn, void *obj)
{
	t_v3	v;

	v = ((t_cam*)sn->basecam->obj)->d;
	if (sn->baseobj->type == SP)
		((t_sp*)obj)->o = vadd(((t_sp*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == PL)
		((t_pl*)obj)->o = vadd(((t_pl*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == SQ)
		((t_sq*)obj)->o = vadd(((t_sq*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == CY)
		((t_cy*)obj)->o = vadd(((t_cy*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == TR)
	{
		((t_tr*)obj)->a = vadd(((t_tr*)obj)->a, vmul(v, SCALE));
		((t_tr*)obj)->b = vadd(((t_tr*)obj)->b, vmul(v, SCALE));
		((t_tr*)obj)->c = vadd(((t_tr*)obj)->c, vmul(v, SCALE));
	}
	else if (sn->baseobj->type == CI)
		((t_ci*)obj)->o = vadd(((t_ci*)obj)->o, vmul(v, SCALE));
	else if (sn->baseobj->type == CO)
		((t_co*)obj)->o = vadd(((t_co*)obj)->o, vmul(v, SCALE));
	mlx_clear_window(mlx->mlx, mlx->win);
	make_img(mlx, sn);
	mlx_put_image_to_window(mlx->mlx, mlx->win,
			((t_cam*)sn->basecam->obj)->img, 0, 0);
}

void	obj_up(t_data *mlx, t_scene *sn, void *obj)
{
	t_v3	v;

	v = ((t_cam*)sn->basecam->obj)->ver;
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
