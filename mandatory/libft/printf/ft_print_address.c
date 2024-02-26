/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:00:57 by anqabbal          #+#    #+#             */
/*   Updated: 2023/12/08 17:01:45 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hexa_long(unsigned long nb)
{
	char	*arr;
	int		count;

	count = 0;
	arr = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_print_hexa_long(nb / 16);
		count += ft_print_hexa_long(nb % 16);
	}
	else if (nb < 16)
		count += ft_putchar_fd(arr[nb], 1);
	return (count);
}

int	ft_print_address(void *p)
{
	int				count;
	unsigned long	nb;

	count = 0;
	nb = (unsigned long)p;
	count = ft_putstr_fd("0x", 1);
	count += ft_print_hexa_long(nb);
	return (count);
}
