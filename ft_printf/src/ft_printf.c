/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:58:35 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/27 13:56:22 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_fmt(char c, va_list ap)
{
	char	ch;

	if (c == 'c')
	{
		ch = (char)va_arg(ap, int);
		return ((int)write(1, &ch, 1));
	}
	else if (c == '%')
		return ((int)write(1, "%", 1));
	else if (c == 's')
		return (p_str(va_arg(ap, const char *)));
	else if (c == 'p')
		return (p_pointer(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (p_nbr(va_arg(ap, int)));
	else if (c == 'u')
		return (p_uint(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (p_lowhex(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (p_highhex(va_arg(ap, unsigned int)));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;
	int		len;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == '\0')
				break ;
			i++;
			len += check_fmt(fmt[i], ap);
		}
		else
			len += (int)write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
