/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:08:30 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:49:48 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b;
	unsigned char	*c;
	size_t			a;

	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	a = 0;
	if (n == 0)
		return (0);
	while (a < n)
	{
		if (b[a] != c[a])
			return (b[a] - c[a]);
		a++;
	}
	return (0);
}
