/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <@student.42porto.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:55:11 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/20 20:56:59 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*jstr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	jstr = (char *)malloc(len_s1 + len_s2 + 1);
	if (!jstr)
		return (NULL);
	ft_memcpy(jstr, s1, len_s1);
	ft_memcpy(jstr + len_s1, s2, len_s2);
	jstr[len_s1 + len_s2] = '\0';
	return (jstr);
}
