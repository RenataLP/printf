/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:45:18 by bkristle          #+#    #+#             */
/*   Updated: 2019/08/19 12:45:18 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

double	ft_get_depth(double nb, int *size)
{
	double depth;

	depth = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		depth *= 10;
	return (depth);
}

void	ft_get_integer(double *nb, char **str, int *i, double bit_depth)
{
	char *s;

	s = *str;
	while ((int)*nb != 0)
	{
		s[(*i)++] = (char)(*nb / bit_depth + 48);
		*nb = *nb - (int)(*nb / bit_depth) * bit_depth;
		bit_depth = bit_depth / 10;
	}
}

void	ft_get_decimals(double nb, char **str, int *i, int precision)
{
	int j;
	char *s;
	int tmp;

	s = *str;
	nb = nb * 10;
	s[(*i)++] = '.';
	j = 0;
	while (j < precision)
	{
		if ((int)nb == 0)
			s[(*i)++] = 0;
		else
		{
			if ((int)(nb) != 9)
			{
				nb = nb + 0.01;
				tmp = (int)nb;
			}
			else
				tmp = (int)(nb);
			s[(*i)++] = (char)(tmp + 48);
			nb = (nb - tmp)*10;
		}
		j++;
	}
}

int ft_check(double nb, char **str, int precision)
{
	int a;
	int b;

	a = nb;
	b = 1;
	while (precision-- > 0)
	{
		a = a * 10;
		b = b * 10;
	}
	if (((a + 1) % b) == 0)

}

char	ft_float_to_string(double nb, char **s, int precision)
{
	int		i;
	int		neg_sign;
	int		size;
	char	*str;
	double	bit_depth;

	size = 1;
	neg_sign = 0;
	if (nb < 0 && size++ && (neg_sign = 1) == 1)
		nb = -nb;
	bit_depth = ft_get_depth(nb, &size);
	size = size + precision;
	if (!(str = (char *)malloc(sizeof(char) * (size + 2))))
		return (0);
	i = 0;
	if (neg_sign == 1)
		str[i++] = '-';
//	if (ft_check(nb, &str, &i, precision) == 1)
//		...
	ft_get_integer(&nb, &str, &i, bit_depth);
	ft_get_decimals(nb, &str, &i, precision);
	str[i] = '\0';
	*s = str;
	return (size);
}

int main()
{
	double a;
	char *s;
	int precision;

	a = 9.99999999998600030083;
	precision = 3;
	ft_float_to_string(a, &s, precision);
	printf ("%s\n", s);
	printf ("%f", a);
	return (0);
}