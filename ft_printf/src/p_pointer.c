/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:30:14 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/27 13:59:39 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	p_hex64(uintptr_t addr)
{
	const char	*hex;
	int			len;

	hex = "0123456789abcdef";
	len = 0;
	if (addr >= 16)
		len += p_hex64(addr / 16);
	write(1, &hex[addr % 16], 1);
	len++;
	return (len);
}

int	p_pointer(void *p)
{
	int	len;

	if (!p)
		return ((int)write(1, "(nil)", 5));
	len = 0;
	len += (int)write(1, "0x", 2);
	len += p_hex64((uintptr_t)p);
	return (len);
}
