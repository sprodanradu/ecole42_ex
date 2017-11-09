#include<stdio.h>
#include<stdlib.h>

long long absolut(long long n)
{
	if (n < 0)
	{
		n = - n;
		return (n);
	}
	else
	{
		return (n);
	}
}

void ft_rev(char *str) //reverse string
{
	int start;
	int end;
	char temp;
	
	start = 0;
	end = 0;
	while (str[end])
	{
		end++;
	}
	end--;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char ft_itoa(int value) //integer to alpha
{
	char c;
	
	if (0 <= value && value <= 9)
	{
		c = value + '0';
	}
	else 
	{
		c = value + 55;
	}
	return (c);
}

char *ft_itoa_base(int value, int base)
{
	char *str;
	char c;
	int i;
	int n;
	long long value2;
	
	value2 = (long long)value;
	str = (char*)malloc(sizeof(char)*33); //longest string for absolut(min int) in base 2
	if (str == NULL)
	{
		return (0);
	}
	i = 0;
	if (value2 == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (value2 < 0)
	{
		value2 = absolut(value2);	
	}
	while (value2 > 0)
	{
		n = value2 % base;
		value2 = value2 / base;
		str[i] = ft_itoa(n);
		i++;
	}
	if (value < 0 && base == 10)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	ft_rev(str);
	return (str);
}
