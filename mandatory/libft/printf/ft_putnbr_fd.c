/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:47:55 by anqabbal          #+#    #+#             */
/*   Updated: 2023/12/08 16:58:53 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (fd < 0)
		return (-1);
	nb = n;
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		nb = n * -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr_fd(nb / 10, fd);
		count += ft_putnbr_fd(nb % 10, fd);
	}
	if (nb >= 0 && nb <= 9)
		count += ft_putchar_fd((nb + 48), fd);
	return (count);
}
