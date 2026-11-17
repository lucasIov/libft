/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:55:39 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 11:55:40 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \brief errase given memory section with 0
 *
 * \param s start pointer
 * \param n memory size
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
