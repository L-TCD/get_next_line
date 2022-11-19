/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoissar <lcoissar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:03:51 by lcoissar          #+#    #+#             */
/*   Updated: 2022/11/18 07:06:38 by lcoissar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);

int		char_format(char c);
int		string_format(char *str);
int		pointer_format(void *ptr);
int		digit_format(int digit);
int		unsigned_format(unsigned int ul);
int		hexa_format(unsigned int hexa);
int		upper_hexa_format(unsigned int hexa);
int		percent_format(void);

char	*itoa_base(unsigned long long num, char *base);

#endif
