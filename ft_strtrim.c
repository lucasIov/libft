/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:37 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:35:06 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \param s1  The string to be trimmed.
 * \param set The reference set of characters to trim.
 *
 * \return trimmed string or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	start = 0;
	end = 0;
	while (s1[start])
	{
		if (!ft_strchr(set, s1[start++]))
			end = start;
	}
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) && start < end)
		start++;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	res[end - start] = 0;
	ft_memcpy(res, s1 + start, (end - start));
	return (res);
}
