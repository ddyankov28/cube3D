/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value_from_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:20:55 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 16:14:57 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_value_from_env(char **arr, char *varname)
{
	int	i;
	int	len;

	len = ft_strlen(varname);
	i = 0;
	while (arr[i])
	{
		if (!ft_strncmp(arr[i], varname, len) && arr[i][len] == '=')
			return (arr[i] + len + 1);
		i++;
	}
	return (NULL);
}
