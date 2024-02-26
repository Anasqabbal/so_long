/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:36:08 by anqabbal          #+#    #+#             */
/*   Updated: 2024/01/10 12:57:35 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	to_check(const char *format, va_list ar, int i, int count)
{
	if (*(format + i) == '%' && (*(format + i + 1) == '%'))
		count += ft_putchar_fd('%', 1);
	else if (*(format + i) == '%' && (*(format + i + 1) == 'c'))
		count += ft_putchar_fd(va_arg(ar, int), 1);
	else if (*(format + i) == '%' && (*(format + i + 1) == 's'))
		count += ft_putstr_fd(va_arg(ar, char *), 1);
	else if (*(format + i) == '%'
		&& (*(format + i + 1) == 'd' || *(format + i + 1) == 'i'))
		count += ft_putnbr_fd(va_arg(ar, int), 1);
	else if (*(format + i) == '%' && *(format + i + 1) == 'x')
		count += ft_print_hexa(va_arg(ar, unsigned int), 0);
	else if (*(format + i) == '%' && *(format + i + 1) == 'X')
		count += ft_print_hexa(va_arg(ar, unsigned int), 1);
	else if (*(format + i) == '%' && *(format + i + 1) == 'u')
		count += ft_print_unsigned(va_arg(ar, int), 1);
	else if (*(format + i) == '%' && *(format + i + 1) == 'p')
		count += ft_print_address(va_arg(ar, void *));
	else if (*(format + i) == '%')
		count += ft_putchar_fd(*(format + i + 1), 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ar;

	va_start(ar, format);
	i = 0;
	count = 0;
	while (*(format + i))
	{
		if (write(1, "", 0) == -1)
			return (-1);
		if (*(format + i) == '%' && *(format + i + 1) != '\0')
			count = to_check(format, ar, i++, count);
		else if (format[i] != '%')
			count += ft_putchar_fd(*(format + i), 1);
		i++;
	}
	va_end(ar);
	return (count);
}

int main()
{
	ft_printf("adghaug%uelwihfw%x", 455);
	printf("\n");
	printf("adghaug%uelwihfw%c", 455);
	
	
}