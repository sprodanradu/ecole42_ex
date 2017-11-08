#include<stdio.h>
#include<stdlib.h>

long long absolut(long long n)
{
	if (n < 0)
	{
		n = -1 * n;
		return (n);
	}
	else
	{
		return (n);
	}
}

void ft_rev(char *str)
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

char ft_itoa(int value)
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
	str = (char*)malloc(sizeof(char)*32); //longest string for max/min int in base 2
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

	printf("value2=%ld\n", value2);

	while (value2 > 0)
	{
		n = value2 % base;
		value2 = value2 / base;
		printf("%d ", n);
		str[i] = ft_itoa(n);
		printf("\nstr[%d]=%c ", i, str[i]);
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

void main()
{
	int n;
	int b;
	
	n = -1567;
	b = 8;
	printf("\n%d in baza %d = %s", n, b, ft_itoa_base(n,b));
}