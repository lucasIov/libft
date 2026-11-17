/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:57:58 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 18:37:00 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(const char *s, char c)
{
	size_t	w_count;
	int		isin;
	size_t	i;

	isin = 0;
	w_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && isin)
		{
			w_count++;
			isin = 0;
		}
		if (s[i] != c)
			isin = 1;
		i++;
	}
	if (isin)
		w_count++;
	return (w_count);
}

static int	alloc_or_clear(char **t, size_t i, size_t s)
{
	t[i] = malloc(s);
	if (!t[i])
	{
		while (--i)
			free(t[i]);
		free(t);
		return (0);
	}
	return (1);
}

/**
 * \param s The string to be split
 * \param c The delimiter character
 *
 * \return pointer the list of new strings or NULL if insufficient memory
 */
char	**ft_split(char const *s, char c)
{
	size_t	w_count;
	char	**res;
	char	*curw_l;

	w_count = ft_count_word(s, c);
	res = malloc(sizeof (char *) * (w_count + 1));
	res[w_count] = 0;
	w_count = 0;
	while (s && *s)
	{
		curw_l = ft_strchr(s, c);
		if (!curw_l)
			curw_l = ((char *)s) + ft_strlen(s);
		if (curw_l != s)
		{
			if (!alloc_or_clear(res, w_count, sizeof(char) * (curw_l - s + 1)))
				return (NULL);
			ft_strlcpy(res[w_count], s, curw_l - s + 1);
			w_count++;
		}
		else if (curw_l)
			curw_l++;
		s = curw_l;
	}
	return (res);
}
