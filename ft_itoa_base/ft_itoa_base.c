/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:16:29 by exam              #+#    #+#             */
/*   Updated: 2017/10/05 16:56:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	test_base(int nb)
{
	char c;

	if (nb >= 0 && nb <= 9)
		c = nb + '0';
	else if (nb >= 10 && nb <= 16)
		c = 'A' - 10 + nb;
	else
		c = '\0';
	return (c);
}

int		modul(long int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int		ft_len(int n, int base)
{
	int len;
	int nr;
	int i;
	int b;
	
	b = n;
	nr = n;
	len = 0;
	if (n <= 0)
		len++;
	while (nr != 0)
		{
			len++;
			nr = modul(nr / base);
		}	
		if (base > 10)
		{
			i = -1;
			while (b !=  0)
			{
				if (modul(b % base) >= 10)
				{	
					i++;
				}
				b = modul(b / 10);
			}
			len = len - i;
		}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	int n;
	char *str;
	int len;
	char c;
	
	len = ft_len(value, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	len--;
	n = value;
	c = test_base(modul(n % base));
		while (n != 0 && c)
		{
			if (n < 0 && base == 10)
			{
				str[0] = '-';
			}
			if (n < 0 && base!= 10)
				len--;
			str[len] = c;
			n = modul(n / base);	
			len--;
			c = test_base(modul(n % base));
		}
	return (str);
}
