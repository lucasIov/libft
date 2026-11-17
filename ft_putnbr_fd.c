/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:57:53 by liovine           #+#    #+#             */
/*   Updated: 2026/11/17 12:42:04 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \param n  The integer to output
 * \param fd The file descriptor on which to write
 *
 * \bref write the string representation of the given integer
 */
ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	res[11];
	size_t	pos;
	int		isn;

	pos = 11;
	isn = n < 0;
	while (n || pos == 11)
	{
		res[--pos] = ((n % 10) * ((((n % 10) >= 0) << 1) - 1)) + '0';
		n /= 10;
	}
	if (isn)
		res[--pos] = '-' * isn;
	return (write(fd, res + pos, 11 - pos));
}
