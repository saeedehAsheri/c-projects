/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <sasheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:52:40 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/27 14:23:08 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		p_highhex(unsigned int n);
int		p_lowhex(unsigned int n);
int		p_nbr(int n);
int		p_pointer(void *p);
int		p_str(const char *s);
int		p_uint(unsigned int n);

#endif
