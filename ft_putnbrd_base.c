/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrd_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:10:37 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/11 19:26:20 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(long c, int len, int tof, int base)
{
	char	*hexmayus;
	char	*hexminus;

	hexmayus = "0123456789ABCDEF";
	hexminus = "0123456789abcdef";
	if (tof == 1)
		len += ft_putchard(hexmayus[c % base]);
	else if (tof == 0)
		len += ft_putchard(hexminus[c % base]);
	else
		len += ft_putchard(c % base + '0');
	return (len);
}

int	ft_putnbrd_base(long c, int base, int len, int tof)
{
	if (c < 0)
	{
		len += ft_putchard('-');
		c = -c;
	}
	if (c >= base)
		len = ft_putnbrd_base(c / base, base, len, tof);
	len = printnbr(c, len, tof, base);
	return (len);
}

int	ft_putchard(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putsrtd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putsrtd("(null)", 1);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				len;

	addr = (unsigned long)ptr;
	len = 0;
	len += ft_putsrtd("0x", 1);
	if (addr == 0)
		len += ft_putchard('0');
	else
		len += ft_putnbrd_base(addr, 16, 0, 0);
	return (len);
}
