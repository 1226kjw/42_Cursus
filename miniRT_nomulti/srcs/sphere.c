#include "minirt.h"

t_sp	*new_sp(t_v3 o, double r, int color)
{
	t_sp	*ret;

	if (!(ret = (t_sp*)ft_calloc(1, sizeof(t_sp))))
		errmsg(0, "error:malloc\n");
	ret->o = o;
	ret->r = r;
	ret->color = color;
	return (ret);
}

int		parsing_sp(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;
	t_sp	*ns;

	i = 2;
	no = ft_lstnew(ns = new_sp(ft_atov(buf, &i),
				next_atof(buf, &i), ft_atoc(buf, &i)));
	no->type = SP;
	ft_lstadd_back(&sn->objs, no);
	if (((t_sp*)no->obj)->r <= 0)
		errmsg(sn, "valid radius : (0, inf)");
	return (0);
}

double	i_sp(t_ray ray, void *obj)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_sp ns=*(t_sp*)obj;
	t_v3	oc = vsub(ray.o, ns.o);
	a = vinner(ray.d, ray.d);
	b = vinner(ray.d, oc);
	c = vinner(oc, oc) - ns.r * ns.r;
	disc = b * b - a * c;
	if (disc <= 0)
		return (-1.0);
	disc = sqrt(disc);
	if ((-b - disc) / a >= 0)
		return ((-b - disc) / a);
	else if ((-b + disc) / a >= 0)
		return ((-b + disc) / a);
	else
		return (-1.0);
}

int		c_sp(void *obj)
{
	return (((t_sp*)obj)->color);
}
