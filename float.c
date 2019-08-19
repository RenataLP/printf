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

int		ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= 48 && *str <= 57) && *str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	return (num * sign);
}

static int	convert_and_check_nb(char c, int base)
{
	int		result;

	if (c >= '0' && c <= '9')
		result = c - 48;
	else if (c >= 'a' && c <= 'z')
		result = c - 97 + 10;
	else if (c >= 'A' && c <= 'Z')
		result = c - 65 + 10;
	else
		result = -1;
	if (result < base && result != -1)
		return (result);
	else
		return (-1);
}

static int	length_number(char *str, int base)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (convert_and_check_nb(str[length], base) == -1)
			break ;
		length++;
	}
	return (length);
}

int			ft_atoi_base(char *nb, int base)
{
	int		result;
	int		length;

	if (base == 10)
		return (ft_atoi(nb));
	while (*nb == ' ' || *nb == '\t' || *nb == '\n'
			|| *nb == '\v' || *nb == '\r' || *nb == '\f')
		nb++;
	result = 0;
	length = length_number(nb, base) - 1;
	while (*nb && length >= 0 && convert_and_check_nb(*nb, base) != -1)
	{
		result += convert_and_check_nb(*nb, base) * ft_power(base, length);
		nb++;
		length--;
	}
	return (result);
}

static size_t	digit_count(long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int value, int base)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;
	int		sign;

	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	sign = 0;
	if (base == 10 && value < 0)
		sign = 1;
	if (value < 0)
		value = -value;
	if (value == 0)
		return ("0");
	tab_base = (char *)malloc(sizeof(char) * 17);
	tab_base = "0123456789ABCDEF";
	taille = digit_count(value, base);
	taille += (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}

int ft_exp(const char *str)
{
	int i;
	int j;
	char *exp;
	int exp_ten;//change type

	i = 1;
	j = 0;
	if (!(exp = (char *)malloc(sizeof(char) * 12)))
		return (0);
	while (i < 12)
		exp[j++] = str[i++];
	exp[j] = '\0';
	exp_ten = ft_atoi(ft_itoa_base(ft_atoi_base(exp,2), 10));
	printf("%d\n", exp_ten);
	return (exp_ten);
}

int

int ft_mantissa(const char *str)
{
	int i;
	int j;
	int *mantissa;
	int mantissa_ten;

	i = 12;
	j = 0;
	if (!(mantissa = (int *)malloc(sizeof(int) * 52)))
		return (0);
	while (str[i] != 0)
		mantissa[j++] = str[i++] - 48;
}

void	ft_float(double nb)
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
	ft_mantissa(str);
	printf("%s\n", str);
}

int main()
{
	double nb;

	nb = 8.9574629480;
	ft_float(nb);
}