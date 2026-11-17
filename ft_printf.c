/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:29:22 by liovine           #+#    #+#             */
/*   Updated: 2026/11/17 12:44:02 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

#define DIGIT "0123456789"
#define HEXSTR "0123456789abcdef"
#define HEXSTR_MAJ "0123456789ABCDEF"

static size_t	ft_putnbase(size_t n, const char *base)
{
	char	res[64];
	size_t	pos;
	int		base_l;

	pos = 64;
	base_l = ft_strlen(base);
	while (n || pos == 64)
	{
		res[--pos] = base[n % base_l];
		n /= base_l;
	}
	return (write(1, res + pos, 64 - pos));
}

static ssize_t	ft_print_pointer(size_t v)
{
	if (!v)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_putnbase(v, HEXSTR));
}

static size_t	ft_putv(const char *c, va_list *ap)
{
	if (*c == '%')
		return (write(1, "%", 1));
	if (*c == 'c')
		return (write(1, &(char){va_arg(*ap, int)}, 1));
	if (*c == 's')
	{
		c = va_arg(*ap, char *);
		if (!c)
			return (write(1, "(null)", 6));
		return (write(1, (char *)c, ft_strlen((char *)c)));
	}
	if (*c == 'p')
		return (ft_print_pointer(va_arg(*ap, unsigned long long)));
	if (*c == 'd' || *c == 'i')
		return (ft_putnbr_fd(va_arg(*ap, int), 1));
	if (*c == 'u')
		return (ft_putnbase(va_arg(*ap, unsigned int), DIGIT));
	if (*c == 'x')
		return (ft_putnbase(va_arg(*ap, unsigned int), HEXSTR));
	if (*c == 'X')
		return (ft_putnbase(va_arg(*ap, unsigned int), HEXSTR_MAJ));
	return (-1);
}

static int	ft_vprintf(const char *s, va_list *ap)
{
	size_t	writen;
	char	*end;
	int		wr;

	writen = 0;
	while (1)
	{
		end = ft_strchr(s, '%');
		if (!end)
			return (writen + write(1, s, ft_strlen(s)));
		if (end - s)
			writen += write(1, s, end - s);
		s = end + 1;
		wr = ft_putv(s, ap);
		if (wr == -1)
			writen += write(1, "%", 1);
		else
		{
			writen += wr;
			s++;
		}
		if (!*s)
			return (writen);
	}
}

// __attribute__ ((format (printf, 1, 2)))
int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		c;

	if (!s)
		return (-1);
	if (!*s)
		return (0);
	va_start(ap, s);
	c = ft_vprintf(s, &ap);
	va_end(ap);
	return (c);
}
