/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasheri <@student.42porto.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:08:17 by sasheri           #+#    #+#             */
/*   Updated: 2025/10/21 19:45:00 by sasheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int		num_w;
	int		in_word;
	size_t	i;

	num_w = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			num_w++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (num_w);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*w;
	int		i;

	i = 0;
	w = (char *)malloc((end - start + 1) * sizeof(char));
	if (!w)
		return (NULL);
	while (start < end)
	{
		w[i] = s[start];
		i++;
		start++;
	}
	w[i] = '\0';
	return (w);
}

static int	push_word(char **str, int *j, char *w)
{
	if (!w)
	{
		while (*j > 0)
		{
			(*j)--;
			free(str[*j]);
		}
		return (0);
	}
	str[*j] = w;
	(*j)++;
	return (1);
}

static int	fill_array(char **str, const char *s, char c)
{
	int		i;
	int		j;
	int		start;
	int		end;

	i = -1;
	j = 0;
	start = -1;
	while (s[++i])
	{
		if (s[i] != c && start < 0)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			end = i;
			if (s[i] != c)
				end = i + 1;
			if (!push_word(str, &j, word_dup(s, start, end)))
				return (0);
			start = -1;
		}
	}
	str[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		num_w;
	char	**str;

	if (!s)
		return (NULL);
	num_w = count_words(s, c);
	str = (char **)malloc((num_w + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	if (!fill_array(str, s, c))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
