/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:40 by liovine           #+#    #+#             */
/*   Updated: 2026/11/05 12:03:56 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \param s     The string from which to create the substring
 * \param start The start index of the substring in the string 's'
 * \param len   The maximum length of the substring
 *
 * \return the substring or NULL if allocation fails
 *
 * \note The substring begins at index 'start' and is of maximum size 'len'
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sl;
	char	*res;

	sl = ft_strlen(s);
	if (sl < start)
		sl = start;
	sl -= start;
	if (sl < len)
		len = sl;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	ft_memcpy(res, s + start, len);
	return (res);
}
