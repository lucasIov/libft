/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:02 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 17:07:24 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \param s null terminated string in witch to look at
 * \param c character to find in the string
 * \return pointer to the first matched character or NULL if none is found
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!c)
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	c = c & 0b1111111;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
