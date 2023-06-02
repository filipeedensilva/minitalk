/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:19:17 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/26 18:51:13 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_placeholder(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == '%'
		|| c == 's' || c == 'p' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	ft_checker(va_list *args, char format, t_ind *lst)
{
	if (format == 'd' || format == 'i')
		ft_putlnbr(va_arg(*args, int), lst);
	else if (format == 'c')
		ft_putlchar(va_arg(*args, int), lst);
	else if (format == 's')
		ft_putlstr(va_arg(*args, char *), lst);
	else if (format == '%')
		ft_putlchar('%', lst);
	else if (format == 'p')
		ft_putlptr(va_arg(*args, size_t), lst);
	else if (format == 'u')
		ft_putlnbr(va_arg(*args, unsigned int), lst);
	else if (format == 'x')
		ft_putlhex(va_arg(*args, unsigned int), 'x', lst);
	else if (format == 'X')
		ft_putlhex(va_arg(*args, unsigned int), 'X', lst);
}

int	ft_printf(const char *format, ...)
{
	t_ind	lst;
	va_list	args;

	lst.len = 0;
	lst.width = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ft_placeholder(*(char *)(format + 1)))
		{
			ft_checker(&args, *(char *)(format + 1), &lst);
			format++;
		}
		else
			ft_putlchar(*format, &lst);
		format++;
	}
	va_end(args);
	return (lst.len);
}
