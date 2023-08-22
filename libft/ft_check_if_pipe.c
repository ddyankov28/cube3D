/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:57:37 by ddyankov          #+#    #+#             */
/*   Updated: 2023/07/17 20:59:48 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_if_pipe(char **arr)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (arr[0][0] == '|')
		return (2);
	while (arr[i])
	{
		if (arr[i][0] == '|')
		{
			if (arr[i][1] == '|')
				return (2);
			else if (arr[i + 1][0] == '|')
				return (2);
			count++;
		}
		i++;
	}
	if (count > 0)
		return (1);
	return (0);
}
