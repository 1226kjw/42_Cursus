#include "minirt.h"

t_cam	*newcam(t_v3 o, t_v3 d, int fov)
{
	t_cam	*nc;

	nc = (t_cam*)ft_calloc(1, sizeof(t_cam));
	nc->o = o;
	nc->d = d;
	nc->fov = fov;
	nc->hor = vnorm(d);
	nc->ver = vunit(vcross(d, nc->hor));
	nc->hor = vmul(nc->hor, 2 * vabs(d) * tan(M_PI * fov / 360.0));
	nc->ver = vmul(nc->ver, vabs(nc->hor) * (double)g_y / (double)g_x);
	nc->hl = vsub(d, vadd(vmul(nc->hor, 0.5), vmul(nc->ver, 0.5)));
	printf("%lf %lf %lf, %lf %lf %lf\n",nc->hor.x,nc->hor.y,nc->hor.z,nc->ver.x,nc->ver.y,nc->ver.z);
	printf("%lf %lf %lf\n",nc->hl.x,nc->hl.y,nc->hl.z);
	return (nc);
}

t_light	*newlight(t_v3 o, double inten, int color)
{
	t_light	*nl;

	nl = (t_light*)ft_calloc(1, sizeof(t_light));
	nl->o = o;
	nl->inten = inten;
	nl->color = color;
	return (nl);
}
