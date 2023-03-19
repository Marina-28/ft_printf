/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:26:50 by bjeana            #+#    #+#             */
/*   Updated: 2021/11/03 12:54:01 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_psixteen(unsigned long long n)
{
	unsigned long long	ost;
	int					i;

	i = 0;
	while (n > 15)
	{
		ost = n % 16;
		if (ost < 16 && ost > 9)
			i++;
		else
			i++;
		n = n / 16;
	}
	if (n > 9 && n < 16)
		i++;
	else
		i++;
	return ((i + 2));
}

char	*ft_psixteen(unsigned long long n)
{
	unsigned long long	ost;
	char				*nbr;
	int					i;

	i = len_psixteen(n);
	nbr = (char *)malloc((i + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[i] = '\0';
	while (n > 15)
	{
		ost = n % 16;
		if (ost < 16 && ost > 9)
			nbr[--i] = ost + 120 - 33;
		else
			nbr[--i] = ost + 48;
		n = n / 16;
	}
	if (n > 9 && n < 16)
		nbr[--i] = n + 120 - 33;
	else
		nbr[--i] = n + 48;
	nbr[--i] = 'x';
	nbr[--i] = '0';
	return (nbr);
}

int	ft_pr(va_list ap, char f)
{
	int	ret;

	ret = 0;
	if (f == 'c')
		ret = ret + ft_pr_c(va_arg(ap, int));
	else if (f == 's')
		ret = ret + ft_pr_s(va_arg(ap, char *));
	else if (f == '%')
		ret = ret + ft_pr_per();
	else if (f == 'd' || f == 'i')
		ret = ret + ft_pr_di(va_arg(ap, int));
	else if (f == 'u')
		ret = ret + ft_pr_u(va_arg(ap, unsigned int));
	else if (f == 'x' || f == 'X')
		ret = ret + ft_pr_x(va_arg(ap, unsigned int), f);
	else if (f == 'p')
		ret = ret + ft_pr_p(va_arg(ap, unsigned long long));
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	va_start(ap, fmt);
	i = 0;
	ret = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			ret = ret + ft_pr(ap, fmt[i]);
		}
		else
			ret = ret + ft_pr_c(fmt[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
