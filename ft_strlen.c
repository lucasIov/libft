/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:22 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:30:01 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// pointer alternative:
// same things this one use a sub instead of add in the asm code
// const char *os = s;
// while (*s)
// 	s++;
// return (s - os);
/**
 * \param s pointer to a NULL terminated string
 * \return string size
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
