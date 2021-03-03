/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinukim <jinukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:46:09 by jinukim           #+#    #+#             */
/*   Updated: 2021/02/21 16:48:50 by jinukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		create_file(char *name)
{
	int		i;
	char	*bmp;

	bmp = (char*)ft_calloc(ft_strlen(name) + 6, sizeof(char));
	ft_strcpy(bmp, "./images/");
	ft_strlcat(bmp, name + 5, 0xffffffff);
	i = 1;
	while (bmp[i] && bmp[i] != '.')
		i++;
	if (bmp[i] == 0)
		errmsg(0, "file format error");
	bmp[i + 1] = 'b';
	bmp[i + 2] = 'm';
	bmp[i + 3] = 'p';
	bmp[i + 4] = 0;
	i = open(bmp, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	free(bmp);
	return (i);
}

t_bmph	create_bmph(void)
{
	t_bmph	h;

	ft_memset(&h, 0x00, sizeof(t_bmph));
	h.type[0] = 'B';
	h.type[1] = 'M';
	h.size_f = 4 * g_x * g_y + 54;
	h.offset = 54;
	h.size_d = 40;
	h.width = g_x;
	h.height = -g_y;
	h.planes = 1;
	h.bpp = 32;
	h.size_i = 4 * g_x * g_y;
	return (h);
}

void	write_bmph(int fd, t_bmph h)
{
	write(fd, &h.type, 2);
	write(fd, &h.size_f, 4);
	write(fd, &h.reserved, 4);
	write(fd, &h.offset, 4);
	write(fd, &h.size_d, 4);
	write(fd, &h.width, 4);
	write(fd, &h.height, 4);
	write(fd, &h.planes, 2);
	write(fd, &h.bpp, 2);
	write(fd, &h.comp, 4);
	write(fd, &h.size_i, 4);
	write(fd, &h.x_ppm, 4);
	write(fd, &h.y_ppm, 4);
	write(fd, &h.color, 4);
	write(fd, &h.cimp, 4);
}

void	write_file(int fd, t_scene *sn)
{
	int		i;
	int		j;
	int		size;
	char	*buf;
	int		*c;

	size = g_x * g_y;
	c = (int*)((t_cam*)sn->basecam->obj)->addr;
	if (!(buf = (char*)ft_calloc(((t_cam*)sn->basecam->obj)->lsize * g_y,
					sizeof(char))))
		errmsg(sn, "malloc");
	i = 0;
	j = 0;
	while (i < size)
	{
		buf[j++] = cblue(c[i]);
		buf[j++] = cgreen(c[i]);
		buf[j++] = cred(c[i]);
		buf[j++] = 0;
		i++;
	}
	write(fd, buf, ((t_cam*)sn->basecam->obj)->lsize * g_y);
	free(buf);
}

void	save_file(char *name, t_scene *sn)
{
	int		fd;
	t_bmph	bmph;

	if ((fd = create_file(name)) <= 0)
		errmsg(sn, "cannot create file");
	bmph = create_bmph();
	printf("create\n");
	write_bmph(fd, bmph);
	printf("bmph\n");
	write_file(fd, sn);
	printf("end\n");
	errmsg(sn, 0);
}
