/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:57:35 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/19 12:04:36 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_push *push_take)
{
	int	i;
	int	*temp;

	i = 1;
	temp = malloc(sizeof(int) * (push_take->len - 1));
	while (i < push_take->len)
	{
		temp[i - 1] = push_take->stack[i];
		i++;
	}
	free(push_take->stack);
	push_take->len--;
	push_take->stack = malloc(sizeof(int) * push_take->len);
	i = 0;
	while (i < push_take->len)
	{
		push_take->stack[i] = temp[i];
		i++;
	}
	free(temp);
}

void	mounting(t_push *push_recive, t_push *push_take)
{
	int	i;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * push_recive->len);
	while (i < push_recive->len)
	{
		temp[i] = push_recive->stack[i];
		i++;
	}
	free(push_recive->stack);
	push_recive->len++;
	push_recive->stack = malloc(sizeof(int) * push_recive->len);
	push_recive->stack[0] = push_take->stack[0];
	i = 1;
	while (i < push_recive->len)
	{
		push_recive->stack[i] = temp[i - 1];
		i++;
	}
	free(temp);
}

void	push(t_push *push_recive, t_push *push_take, char print)
{
	int	i;

	i = push_recive->len + 1;
	if (i == 1)
	{
		push_recive->stack = malloc(sizeof(int));
		push_recive->stack[0] = push_take->stack[0];
		push_recive->len++;
	}
	else
		mounting(push_recive, push_take);
	if (push_take->len > 1)
		move(push_take);
	else if (push_take->len == 1)
	{
		push_take->len--;
		free(push_take->stack);
	}
	if (print == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (print == 'b')
		ft_putstr_fd("pb\n", 1);
}
