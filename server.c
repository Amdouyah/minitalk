/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:02:25 by amdouyah          #+#    #+#             */
/*   Updated: 2023/03/09 22:44:35 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power_conv(int i)
{
	int a;
	int nb;

	a = 0;
	nb = 1;
	while (a < i)
	{
		nb *= 2;
		a++;
	}
	return (nb);
}

int	opp_convert(char *str)
{
	int i;
	int power;
	int nb;
	
	power = 0;
	nb = 0;
	i = 7;
	while(i >= 0)
	{
		if (str[i] == '1')
		{
			nb += power_conv(power);
		}
		i--;
		power++;
	}
	return (nb);
}

void	handler(int sig, siginfo_t *info, void *vd)
{
	(void)vd;
	char str[8];
	static int i;

	if (sig == SIGUSR2)
		str[i] = '0';
	if (sig == SIGUSR1)
		str[i] = '1';
	i++;
	if (i == 8)
	{
		opp_convert(str);
		ft_printf("%c", opp_convert(str));
		i = 0;
	}
}

int main()
{
	struct sigaction sa;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_RESTART;
	pid_t pid;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{}
	
	return 0;
}  