/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:34 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 17:13:03 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*lastpos;

	i = 0;
	lastpos = NULL;
	if (!c)
		return ((char *)(s + ft_strlen(s)));
	c = c & 0b1111111;
	while (s[i])
	{
		if (s[i] == c)
			lastpos = (char *)(s + i);
		i++;
	}
	return (lastpos);
}
