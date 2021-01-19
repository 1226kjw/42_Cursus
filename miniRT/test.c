#include "mlx.h"
#include <stdio.h>

#define X 512
#define Y 512
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		exit_program()
{
	exit(0);
	return (0);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, X, Y, "Hello world!");
	img.img = mlx_new_image(mlx, X, Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("%s\n",img.addr);
	for(int i = 0; i < 512 ; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			unsigned int r = j/2;
			unsigned int g = 255 - i/2;
			unsigned int b = 64;

			my_mlx_pixel_put(&img, j, i, (r << 16) | (g << 8) | b);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
