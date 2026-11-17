/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:58:13 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:26:37 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * \param s1 The prefix string
 * \param s2 The suffix string
 * \return The new string or NULL if the allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	prefix_len;
	size_t	suffix_len;
	char	*res;

	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	res = malloc(sizeof(char) * (suffix_len + prefix_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, prefix_len);
	ft_memcpy(res + prefix_len, s2, suffix_len);
	res[suffix_len + prefix_len] = 0;
	return (res);
}
