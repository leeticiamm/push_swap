/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:39:41 by mpimenta          #+#    #+#             */
/*   Updated: 2022/12/13 16:54:56 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moving(t_push *push)
{
	int	i;
	int	*temp;

	i = 1;
	temp = malloc(sizeof(int) * (push->len_a - 1));
	while (i < push->len_a)
	{
		temp[i - 1] = push->stack_a[i];
		i++;
	}
	free(push->stack_a);
	push->len_a--;
	push->stack_a = malloc(sizeof(int) * push->len_a);
	i = 0;
	while (i < push->len_a)
	{
		push->stack_a[i] = temp[i];
		i++;
	}
	free(temp);
}

void	mount(t_push *push)
{
	int	i;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * push->len_b);
	while (i < push->len_b)
	{
		temp[i] = push->stack_b[i];
		i++;
	}
	free(push->stack_b);
	push->len_b++;
	push->stack_b = malloc(sizeof(int) * push->len_b);
	push->stack_b[0] = push->stack_a[0];
	i = 1;
	while (i < push->len_b)
	{
		push->stack_b[i] = temp[i - 1];
		i++;
	}
	free(temp);
}

void	pb(t_push *push)
{
	int	i;

	i = push->len_b + 1;
	if (i == 1)
	{
		push->stack_b = malloc(sizeof(int));
		push->stack_b[0] = push->stack_a[0];
		push->len_b++;
	}
	else
		mount(push);
	if (push->len_a > 1)
		moving(push);
	else if (push->len_a == 1)
	{
		push->len_a--;
		free(push->stack_a);
	}
	ft_putstr_fd("pb\n", 1);
}
