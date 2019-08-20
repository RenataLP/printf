/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:47:11 by bkristle          #+#    #+#             */
/*   Updated: 2019/08/20 15:47:11 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int		ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * len);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static size_t	ft_length(int nbr)
{
	int n;

	n = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		n = 1;
	}
	while (nbr > 0)
	{
		n++;
		nbr = nbr / 10;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	length;

	length = ft_length(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((str = (char *)malloc(sizeof(char) * (length + 1))) == NULL)
		return (NULL);
	str[length--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[length--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
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