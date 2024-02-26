/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:08:37 by anqabbal          #+#    #+#             */
/*   Updated: 2023/12/31 10:53:35 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	to_upper_case(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}

int	ft_print_hexa(unsigned int nb, int indice)
{
	char	*arr;
	int		count;

	count = 0;
	arr = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_print_hexa(nb / 16, indice);
		count += ft_print_hexa(nb % 16, indice);
	}
	if (nb < 16 && indice == 1)
		count += ft_putchar_fd(to_upper_case(arr[nb]), 1);
	else if (nb < 16 && indice == 0)
		count += ft_putchar_fd(arr[nb], 1);
	return (count);
}
