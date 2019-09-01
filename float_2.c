#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int ft_exp(const char *str)
{
	int i;
	int j;
	char *exp;
	int exp_ten;

	i = 1;
	j = 0;
	if (!(exp = (char *)malloc(sizeof(char) * 12)))
		return (0);
	while (i < 12)
		exp[j++] = str[i++];
	exp[j] = '\0';
	exp_ten = ft_atoi(ft_itoa_base(ft_atoi_base(exp,2), 10));
	printf("%d\n", exp_ten);
	return (exp_ten - 1023);
}

int ft_get_integer_2(int *str, int exp, int *mas_int)
{
	int mas[5000];
	int i;

	i = 0;
	while (exp > 0)
	{

		i++;
	}
}

int ft_get_integer(int *str, int exp, char **s)
{
	int mas_int[5000];
	int j;
	int i;
	int res;

	j = 0;
	i = exp;
	while (j < 5000)
		mas_int[j++] = 0;
	res = 0;
	mas_int[0] = 1;
	while (i > 0)
	{
		j = 0;
		while (mas_int[j] != 0 || mas_int[j + 1] != 0)
			mas_int[j++] *= 2;
		j = 0;
		while (mas_int[j] != 0 || mas_int[j + 1] != 0)
		{
			if (mas_int[j] > 9)
			{
				res = mas_int[j];
				mas_int[j] %= 10;
				mas_int[j + 1] += res / 10;
			}
			j++;
		}
//		j = 0;
//		while (j < 99)
//			printf("%d", mas_int[j++]);
		i--;
//		printf("\n");
	}
	return (0);
}

int ft_mantissa(const char *str, int precision)
{
	int i;
	int j;
	int *mantissa;
	int exp;
	char *s;

	i = 12;
	j = 1;
	exp = ft_exp(str);
	if (!(mantissa = (int *)malloc(sizeof(int) * 53)))
		return (0);
	mantissa[0] = 1;
	while (str[i] != 0)
		mantissa[j++] = str[i++] - 48;
	ft_get_integer(mantissa, exp, &s);
//	ft_get_decimals(mantissa, exp, precision, &s);
	return (0);
}

void	ft_float(double nb, int precision)
{
	unsigned char *p;
	int i;
	char *str;
	int j;
	int a;

	i = 0;
	a = 63;
	p = ((unsigned char*)&nb);
	str = (char *)malloc(sizeof(char) * 65);
	str[64] = '\0';
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if ((1 << j++) & p[i])
				str[a] = '1';
			else
				str[a] = '0';
			a--;
		}
		i++;
	}
	ft_exp(str);
	ft_mantissa(str, precision);
//	printf("%s\n", str);
}

int main()
{
	double nb;
	int precision;

	nb = 5.995544;
	precision = 10;
	printf("%.10f\n", nb);
	ft_float(nb, precision);
}
