/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:02:23 by bjeana            #+#    #+#             */
/*   Updated: 2021/11/01 18:14:30 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pr_x(unsigned int n, char c)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_sixteen(n, c);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}

int	ft_pr_p(unsigned long long n)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_psixteen(n);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}
