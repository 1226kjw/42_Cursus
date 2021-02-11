#include "minirt.h"

t_v3	vset(double x, double y, double z)
{
	t_v3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_v3	vadd(t_v3 a, t_v3 b)
{
	return (vset(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_v3	vsub(t_v3 a, t_v3 b)
{
	return (vset(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_v3	vmul(t_v3 a, double c)
{
	return (vset(a.x * c, a.y * c, a.z * c));
}

double	vinner(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vabs(t_v3 a)
{
	return (sqrt(vinner(a, a)));
}

t_v3	vcross(t_v3 a, t_v3 b)
{
	return (vset(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x));
}

t_v3	vunit(t_v3 a)
{
	if (a.x == 0.0 && a.y == 0.0 && a.z == 0.0)
		return (a);
	return (vmul(a, 1.0 / vabs(a)));
}

t_v3	vnorm(t_v3 a)
{
	if (a.x == 0.0 && a.y == 0.0)
		return (vset(1.0, 0.0, 0.0));
	else
		return (vunit(vcross(a, vset(0.0, 0.0, 1.0))));
}

int		viseq(t_v3 a, t_v3 b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}
