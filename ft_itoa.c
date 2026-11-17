/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:56:37 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:03:18 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \brief convert a integer into a string
 *
 * \param n the integer to convert
 * \return the string (allocates with malloc(3)) representing the integer
 * or NULL if the allocation fails
 */
char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	int		copy;

	copy = n;
	len = (n == 0) + (n < 0);
	while (copy && ++len)
		copy /= 10;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	while (n || (res[len]) == 0)
	{
		res[--len] = ((n % 10) * ((((n % 10) >= 0) << 1) - 1)) + '0';
		n /= 10;
	}
	if (len)
		res[0] = '-';
	return (res);
}
