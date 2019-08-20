/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:48:07 by bkristle          #+#    #+#             */
/*   Updated: 2019/08/20 15:48:07 by bkristle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H
#include <stdlib.h>
#include <stdio.h>
# include <unistd.h>
# include <string.h>

long int		ft_power(int nb, int power);
char	*ft_strdup(const char *s1);
static size_t	ft_length(int nbr);
char			*ft_itoa(int n);
int	ft_atoi(const char *str);
int			ft_atoi_base(char *nb, int base);
static size_t	digit_count(long nb, int base);
char			*ft_itoa_base(int value, int base);


#endif
