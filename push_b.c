/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:21:20 by mpimenta          #+#    #+#             */
/*   Updated: 2022/12/13 16:54:47 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_push *push)
{
	int	i;
	int	*temp;

	i = 1;
	temp = malloc(sizeof(int) * (push->len_b - 1));
	while (i < push->len_b)
	{
		temp[i - 1] = push->stack_b[i];
		i++;
	}
	free(push->stack_b);
	push->len_b--;
	push->stack_b = malloc(sizeof(int) * push->len_b);
	i = 0;
	while (i < push->len_b)
	{
		push->stack_b[i] = temp[i];
		i++;
	}
	free(temp);
}

void	mounting(t_push *push)
{
	int	i;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * push->len_a);
	while (i < push->len_a)
	{
		temp[i] = push->stack_a[i];
		i++;
	}
	free(push->stack_a);
	push->len_a++;
	push->stack_a = malloc(sizeof(int) * push->len_a);
	push->stack_a[0] = push->stack_b[0];
	i = 1;
	while (i < push->len_a)
	{
		push->stack_a[i] = temp[i - 1];
		i++;
	}
	free(temp);
}

void	pa(t_push *push)
{
	int	i;

	i = push->len_a + 1;
	if (i == 1)
	{
		push->stack_a = malloc(sizeof(int));
		push->stack_a[0] = push->stack_b[0];
		push->len_a++;
	}
	else
		mounting(push);
	if (push->len_b > 1)
		move(push);
	else if (push->len_b == 1)
	{
		push->len_b--;
		free(push->stack_b);
	}
	ft_putstr_fd("pa\n", 1);
}
