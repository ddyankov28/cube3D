/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:36:13 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 16:16:52 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		d;

	d = 0;
	a = (char *)s;
	while (a[d] != '\0')
		d++;
	while (a[d] != (unsigned char)c && d > 0)
		d--;
	if (a[d] == (unsigned char)c)
		return ((char *)a + d);
	else
		return (NULL);
}
