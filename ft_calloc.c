/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:55:44 by liovine           #+#    #+#             */
/*   Updated: 2026/11/05 11:41:54 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \brief allocate requested memory and initialize if with 0
 *
 * \param nelem number of element
 * \param elsize single element size
 * \return pointer to allocated memory or NULL on fail
 */
void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*res;
	size_t	s;

	s = nelem * elsize;
	if (!nelem || !elsize)
		s = 1;
	else if (s / nelem != elsize)
		return (NULL);
	res = malloc(s);
	if (res)
		ft_bzero(res, s);
	return (res);
}
