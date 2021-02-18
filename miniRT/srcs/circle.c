#include "minirt.h"

t_ci	*new_ci(t_v3 o, t_v3 n, double r, int color)
{
	t_ci	*nc;

	if (!(nc = (t_ci*)ft_calloc(1, sizeof(t_ci))))
		errmsg(0, "malloc");
	nc->o = o;
	nc->n = vunit(n);
	nc->r = r;
	nc->color = color;
	return (nc);
}

double	i_ci(t_ray r, void *obj)
{
	t_ci	c;
	t_pl	pl;
	double	t;
	t_v3	p;

	c = *(t_ci*)obj;
	pl.o = c.o;
	pl.n = vunit(c.n);
	t = i_pl(r, (void*)&pl);
	if (t < 0.0)
		return (-1.0);
	p = vadd(r.o, vmul(r.d, t));
	if (vabs(vsub(p, c.o)) <= c.r)
		return (t);
	return (-1.0);
}

int		c_ci(void *obj)
{
	return (((t_ci*)obj)->color);
}

t_v3	n_ci(t_hit hit)
{
	return (((t_ci*)hit.obj)->n);
}
