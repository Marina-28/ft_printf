/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:00:03 by bjeana            #+#    #+#             */
/*   Updated: 2021/11/01 18:12:57 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_c(char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_pr_s(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	ft_putstr(s);
	i = ft_strlen(s);
	return (i);
}

int	ft_pr_per(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_pr_di(int n)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_itoa(n);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}

int	ft_pr_u(unsigned int n)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_unitoa(n);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}
