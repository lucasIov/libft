/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:45:39 by liovine           #+#    #+#             */
/*   Updated: 2026/11/17 12:58:16 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	buff_concat(t_buff *a, t_buff b)
{
	void	*p;

	if (!a->data)
		a->l = 0;
	p = malloc(a->l + b.l);
	if (!p)
		return (0);
	if (a->data)
	{
		ft_memcpy(p, a->data, a->l);
		free(a->data);
	}
	a->data = p;
	ft_memcpy(a->data + a->l, b.data, b.l);
	a->l += b.l;
	return (1);
}

static t_buff	separate(t_buff b, t_bk_buff *bk, size_t prefix)
{
	t_buff	line;

	line.l = prefix;
	line.data = malloc(sizeof(char) * (line.l + 1));
	if (!line.data)
		return ((t_buff){0, NULL});
	ft_memcpy(line.data, b.data, prefix);
	line.data[line.l] = 0;
	ft_memcpy(bk->data, b.data + prefix, b.l - prefix);
	bk->l = b.l - prefix;
	return (line);
}

static ssize_t	find_lf(t_buff b)
{
	ssize_t	i;

	i = 0;
	while (i < b.l)
	{
		if (b.data[i++] == '\n')
			return (i);
	}
	return (0);
}

static ssize_t	new(t_buff *work_buff, int fd)
{
	size_t				ln_pos;
	static t_bk_buff	new_data;

	while (1)
	{
		new_data.l = read(fd, new_data.data, BUFFER_SIZE);
		if (new_data.l < 0)
			return (new_data.l);
		if (new_data.l == 0)
			return (work_buff->l);
		if (!buff_concat(work_buff, (t_buff){new_data.l, new_data.data}))
			return (-1);
		ln_pos = find_lf(*work_buff);
		if (!ln_pos)
			continue ;
		return (ln_pos);
	}
}

char	*get_next_line(int fd)
{
	static t_bk_buff	old[FD_LIMIT];
	t_buff				res;
	ssize_t				ln_pos;
	t_buff				final_res;

	if (fd < 0 || fd >= FD_LIMIT)
		return (NULL);
	ln_pos = find_lf((t_buff){old[fd].l, old[fd].data});
	if (ln_pos)
	{
		res = separate((t_buff){old[fd].l, old[fd].data}, &old[fd], ln_pos);
		return (res.data);
	}
	res.data = NULL;
	res.l = 0;
	if (old[fd].l && !buff_concat(&res, (t_buff){old[fd].l, old[fd].data}))
		return (NULL);
	ln_pos = new(&res, fd);
	if (ln_pos <= 0)
		return (NULL);
	final_res = separate(res, &old[fd], ln_pos);
	free(res.data);
	return (final_res.data);
}
