/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:01:41 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:54:08 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	char	*b;
	int		counter;
	int		index;

	b = (char *)big;
	counter = 0;
	if (big == 0 && len == 0)
		return (NULL);
	if ((ft_strlen(little) == 0 && ft_strlen(big) == 0)
		|| ft_strlen(little) == 0)
		return (b);
	if (ft_strlen(big) == 0)
		return (NULL);
	while (big[counter] != '\0' && counter < len)
	{
		index = 0;
		while (little[index] != '\0' && counter + index < len
			&& big[counter + index] == little[index])
			index++;
		if (index == ft_strlen(little))
			return (b + counter);
		counter++;
	}
	return (NULL);
}
