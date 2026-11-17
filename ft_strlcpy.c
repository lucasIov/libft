/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:19 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:29:07 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	const char	*osrc;

	osrc = src;
	if (!dsize)
		return (ft_strlen(src));
	while (*src && --dsize)
		*dst++ = *src++;
	src += ft_strlen(src);
	*dst = 0;
	return (src - osrc);
}
