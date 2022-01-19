/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:32:26 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/19 18:07:39 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		i;
	size_t		len;
	char		*dest;

	if (src == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
