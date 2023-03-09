/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:26:23 by amdouyah          #+#    #+#             */
/*   Updated: 2023/03/09 22:43:44 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int bin[8];

void convert(char c, int pid)
{
	int i;
	int n;
	
	n = (int)c;
	ft_bzero(bin, 8);
	i = 7;
	while (i >= 0)
	{
		bin[i] = n % 2;
		n =  n / 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if (bin[i] == 0)
			kill(pid, SIGUSR2);
		if (bin[i] == 1)
			kill (pid, SIGUSR1);
		usleep(200);
		i++;
	}
}

void	chara(char *str, int pid)
{
	int i;
	i = 0;
	while (str[i])
	{
		convert(str[i], pid);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int pid;

		pid = ft_atoi(av[1]);
		chara(av[2], pid);
	}
}