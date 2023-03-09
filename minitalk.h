/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:24:34 by amdouyah          #+#    #+#             */
/*   Updated: 2023/03/09 21:54:41 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const	char *s);
void	convert(char c, int pid);
void	chara(char *str, int pid);

#endif