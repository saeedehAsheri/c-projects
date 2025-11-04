/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_highhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:30:28 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/27 13:56:29 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_highhex(unsigned int n)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		len += p_highhex(n / 16);
	write(1, &hex[n % 16], 1);
	len++;
	return (len);
}
