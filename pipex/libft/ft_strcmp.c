#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		ret;
	int		idx;

	ret = 0;
	idx = 0;
	while (!ret && (s1[idx] || s2[idx]))
	{
		ret = (unsigned char)s1[idx] - (unsigned char)s2[idx];
		idx++;
	}
	return (ret);
}
