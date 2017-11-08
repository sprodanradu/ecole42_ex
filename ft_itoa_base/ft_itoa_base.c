Write a function that converts an integer value to a null-terminated string using the specified base and stores the result in a char array that you must
allocate.
The base is expressed as an integer, from 2 to 16. The characters comprising the base are the digits from 0 to 9, followed by uppercase letter from A to F.
For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".
If base is 10 and value is negative, the resulting string is preceded with a minus sign (-). With any other base, value is always considered unsigned.
Your function must be declared as follows:
char	*ft_itoa_base(int value, int base);

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
	str = (char*)malloc(sizeof(char)*32); //longest string for absolut(min int) in base 2
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

void main()
{
	int n;
	int b;
	
	n = -1567;
	b = 8;
	printf("\n%d in baza %d = %s", n, b, ft_itoa_base(n,b));
}
