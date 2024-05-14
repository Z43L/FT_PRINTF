/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:29:31 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/12 14:37:55 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_putchard(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putsrtd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

void	comstart(int *len, const char *format, va_list charmeleon, int i)
{
	if (format[i] == '%' && format[i + 1] != '%')
	{
		i++;
		if (format[i] == 'c')
			*len += ft_putchard(va_arg(charmeleon, int));
		else if (format[i] == 's')
			*len += ft_putsrtd(va_arg(charmeleon, char *), 1);
		else if (format[i] == 'd' || format[i] == 'i')
			*len += ft_putnbrd_base(va_arg(charmeleon, int), 10, 0, false);
		else if (format[i] == 'u')
			*len += ft_putnbrd_base(va_arg(charmeleon, unsigned int), 10, 0,
					false);
		else if (format[i] == 'x')
			*len += ft_putnbrd_base(va_arg(charmeleon, unsigned int), 16, 0,
					false);
		else if (format[i] == 'X')
			*len += ft_putnbrd_base(va_arg(charmeleon, unsigned int), 16, 0,
					true);
	}
}

void	secomp(const char *format, int i, int len, va_list charmeleon)
{
	void	*ptr;

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'p')
		{
			ptr = va_arg(charmeleon, void *);
			len += ft_putsrtd("0x", 1);
			len += ft_putnbrd_base((unsigned long)ptr, 16, 0, false);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			comstart(&len, format, charmeleon, i);
			i++;
		}
		else
			len += ft_putchard(format[i]);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	charmeleon;
	int		i;

	len = 0;
	i = 0;
	va_start(charmeleon, format);
	secomp(format, i, len, charmeleon);
	va_end(charmeleon);
	return (len);
}

/*int	main(void)
{
	char c = 'a';
	char str[] = "Hola, mundo!";
	void *ptr = &str;
	int i = 10;
	unsigned int u = 20;
	int x = 30;

	printf("Carácter: %c\n", c);
	printf("String: %s\n", str);
	printf("Puntero: %p\n", ptr);

	printf("Entero decimal: %d\n", i);
	printf("Entero decimal (otra forma): %i\n", i);
	printf("Entero sin signo: %u\n", u);

	printf("Hexadecimal en minúsculas: %x\n", x);
	printf("Hexadecimal en mayúsculas: %X\n", x);

	printf("Símbolo de porcentaje: %%\n");

	ft_printf("Carácter: %c\n", c);
	ft_printf("String: %s\n", str);
	ft_printf("Puntero: %p\n", ptr);

	ft_printf("Entero decimal: %d\n", i);
	ft_printf("Entero decimal (otra forma): %i\n", i);
	ft_printf("Entero sin signo: %u\n", u);

	ft_printf("Hexadecimal en minúsculas: %x\n", x);
	ft_printf("Hexadecimal en mayúsculas: %X\n", x);

	ft_printf("Símbolo de porcentaje: %%\n");

	return (0);
}*/