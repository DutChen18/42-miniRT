/* ************************************************************************** */
/*                                                                            */
/*                                                           :      .         */
/*   ft_tolower.c                                     -=-:::+*+:-+*#.         */
/*                                                :-:::+#***********----:     */
/*   By: csteenvo <csteenvo@student.codam.n>        .:-*#************#-       */
/*                                                 :=+*+=+*********####+:     */
/*   Created: 2022/05/10 11:58:40 by csteenvo     ..     +**=-=***-           */
/*   Updated: 2022/05/10 11:58:40 by csteenvo            :      ..            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch += 'a' - 'A';
	return (ch);
}
