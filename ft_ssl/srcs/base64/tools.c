#include "ft_ssl.h"

unsigned char *ft_realloc_base64(void *s1, size_t len1, size_t len2)
{
	unsigned char	*str;

	if (!(str = ft_memalloc(len1 + len2 + 1)))
		return (NULL);
	if (len1)
	{
		ft_memcpy(str, s1, len1);
		free(s1);
	}
	return (str);
}