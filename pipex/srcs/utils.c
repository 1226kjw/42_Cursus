#include "libft.h"

void	free_all(char **strs)
{
	int		i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

char	*ft_strjoin_3(char *str1, char *str2, char *str3)
{
	char	*tmp12;
	char	*tmp23;

	tmp12 = ft_strjoin(str1, str2);
	tmp23 = ft_strjoin(tmp12, str3);
	free(tmp12);
	return (tmp23);
}
