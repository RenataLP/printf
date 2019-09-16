/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:17:20 by bkristle          #+#    #+#             */
/*   Updated: 2019/08/19 16:17:20 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	*ft_reverse(int *str, int nb, int nb_nul)
{
	int i;
	int *rev_str;
	int j;

	j = 0;
	i = nb - nb_nul;
	if (!(rev_str = (int *)malloc(sizeof(int) * i)))
		return (0);
	while (i > 0)
	{
		rev_str[j] = str[i - 1];
		i--;
		j++;
	}
//	j = 0;
//	while (rev_str[j])
//		printf("%d", rev_str[j++]);
	return(rev_str);
}

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

int *ft_division(int *integer, int divider)
{

}

int ft_get_int(int *integer, int *str, int exp, int nb)
{
	int j;
	int sum[5000];
	int i;
	int res;

	j = 0;
	res = 0;
	while (i < 5000)
		sum[i++] = 0;// check
	while (j <= exp)
	{
		i = 0;
		if (str[j] == 0)
			j++;
		else
			while (i <= nb)
				sum[i++] += integer[i];
		i = 0;
		while (integer[j][i] != 0 || integer[j][i + 1] != 0)
		{
			if (sum[i] > 9)
			{
				res = sum[i];
				sum[i] %= 10;
				sum[i + 1] += res / 10;
			}
			i++;
		}
		j++;
	}
	i = 0;
	while (i < 100)
		printf("%d", sum[i++]);
	return (0);
}

int ft_get_integer(int *str, int exp, char **s)
{
	int mas_int[5000];
	int j;
	int i;
	int res;

	j = 0;
	i = exp;
	res = 0;
	while (j < 5000)
		mas_int[j++] = 0;
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
		i--;
	}
	ft_get_int(*ft_reverse(mas_int, 5000, 5000 - j), mantissa, exp, 5000 - j);
	return (0);
}

int	ft_get_decimals(int *str, int precision, char **s)
{
	int mas_dec[5000];
	int j;
	int i;
	int res;

	j = 0;
	i = precision;
	while (j < 5000)
		mas_dec[j++] = 0;
	res = 0;
	mas_dec[0] = 1;
	while (i > 0)
	{
		j = 0;
		while (mas_dec[j] != 0 || mas_dec[j + 1] != 0)
			mas_dec[j++] *= 5;
		j = 0;
		while (mas_dec[j] != 0 || mas_dec[j + 1] != 0)
		{
			if (mas_dec[j] > 9)
			{
				res = mas_dec[j];
				mas_dec[j] %= 10;
				mas_dec[j + 1] += res / 10;
			}
			j++;
		}

		j = 0;
		while (j < 99)
			printf("%d", mas_dec[j++]);
		i--;//оставить все остальное убрать
		printf("\n");
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
	ft_get_decimals(mantissa, precision, &s);
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

	nb = 16.995544;
	precision = 2;
	printf("%.10f\n", nb);
	ft_float(nb, precision);
}