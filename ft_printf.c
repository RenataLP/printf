/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:46:11 by bkristle          #+#    #+#             */
/*   Updated: 2019/06/30 16:46:11 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char i;

//	if (nb == -2147483648)
//		ft_putchar("-2147483648");
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

//typedef union	t_f
//{
//	double		n;
//	struct		s_f
//	{
//		unsigned long m:52;
//		unsigned int e:11;
//		unsigned int s:1;
//	}			t_ma;
//}				u_f;//для определения мантиссы,

int	ft_printf(const char * restrict format, ...)
{
	char *traverse;
	int i;
	char *s;

	va_list arg;
	va_start(arg, format);
	traverse = (char *)format;
	while (*traverse != '\0')
	{
		write (1, &(*traverse), 1);
		traverse++;
		if (*traverse == '%')
		{
			traverse++;
			if (traverse == 'c')
			{
				i = va_arg(arg, int);
				ft_putchar(i);
				traverse++;
			}
			else if (*traverse == 'd' || *traverse == 'i')
			{
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = -i;
					ft_putchar('-');
				}
				ft_putnbr(i);
				traverse++;
			}
			else if (*traverse == 'f')
			{

			}
		}
		if (*traverse == '\n')
		{
			ft_putchar('\n');
			traverse++;
		}
	}
	va_end(arg);
	return (0);
}

int main()
{
	char a = 'p';
	int b = 12345;
	ft_printf("Hi %i JJ\n", b);
	printf("Hi %10d JJ\n", b);
//	ft_printf("%d", b);
	return (0);
}
