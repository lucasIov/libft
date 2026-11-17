/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:06 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:23:46 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \param s original string to be copied
 * \return pointer to the duplicated string or NULL if insufficient memory
 */
char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	s_size;

	s_size = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * s_size);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, s_size);
	return (res);
}
