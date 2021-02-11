#include "minirt.h"

t_tr	*new_tr(t_v3 a, t_v3 b, t_v3 c, int color)
{
	t_tr	*ret;

	if (!(ret = (t_tr*)ft_calloc(1, sizeof(t_tr))))
		errmsg(0, "error:malloc\n");
	ret->a = a;
	ret->b = b;
	ret->c = c;
	ret->color = color;
	return (ret);
}

int		parsing_tr(char *buf, t_scene *sn)
{
	int		i;
	t_list	*no;
	t_tr	*tr;

	i = 2;
	tr = new_tr(ft_atov(buf, &i), ft_atov(buf, &i),
			ft_atov(buf, &i), ft_atoc(buf, &i));
	no = ft_lstnew((void*)tr);
	no->type = TR;
	ft_lstadd_back(&sn->objs, no);
	if (viseq(tr->a, tr->b) || viseq(tr->b, tr->c) || viseq(tr->c, tr->a))
		errmsg(sn, "there is at least one pair dup point on triangle");
	if (vinner(vsub(tr->a, tr->b), vsub(tr->c, tr->b)) ==
			fabs(vabs(vsub(tr->a, tr->b)) * vabs(vsub(tr->c, tr->b))))
		errmsg(sn, "3 points in line cannot make triangle");
	return (0);
}

int		issplit(t_v3 a, t_v3 b, t_v3 p, t_v3 q)
{
	t_v3	u;
	t_v3	v;

	u = vcross(vsub(b, a), vsub(p, a));
	v = vcross(vsub(b, a), vsub(q, a));
	if (vinner(u, v) < 0)
		return (1);
	return (0);
}

double	i_tr(t_ray ray, void *obj)
{
	t_pl	pl;
	t_tr	tr;
	double	t;
	t_v3	p;

	tr = *(t_tr*)obj;
	pl.o = tr.a;
	pl.n = vunit(vcross(vsub(tr.b, tr.a), vsub(tr.c, tr.a)));
	t = i_pl(ray, (void*)&pl);
	if (t < 0.0)
		return (-1.0);
	p = vadd(ray.o, vmul(ray.d, t));
	if (issplit(tr.a, tr.b, tr.c, p) || issplit(tr.b, tr.c, tr.a, p) ||
			issplit(tr.c, tr.a, tr.b, p))
		return (-1.0);
	return (t);
}

int		c_tr(void *obj)
{
	return (((t_tr*)obj)->color);
}