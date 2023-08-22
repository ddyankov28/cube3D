/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:30:19 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:52:48 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*b;
	unsigned char	*c;
	size_t			a;

	b = (unsigned char *) s1;
	c = (unsigned char *) s2;
	a = 0;
	while (b[a] == c[a] && b[a] != '\0' && c[a] != '\0' && a < n)
	{
		a++;
	}
	if (a == n)
		return (0);
	return (b[a] - c[a]);
}
