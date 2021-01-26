#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_ray
{
	t_vec		pos;
	t_vec		dir;
}				t_ray;

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			bytes_per_line;
	int			endian;
}				t_data;

typedef struct	s_cam
{
	t_vec		pos;
	t_vec		dir;
	int			fov;
}				t_cam;

typedef struct	s_light
{
	t_vec		pos;
	t_vec		color;
	double		brightness;
}				t_light;

typedef struct	s_sphere
{
	t_vec		pos;
	t_vec		color;
	double		r;
}				t_sphere;

typedef struct	s_scene
{
	int			x;
	int			y;
	t_vec		hor;
	t_vec		ver;
	int			ncam;
	int			nlight;
	int			nsphere;
	t_cam		cam[MAXCAM];
	t_light		light[MAXLIGHT];
	t_sphere	sphere[MAXSPHERE];
}				t_scene;

#endif
