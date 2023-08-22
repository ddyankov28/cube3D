/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:06:38 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:51:23 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countstrings(char const *s, char c)
{
	int	result;
	int	counter;

	result = 0;
	counter = 0;
	while (s[counter])
	{
		while (s[counter] == c)
			counter++;
		if (s[counter] != '\0')
			result++;
		while (s[counter] && s[counter] != c)
			counter++;
	}
	return (result);
}

static char	*cut_part(const char *s, int start, int end)
{
	char	*part;
	int		i;

	i = 0;
	part = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		part[i++] = s[start++];
	part[i] = '\0';
	return (part);
}

static void	add_to_result(char **result, const char *s, char c, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			result[j++] = cut_part(s, index, i);
			index = -2;
		}
		i++;
	}
	result[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((countstrings(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = -2;
	add_to_result(result, s, c, index);
	return (result);
}
