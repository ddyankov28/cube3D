/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:08:58 by vstockma          #+#    #+#             */
/*   Updated: 2023/10/09 13:04:19 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	j = 0;
	if (!c)
		return (1);
	while (str[i])
	{
		if (str[i] != c)
		{
			j++;
			count++;
			i++;
		}
		while (str[i] && str[i] != c && j > 0)
			i++;
		while (str[i] == c)
			i++;
		j = 0;
	}
	return (count);
}

static char	*ft_word(const char *str, char c, int i)
{
	char	*word;
	int		j;
	int		count;
	int		temp;

	j = 0;
	temp = i;
	count = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		count++;
	}
	word = malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);
	while (j < count)
	{
		word[j] = str[temp];
		j++;
		temp++;
	}
	word[j] = '\0';
	return (word);
}

static char	**finalstr(char **str, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ft_word(s, c, i);
			if (!str[j])
				return (NULL);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		arrlen;

	if (!s)
		return (NULL);
	arrlen = ft_wordcount(s, c);
	str = malloc(sizeof(char *) * (arrlen + 1));
	if (!str)
		return (NULL);
	return (finalstr(str, s, c));
}

/*int	main(void)
{
	const char	s[] = " Hallo56 Bro was geht ? ";
	char	c = ' ';
	int	i;
	char	**str;

	i = 0;
	str = ft_split(s, c);
	while (i < 5)
	{
		printf("%s", str[i]);
		i++;
	}
	return (0);
}*/
