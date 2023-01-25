/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myayla <myayla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:33 by myayla            #+#    #+#             */
/*   Updated: 2023/01/12 05:40:19 by myayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	put_bin(char *str)
{
	int		base;
	char	res;
	int		i;

	base = 128;
	res = 0;
	i = 0;
	while (str[i] != '\0' && base != 0)
	{
		if (str[i] == '1')
		{
			res += base;
			base /= 2;
		}
		else
			base /= 2;
		i++;
	}
	ft_putchar_fd(res, 1);
}

static void	sighandler(int signal)
{
	static int		byte;
	static char		*binary;

	if (binary == NULL)
	{
		binary = ft_strdup("");
		byte = 1;
	}
	if (signal == SIGUSR1)
		binary = ft_strjoin(binary, "0");
	else
		binary = ft_strjoin(binary, "1");
	if (byte == 8)
	{
		put_bin(binary);
		free(binary);
		binary = NULL;
	}
	byte++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
	{
		pause();
	}
	return (0);
}
