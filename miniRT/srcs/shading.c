#include "minirt.h"

int		calc_diffuse(t_ray ray, t_hit hit, t_scene *sn)
{
	t_list	*cur;
	int		color;
	double	inten;
	t_v3	lp;

	color = 0;
	cur = sn->lights;
	while (cur)
	{
		lp = vsub(((t_light*)cur->obj)->p, hit.p);
		inten = vcos(hit.n, lp);
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
	return (0);
}
