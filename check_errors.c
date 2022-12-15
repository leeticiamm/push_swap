/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:04:56 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/15 17:47:22 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 0)
		{
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		i++;
	}
	return (0);
}

void	check_limits(long num)
{
	if (num > 2147483647 || num < -2147483648)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
}

void	check_repeated_num(t_push *push)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < push->len_a)
	{
		while (j < push->len_a)
		{
			if (push->stack_a[i] == push->stack_a[j])
			{
				ft_putstr_fd("Error\n", 1);
				exit(0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	check_order(t_push *push)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j < push->len_a)
	{
		if (push->stack_a[i] < push->stack_a[j])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	free(push->stack_a);
	exit(0);
}