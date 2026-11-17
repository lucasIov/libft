/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:54:26 by liovine           #+#    #+#             */
/*   Updated: 2026/11/17 12:09:44 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \param nptr string to parse
 * \return converted integer value or 0 is no valid integer has been foud
 */
int	ft_atoi(const char *nptr)
{
	int	res;
	int	isn;

	while (*nptr && ft_isspace(*nptr))
		nptr++;
	isn = *nptr == '-';
	nptr += (isn || *nptr == '+');
	res = 0;
	while (*nptr && ft_isdigit(*nptr))
		res = res * 10 + (*(nptr++) - '0');
	return (res * ((!isn << 1) - 1));
}
