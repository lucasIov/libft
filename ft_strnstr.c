/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:31 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 18:10:33 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*last_start;
	size_t	lit_i;

	last_start = 0;
	lit_i = 0;
	if (!little || !*little || !big)
		return ((char *)big);
	while (*big && len--)
	{
		if (*big == little[lit_i])
		{
			if (lit_i++ == 0)
				last_start = (char *)big;
			if (little[lit_i] == 0)
				return (last_start);
		}
		else if (lit_i)
		{
			big -= lit_i;
			len += lit_i;
			lit_i = 0;
		}
		big++;
	}
	return (NULL);
}
