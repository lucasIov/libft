/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:56:24 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 11:56:25 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checks for white-space characters
// space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
// horizontal tab ('\t'), and vertical tab ('\v')
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 0x9 && c <= 0xD));
}
