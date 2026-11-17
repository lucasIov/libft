/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:55:59 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 11:56:00 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checks whether c is a 7-bit unsigned char value that fits into ASCII char set
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 0b01111111);
}
