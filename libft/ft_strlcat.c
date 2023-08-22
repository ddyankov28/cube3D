/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:11:09 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:52:23 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	index = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[index] && index < size)
		index++;
	while (src[counter] && (index + counter + 1) < size)
	{
		dst[index + counter] = src[counter];
		counter++;
	}
	if (index < size)
		dst[index + counter] = '\0';
	return (index + ft_strlen(src));
}
