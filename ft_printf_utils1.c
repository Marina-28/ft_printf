/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:57:34 by bjeana            #+#    #+#             */
/*   Updated: 2021/11/01 18:11:25 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unlennbr(unsigned int n, int i)
{
	if (n >= 10)
	{
		i++;
		i = ft_lennbr((n / 10), i);
	}
	else
		i++;
	return (i);
}

char	*ft_unitoa(unsigned int n)
{
	int		i;
	char	*nbr;

	i = ft_unlennbr(n, 0);
	nbr = (char *)malloc((i + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[i] = '\0';
	i--;
	while (n >= 10)
	{
		nbr[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	nbr[i] = n + 48;
	return (nbr);
}

int	len_sixteen(unsigned int n)
{
	unsigned int	ost;
	int				i;

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
	return (i);
}

char	*ft_sixteen(unsigned int n, char c)
{
	unsigned int	ost;
	char			*nbr;
	int				i;

	i = len_sixteen(n);
	nbr = (char *)malloc((i + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[i] = '\0';
	while (n > 15)
	{
		ost = n % 16;
		if (ost < 16 && ost > 9)
			nbr[--i] = ost + c - 33;
		else
			nbr[--i] = ost + 48;
		n = n / 16;
	}
	if (n > 9 && n < 16)
		nbr[--i] = n + c - 33;
	else
		nbr[--i] = n + 48;
	return (nbr);
}
