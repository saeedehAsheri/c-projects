/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <@student.42porto.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:42:31 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/20 11:45:03 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_fill_digits(char *s, size_t len, long long num)
{
	while (num > 0)
	{
		s[--len] = (char)((num % 10) + '0');
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	long long	num;
	size_t		len;
	char		*s;

	num = (long long)n;
	len = ft_intlen(num);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (num == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	ft_fill_digits(s, len, num);
	return (s);
}
