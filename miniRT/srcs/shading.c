#include "minirt.h"

/*int		calc_diffuse(t_hit hit, t_scene *sn)
{
	t_list	*cur;
	int		color;
	double	inten;
	t_ray	lray;
	double	t;

	color = 0;
	cur = sn->lights;
	lray.o = hit.p;
	while (cur)
	{
		inten = 0;
		lray.d = vunit(vsub(((t_light*)cur->obj)->o, lray.o));
		lray.o = vadd(lray.o, vmul(lray.d, EPSILON));
		t = closest(lray, sn->objs).t;
		if (t > vabs(vsub(((t_light*)cur->obj)->o, hit.p)) || t <= 0)
			inten = vcos(hit.n, vsub(((t_light*)cur->obj)->o, hit.p));
		if (inten < 0)
			inten = 0;
		color = cadd(color, cmul(((t_light*)cur->obj)->color,
					((t_light*)cur->obj)->inten * inten));
		cur = cur->next;
	}
	return (color);
}*/

int		calc_diffuse(t_hit hit, t_light *cur)
{
	int		color;
	double	inten;

	inten =  vcos(hit.n, vsub(cur->o, hit.p));
	if (inten < 0)
		inten = 0;
	color = cmul(cur->color, cur->inten * inten);
	return (color);
}

/*int		calc_specular(t_ray ray, t_hit hit, t_scene *sn)
{
	t_list	*cur;
	int		color;
	double	i[2];
	t_ray	lray;
	t_v3	lp;

	color = 0;
	cur = sn->lights;
	lray.o = hit.p;
	while (cur)
	{
		i[0] = 0;
		lp = vunit(vsub(((t_light*)cur->obj)->o, hit.p));
		lray.d = vunit(vsub(((t_light*)cur->obj)->o, lray.o));
		lray.o = vadd(lray.o, vmul(lray.d, EPSILON));
		i[1] = closest(lray, sn->objs).t;
		if (i[1] > vabs(vsub(((t_light*)cur->obj)->o, hit.p)) || i[1] <= 0)
			i[0] = vinner(vunit(ray.d), vadd(lp, vmul(hit.n, -2 * vinner(lp, hit.n))));
		i[0] = i[0] < 0 ? 0 : pow(i[0], 32);
		color = cadd(color, cmul(((t_light*)cur->obj)->color,
					((t_light*)cur->obj)->inten * i[0]));
		cur = cur->next;
	}
	return (color);
}*/

int		calc_specular(t_ray ray, t_hit hit, t_light *cur)
{
	int		color;
	double	inten;
	t_v3	lp;

	lp = vunit(vsub(cur->o, hit.p));
	inten = vinner(vunit(ray.d),
			vunit(vadd(lp, vmul(hit.n, -2 * vinner(lp, hit.n)))));
	inten = inten < 0 ? 0 : pow(inten, 32);
	color = cmul(cur->color, cur->inten * inten);
	return (color);
}
