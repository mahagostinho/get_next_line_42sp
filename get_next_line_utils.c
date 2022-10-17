/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:39:27 by marcarva          #+#    #+#             */
/*   Updated: 2022/10/14 20:41:51 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
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

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr == NULL)
		return (NULL);
	while (*(s + i))
	{
		*(ptr + i) = *(s + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
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
	free((char *)s1);
	return (new);
}
