#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (!c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_new;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_new = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc((len_new + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		new[i] = (s1)[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		new[ft_strlen(s1) + i] = (s2)[i];
		i++;
	}
	new[len_new] = '\0';
	return (new);
}

void ft_free_ptr(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
