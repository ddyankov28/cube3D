/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_if_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:14:48 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/27 22:16:53 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len_if_double(char *str, int x)
{
	int	j;
	int	i;

	i = x;
	j = 1;
	i++;
	while (str[i])
	{
		if (str[i] == '"')
		{
			j++;
			break ;
		}
		j++;
		i++;
	}
	return (j);
}
