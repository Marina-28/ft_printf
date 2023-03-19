/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:25:12 by bjeana            #+#    #+#             */
/*   Updated: 2021/11/01 18:08:49 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_lennbr(int n, int i)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		i++;
		n = n * (-1);
		i = ft_lennbr(n, i);
	}
	else if (n >= 10)
	{
		i++;
		i = ft_lennbr((n / 10), i);
	}
	else
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*nbr;

	i = ft_lennbr(n, 0);
	nbr = (char *)malloc((i + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[i] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		if (n == -2147483648)
		{
			nbr[1] = '2';
			n = -147483648;
		}
		n = n * (-1);
	}
	while (n >= 10)
	{
		nbr[--i] = n % 10 + 48;
		n = n / 10;
	}
	nbr[--i] = n + 48;
	return (nbr);
}
