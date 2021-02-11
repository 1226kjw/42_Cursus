#ifndef OBJECT_H
# define OBJECT_H

# include "minirt.h"

double	i_sp(t_ray ray, void *obj);
double	i_pl(t_ray ray, void *obj);
double	i_sq(t_ray ray, void *obj);
double	i_cy(t_ray ray, void *obj);
double	i_tr(t_ray ray, void *obj);
int		c_sp(void *obj);
int		c_pl(void *obj);
int		c_sq(void *obj);
int		c_cy(void *obj);
int		c_tr(void *obj);

#endif