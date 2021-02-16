#include "minirt.h"

int		calc_diffuse(t_hit hit, t_scene *sn)
{
	t_list	*cur;
	int		color;
	double	inten;
	t_ray	lray;

	color = 0;
	cur = sn->lights;
	lray.o = hit.p;
	while (cur)
	{
		inten = 0;
		lray.d = vsub(((t_light*)cur->obj)->o, lray.o);
		lray.o = vadd(lray.o, vmul(lray.d, EPSILON));
		if (closest(lray, sn->objs).t <= 0)
			inten = vcos(hit.n, vsub(((t_light*)cur->obj)->o, hit.p));
		if (inten < 0)
			inten = 0;
		color = cadd(color, cmul(((t_light*)cur->obj)->color,
					((t_light*)cur->obj)->inten * inten));
		cur = cur->next;
	}
	return (color);
}

int		calc_specular(t_ray ray, t_hit hit, t_scene *sn)
{
	t_list	*cur;
	int		color;
	double	inten;
	t_ray	lray;
	t_v3	lp;

	color = 0;
	cur = sn->lights;
	lray.o = hit.p;
	while (cur)
	{
		inten = 0;
		lp = vunit(vsub(((t_light*)cur->obj)->o, hit.p));
		lray.d = vsub(((t_light*)cur->obj)->o, lray.o);
		lray.o = vadd(lray.o, vmul(lray.d, EPSILON));
		if (closest(lray, sn->objs).t <= 0)
			inten = vinner(vunit(ray.d), vadd(lp, vmul(hit.n, -2 * vinner(lp, hit.n))));
		inten = inten < 0 ? 0 : pow(inten, 32);
		color = cadd(color, cmul(((t_light*)cur->obj)->color,
					((t_light*)cur->obj)->inten * inten));
		cur = cur->next;
	}
	return (color);
}
