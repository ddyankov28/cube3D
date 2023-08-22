/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_if_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:19:54 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/27 22:20:08 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len_if_single(char *str, int x)
{
	int	j;
	int	i;

	i = x;
	j = 1;
	i++;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			j++;
			break ;
		}
		j++;
		i++;
	}
	return (j);
}
