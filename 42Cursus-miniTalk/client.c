/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myayla <myayla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:19:46 by myayla            #+#    #+#             */
/*   Updated: 2023/01/12 05:41:57 by myayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	get_bit(int pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		i--;
	}
}

static void	get_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		get_bit(pid, str[i++]);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3)
	{
		ft_putstr_fd(LOWARGERR, 1);
		return (0);
	}
	if (argc > 3)
	{
		ft_putstr_fd(TOOARGERR, 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	get_char(pid, argv[2]);
	return (0);
}
