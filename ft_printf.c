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

#include "ft_printf.h"

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
			*len += ft_putnbrd_base(va_arg(charmeleon, int), 10, 0, 0);
		else if (format[i] == 'u')
			*len += ft_putnbrd_base(va_arg(charmeleon, unsigned int), 10, 0, 0);
		else if (format[i] == 'x')
			*len += ft_putnbrd_base(va_arg(charmeleon, unsigned int), 16, 0, 0);
		else if (format[i] == 'X')
			*len += ft_putnbrd_base(va_arg(charmeleon, unsigned int), 16, 0, 1);
	}
}

void	handle_pointer(int *len, va_list charmeleon)
{
	void	*ptr;

	ptr = va_arg(charmeleon, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*len += 5;
	}
	else
	{
		*len += ft_putptr(ptr);
	}
}

int	setres(const char *format, int *i, int len, va_list charmeleon)
{
	if (format[*i] == '%' && format[*i + 1] == 'p')
	{
		handle_pointer(&len, charmeleon);
		(*i)++;
	}
	else if (format[*i] == '%' && format[*i + 1] == '%')
	{
		len += ft_putchard('%');
		(*i)++;
	}
	else if (format[*i] == '%' && format[*i + 1] != '%')
	{
		comstart(&len, format, charmeleon, *i);
		(*i)++;
	}
	return (len);
}

int	secomp(const char *format, int i, int len, va_list charmeleon)
{
	while (format[i])
	{
		if (format[i] == '%')
			len = setres(format, &i, len, charmeleon);
		else
			len += ft_putchard(format[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	charmeleon;
	int		i;

	len = 0;
	i = 0;
	va_start(charmeleon, format);
	len = secomp(format, i, len, charmeleon);
	va_end(charmeleon);
	return (len);
}

/* int main(void)
{
	int				number;
	int				cero_number;
	int				negative_number;
	int				hexadecimal_number;
	int				negative_hexadecimal_number;
	int				min_number;
	int				max_number;
	unsigned int	unsigned_number;
	char			simple_char;
	char			especial_char;
	char			*string;
	char			*empty_string;
	void			*pointer;
	char			*NULL_string;
	int				test;
	void			*ptr;
	int				i;
	int				j;

	// variables
	number = 123;
	cero_number = 0;
	negative_number = -123;
	hexadecimal_number = 1000;
	negative_hexadecimal_number = -1000;
	min_number = -2147483648;
	max_number = 2147483647;
	unsigned_number = 123;
	simple_char = '0';
	especial_char = '@';
	string = "Hola Mundo";
	empty_string = "";
	pointer = &string;
	NULL_string = "";
	// original printf
	printf("Original Printf:\n");
	printf("\n");
	printf("%i \n",printf("= %i\n", number));
	printf("%i \n",printf("= %i\n", cero_number));
	printf("%i \n",printf("= %i\n", negative_number));
	printf("%i \n",printf("= %i\n", min_number));
	printf("%i \n",printf("= %d\n", max_number));
	printf("%i \n",printf("= %u\n", unsigned_number));
	printf("%i \n",printf("= %x\n", hexadecimal_number));
	printf("%i \n",printf("= %x\n", negative_hexadecimal_number));
	printf("%i \n",printf("= %X\n", hexadecimal_number));
	printf("%i 	\n",printf("= %X\n", negative_hexadecimal_number));
	printf("%i \n",printf("= %c\n", simple_char));
	printf("%i \n",printf("= %c\n", especial_char));
	printf("%i \n",printf("= %s\n", string));
	printf("%i \n",printf("= %s\n", empty_string));
	printf("%i \n",printf("= %p\n", pointer));
	printf("%i \n",printf("= %s\n", NULL_string));
	printf("%i \n",printf("\n"));
	// my ft_printf
	printf("My Ft_Printf:\n");
	printf("\n");
	printf("%i \n",ft_printf("= %i\n", number));
	printf("%i \n",ft_printf("= %i\n", cero_number));
	printf("%i \n",ft_printf("= %i\n", negative_number));
	printf("%i \n",ft_printf("= %i\n", min_number));
	printf("%i \n",ft_printf("= %d\n", max_number));
	printf("%i \n",ft_printf("= %u\n", unsigned_number));
	printf("%i \n",ft_printf("= %x\n", hexadecimal_number));
	printf("%i \n",ft_printf("= %x\n", negative_hexadecimal_number));
	printf("%i \n",ft_printf("= %X\n", hexadecimal_number));
	printf("%i \n",ft_printf("= %X\n", negative_hexadecimal_number));
	printf("%i \n",ft_printf("= %c\n", simple_char));
	printf("%i \n",ft_printf("= %c\n", especial_char));
	printf("%i \n",ft_printf("= %s\n", string));
	printf("%i \n",ft_printf("= %s\n", empty_string));
	printf("%i \n",ft_printf("= %p\n", pointer));
	printf("%s\n", NULL_string);
	printf("\n\n");
	ptr = &test;
	printf("%i \n",ft_printf("Hola Mundo, 658 %p, %s, %s, %%, %c, %d, %i, %u, 
			%x, %X\n", ptr, "", "hola", 'W', -30, 200, 0, 1565, 1565));
	printf("%i \n",printf("Hola Mundo, 658 %p, %s, %s, %%, %c, %d, %i, %u, %x,
			%X\n", ptr, "", "hola", 'W', -30, 200, 0, 1565, 1565));
	printf("%i = %i\n", i, j);
	ft_printf("%i = %i\n", i, j);
	return (0);
}
 */