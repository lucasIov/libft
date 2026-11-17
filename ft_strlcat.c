/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:17 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:28:54 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_s;

	if (!dsize)
		return (ft_strlen(src));
	dst_s = ft_strlen(dst);
	if (dst_s > dsize)
		return (dsize + ft_strlen(src));
	return (ft_strlcpy(dst + dst_s, src, dsize - dst_s) + dst_s);
}
