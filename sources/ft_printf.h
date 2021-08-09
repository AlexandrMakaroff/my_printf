/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:23:42 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/01/10 11:48:28 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef	struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			len;
	int			dot;
	char		type;
}				t_flags;

int				ft_printf(const char *format, ...);
t_flags			ft_init_flags();
int				ft_star_arg(va_list args);
int				ft_set_flags(const char *str, int i, va_list args,
				t_flags *flags);
void			ft_putchar(char c);
int				ft_parse(const char *str, va_list args);
int				ft_put_type(t_flags *flags, va_list args);
int				ft_print_c(t_flags *flags, va_list args);
int				ft_print_d(t_flags *flags, va_list args);
char			*ft_put_integer(int size, char *str);
int				ft_print_s(t_flags *flags, va_list args);
int				ft_put_string(char *str, t_flags *flags);
int				ft_print_x(t_flags *flags, va_list args);
char			*ft_to_hex(long i, char type);
int				ft_print_u(t_flags *flags, va_list args);
char			*ft_put_unsigned(size_t size, char *str, t_flags *flags);
int				ft_print_p(t_flags *flags, va_list args);
char			*ft_strcpy(char *str, t_flags *flags);

#endif
