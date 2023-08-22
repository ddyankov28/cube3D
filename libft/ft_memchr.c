/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:38:43 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:49:37 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*a;
	unsigned char	symbol;

	a = (unsigned char *)s;
	symbol = (unsigned char)c;
	counter = 0;
	while (counter < n)
	{
		if (*a == symbol)
		{
			return (a);
		}
		a++;
		counter++;
	}
	return (NULL);
}
