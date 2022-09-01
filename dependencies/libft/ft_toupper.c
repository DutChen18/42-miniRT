/* ************************************************************************** */
/*                                                                            */
/*                                                           :      .         */
/*   ft_toupper.c                                     -=-:::+*+:-+*#.         */
/*                                                :-:::+#***********----:     */
/*   By: csteenvo <csteenvo@student.codam.n>        .:-*#************#-       */
/*                                                 :=+*+=+*********####+:     */
/*   Created: 2022/05/10 11:58:41 by csteenvo     ..     +**=-=***-           */
/*   Updated: 2022/05/10 11:58:41 by csteenvo            :      ..            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		ch += 'A' - 'a';
	return (ch);
}