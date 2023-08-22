/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:04:10 by ddyankov          #+#    #+#             */
/*   Updated: 2023/06/28 17:50:53 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexa(unsigned int n, int *len, char c)
{
	if (n < 16)
	{
		if (c == 'x')
			ft_putchar("0123456789abcdef"[n], len);
		else if (c == 'X')
			ft_putchar("0123456789ABCDEF"[n], len);
	}
	else if (n >= 16)
	{
		ft_hexa(n / 16, len, c);
		ft_hexa(n % 16, len, c);
	}
}

void	ft_pointer_hexa(unsigned long long n, int *len)
{
	if (n < 16)
	{
		ft_putchar("0123456789abcdef"[n], len);
	}
	else
	{
		ft_pointer_hexa(n / 16, len);
		ft_pointer_hexa(n % 16, len);
	}
}

void	ft_pointer(void *ptr, int *len)
{
	unsigned long long	n;

	if (!ptr)
		ft_putstr("(nil)", len);
	else
	{
		n = (unsigned long long)ptr;
		ft_putchar('0', len);
		ft_putchar('x', len);
		ft_pointer_hexa(n, len);
	}
}

void	ft_format_spec(char c, int *len, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	if (c == 'u')
		ft_pos_nbr(va_arg(args, unsigned int), len);
	if (c == 'p')
		ft_pointer(va_arg(args, void *), len);
	if (c == 'x' || c == 'X')
		ft_hexa(va_arg(args, int), len, c);
	if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *f, ...)
{
	int		len;
	int		c;
	va_list	args;

	len = 0;
	c = 0;
	va_start(args, f);
	while (f && f[c])
	{
		if (f[c] == '%')
		{
			c++;
			ft_format_spec(f[c], &len, args);
		}
		else
			ft_putchar(f[c], &len);
		c++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{	
	char 	*s = NULL;
	printf("%d\n",printf("qsd%s", s));
	printf("%d\n",ft_printf("qsd%s",s));
	//printf("%p", p);
	//ft_printf("%p", r);
	//printf("%d\n",printf("Dey%s%cN%c", "FFF", 'U', 'E'));
	//printf("%d\n",ft_printf("Dey%s%cN%c","FFF",'U', 'E'));
	//printf("ORIGINAL LÄNGE  %d\n",printf("%ld\n",-2147483648));
	//printf("MEINE LÄNGE IST %d\n",ft_printf("%d\n",-2147483648));
	//printf("%d\n",printf("DDDD\n"));
	return (0);
}*/
