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
	return (exp_ten - 1023);
}

int ft_get_integer(int *str, int exp, char **s)
{
	int i;
	int j;
	long int num;
	int two;

	i = exp;
	j = 0;
	num = 0;
	two = 2;
	while (i >= 0 && j <= exp)
	{
		num = num + ft_power(two, i)*str[j];
		i--;
		j++;
	}
	printf("this is integer %ld\n", num);
	return (num);
}

char *ft_convert_integer_to_string(long int num, char **s)
{
	int nb;
	int j;
	char *integer;

	nb = num;
	while (nb / 10 > 0)
		j++;
	if (!(integer = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	integer = ft_itoa(num);
	return (integer);
}

char	*ft_get_decimals(int *str, int exp, int precision, char **s)
{
	int i;
	int j;
	long int num;
	double num_d;
	int two;
	int ten;

	i = 1;
	j = exp + 1;
	num_d = 0.0;
	num = 0;
	two = 2;
	ten = 10;
	while (i < 53 - exp)
	{
		num_d = num_d + (double)(str[j])/(double)(ft_power(two, i));
		i++;
		j++;
	}
	num = ((double)(num_d*ft_power(ten, precision))+0.5);
	printf("this is decimals %ld\n", num);
//	ft_convert_decimals_to_string(num, precision);
	return (ft_itoa(num));
}

//char *ft_convert_decimals_to_string(long int num, int precision)
//{
//	char *str;
//
//	if (!(str = (char *)malloc(sizeof(char) * (precision + 1))))
//		return (0);
//	str = ft_itoa(num);
//	return (str);
//}

int ft_mantissa(const char *str, int precision)
{
	int i;
	int j;
	int *mantissa;
	int mantissa_ten;
	int exp;
	int len;
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
	ft_get_decimals(mantissa, exp, precision, &s);
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
	printf("%s\n", str);
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