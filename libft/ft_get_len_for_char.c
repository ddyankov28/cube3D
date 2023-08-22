/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_for_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:25:55 by vstockma          #+#    #+#             */
/*   Updated: 2023/06/28 17:54:33 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len_for_char(char *str, char c, int i)
{
	while (str[i])
	{
		if (str[i] != c)
			break ;
		i++;
	}
	return (i);
}
