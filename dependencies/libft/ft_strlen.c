/* ************************************************************************** */
/*                                                                            */
/*                                                           :      .         */
/*   ft_strlen.c                                      -=-:::+*+:-+*#.         */
/*                                                :-:::+#***********----:     */
/*   By: csteenvo <csteenvo@student.codam.n>        .:-*#************#-       */
/*                                                 :=+*+=+*********####+:     */
/*   Created: 2022/05/10 11:58:36 by csteenvo     ..     +**=-=***-           */
/*   Updated: 2022/05/10 11:58:36 by csteenvo            :      ..            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len += 1;
	return (len);
}
