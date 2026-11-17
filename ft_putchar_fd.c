/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:57:47 by liovine           #+#    #+#             */
/*   Updated: 2026/11/17 12:42:19 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// the fun way
// #if __linux__ && __x86_64__
//
// void	ft_putchar_fd(char c, int fd)
// {
// 	asm	volatile (
// 			"mov $1, %%rax\n\t"
// 			"mov %[fd], %%edi\n\t"
// 			"mov %[ch], %%rsi\n\t"
// 			"mov $1, %%rdx\t\n"
// 			"syscall\t\n"
// 			:
// 			: [fd]"r"(fd), [ch]"r" (&c)
// 			: "%rax", "%rdi", "%rsi", "%rdx"
// 			);
// 	return (1); // should be done in asm
// }
// #endif

/**
 * \param c  the character to output
 * \param fd the file descriptor on which to write
 * 
 * \bref Outputs the character 'c' to the given file descriptor
 */
ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
