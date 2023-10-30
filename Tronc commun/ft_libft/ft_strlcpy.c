#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	l;

	l = ft_strlen((char *)src);
	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return(l);
}

#include <stdio.h>

int	main()
{
	// printf("argv: %s\n", &*argv[i]);
	printf("ft_strlcpy: %zu\n", ft_strlcpy("aiheah", "azdnjazknd", 1));
	// printf("strlcpy: %lu\n", strlcpy("hello", " world", 5));
}