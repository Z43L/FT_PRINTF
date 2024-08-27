/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:55 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/11 19:42:22 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	comstart(int *len, const char *format, va_list charmeleon, int i);
void	handle_pointer(int *len, va_list charmeleon);
int		setres(const char *format, int *i, int len, va_list charmeleon);
int		ft_putchard(char c);
int		ft_putsrtd(char *s, int fd);
int		ft_putnbrd_base(long c, int base, int len, int tof);
int		ft_putptr(void *ptr);

#endif