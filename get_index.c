/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:29:14 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/19 15:48:18 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_index(t_push *push, int *sorted)
{
	int	*temp;
	int	i;
	int	j;

	temp = malloc(sizeof(int) * push->len);
	i = 0;
	j = 0;
	while (i < push->len)
	{
		while (j < push->len)
		{
			if (push->stack[i] == sorted[j])
				temp[i] = j;
			j++;
		}
		i++;
		j = 0;
	}
	while (j < push->len)
	{
		push->stack[j] = temp[j];
		j++;
	}
	free(temp);
}

void	get_index(t_push *push)
{
	int	i;
	int	*temp;
	int	swap;

	i = -1;
	temp = malloc(sizeof(int) * push->len);
	while (++i < push->len)
		temp[i] = push->stack[i];
	i = 0;
	while (i < (push->len - 1))
	{
		if (temp[i] > temp[i + 1])
		{
			swap = temp[i];
			temp[i] = temp[i + 1];
			temp[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	stack_index(push, temp);
	free(temp);
}
