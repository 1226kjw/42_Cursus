#include "libft.h"

char	*get_path(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp("PATH", envp[i], 4))
			return (envp[i] + 5);
	return (0);
}

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
