/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:39:51 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:50:13 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dest;
	if (!src && !dest)
		return (NULL);
	if (a < b)
	{
		while (n > 0)
		{
			b[n - 1] = a[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(b, a, n);
	return (dest);
}
