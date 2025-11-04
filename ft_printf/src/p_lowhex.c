/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lowhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:25:26 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/27 13:57:19 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_lowhex(unsigned int n)
{
	int		len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		len += p_lowhex(n / 16);
	write(1, &hex[n % 16], 1);
	len++;
	return (len);
}
