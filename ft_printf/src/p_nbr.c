/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nbr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:57:43 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/27 13:58:15 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar1(char c)
{
	return ((int)write(1, &c, 1));
}

int	p_nbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar1('-');
		num = -num;
	}
	if (num >= 10)
		count += p_nbr((int)(num / 10));
	count += ft_putchar1((char)('0' + (num % 10)));
	return (count);
}
