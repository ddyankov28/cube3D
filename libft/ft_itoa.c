/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:54:00 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:47:23 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digitlen(int n)
{
	int	digitlen;

	digitlen = 0;
	if (n == -2147483648)
		digitlen = 11;
	else if (n <= 0 && n > -2147483648)
	{
		n *= -1;
		digitlen++;
	}
	while (n > 0)
	{
		n = n / 10;
		digitlen++;
	}
	return (digitlen);
}

static char	*positive(char *s, int n)
{
	int	len;

	len = digitlen(n);
	while (n > 0)
	{
		s[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = digitlen(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = 48;
	else if (n == -2147483648)
	{
		s[0] = '-';
		s[1] = 2 + 48;
		positive(s + 2, 147483648);
	}
	else if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		positive(s + 1, n);
	}
	else
		positive(s, n);
	return (s);
}
