/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 08:47:07 by bjeana            #+#    #+#             */
/*   Updated: 2021/11/03 15:00:38 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_lennbr(int n, int i);
char	*ft_itoa(int n);
int		ft_unlennbr(unsigned int n, int i);
char	*ft_unitoa(unsigned int n);
int		len_sixteen(unsigned int n);
char	*ft_sixteen(unsigned int n, char c);
int		len_psixteen(unsigned long long n);
char	*ft_psixteen(unsigned long long n);
int		ft_pr_c(char c);
int		ft_pr_s(char *s);
int		ft_pr_per(void);
int		ft_pr_di(int n);
int		ft_pr_u(unsigned int n);
int		ft_pr_x(unsigned int n, char c);
int		ft_pr_p(unsigned long long n);
int		ft_pr(va_list ap, char f);

#endif
