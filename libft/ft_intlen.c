#include "libft.h"

size_t	ft_intlen(int nb)
{
	size_t i;

	i = 1;
	while ((nb /= 10))
			i++;
	return (i);
}