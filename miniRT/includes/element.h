#ifndef ELEMENT_H
# define ELEMENT_H

# include "minirt.h"

t_cam	*newcam(t_v3 o, t_v3 d, int fov);
t_light	*newlight(t_v3 o, double inten, int color);

#endif
