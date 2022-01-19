#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len--)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && haystack[i + j] != '\0' )
			{
				if (needle[j + 1] == '\0')
				{
					if (len < j)
						return (NULL);
					return ((char *)&haystack[i]);
				}
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

int	check_extension(const char *filepath)
{
	const char	*ext;
	size_t		ext_len;
	size_t		i;
	size_t		j;

	ext = ".ber";
	ext_len = ft_strlen(ext);
	i = 0;
	j = 0;
	if (ft_strlen(filepath) == ext_len)
		return (false);
	while (filepath[i] != '\0')
		i++;
	while (j < ext_len)
	{
		i--;
		j++;
	}
	if (ft_strncmp(filepath + i, ext, ext_len))
		return (false);
	return (true);
}

int main(int argc, char const *argv[])
{
	if(check_extension(argv[1]))
	{
		printf("true\n");
		exit(0);
	}
	printf("false\n");
	return 0;
}
