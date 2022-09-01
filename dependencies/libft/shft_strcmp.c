/* ************************************************************************** */
/*                                                                            */
/*                                                           :      .         */
/*   shft_strcmp.c                                    -=-:::+*+:-+*#.         */
/*                                                :-:::+#***********----:     */
/*   By: csteenvo <csteenvo@student.codam.n>        .:-*#************#-       */
/*                                                 :=+*+=+*********####+:     */
/*   Created: 2022/05/10 11:58:52 by csteenvo     ..     +**=-=***-           */
/*   Updated: 2022/05/10 11:58:52 by csteenvo            :      ..            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_strcmp(const char *str1, const char *str2)
{
	return (ft_memcmp(str1, str2, ft_strlen(str1) + 1));
}