#ifndef IMAGES_H
# define IMAGES_H

# include "minirt.h"

void	args_set(t_data *mlx, t_scene *sn, t_cam *cam, t_arg *args);
void	*make_line_thread(void *p);
void	multithreading(t_arg *args);
void	my_pixel_put(t_cam *cam, int x, int y, int color);
void	make_img(t_data *mlx, t_scene *sn, t_arg *args);
t_hit	closest(t_ray ray, t_list *objs);

#endif