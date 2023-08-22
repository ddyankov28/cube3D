/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:11:04 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:53:02 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*news;
	int		s1len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1len = ft_strlen(s1);
	while (s1len && ft_strchr(set, s1[s1len]))
		s1len--;
	news = ft_substr((char *) s1, 0, (s1len + 1));
	return (news);
}
