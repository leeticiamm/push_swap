/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:11:33 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/20 12:56:17 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push *push_a)
{
	if (push_a->stack[0] > push_a->stack[1]
		&& push_a->stack[0] < push_a->stack[2])
		swap(push_a->stack, 'a');
	else if (push_a->stack[0] < push_a->stack[1]
		&& push_a->stack[0] > push_a->stack[2])
		reverse_rotate(push_a->stack, push_a->len, 'a');
	else if (push_a->stack[0] < push_a->stack[1]
		&& push_a->stack[1] > push_a->stack[2])
	{
		swap(push_a->stack, 'a');
		rotate(push_a->stack, push_a->len, 'a');
	}
	else if (push_a->stack[0] > push_a->stack[1]
		&& push_a->stack[1] < push_a->stack[2])
		rotate(push_a->stack, push_a->len, 'a');
	else
	{
		swap(push_a->stack, 'a');
		reverse_rotate(push_a->stack, push_a->len, 'a');
	}
}

void	optimize(t_push *push_a)
{
	if (push_a->stack[1] == 0)
		rotate(push_a->stack, push_a->len, 'a');
	else if (push_a->stack[2] == 0)
	{
		rotate(push_a->stack, push_a->len, 'a');
		rotate(push_a->stack, push_a->len, 'a');
	}
	else if (push_a->stack[3] == 0)
	{
		reverse_rotate(push_a->stack, push_a->len, 'a');
		reverse_rotate(push_a->stack, push_a->len, 'a');
	}
	else if (push_a->stack[4] == 0)
		reverse_rotate(push_a->stack, push_a->len, 'a');
}

void	sort_five(t_push *push_a, t_push *push_b)
{
	optimize(push_a);
	push(push_b, push_a, 'b');
	if (push_a->stack[1] == 1)
		rotate(push_a->stack, push_a->len, 'a');
	else if (push_a->stack[2] == 1)
	{
		rotate(push_a->stack, push_a->len, 'a');
		rotate(push_a->stack, push_a->len, 'a');
	}
	else if (push_a->stack[3] == 1)
		reverse_rotate(push_a->stack, push_a->len, 'a');
	push(push_b, push_a, 'b');
	if (check_order(push_a) == 0)
		sort_three(push_a);
	push(push_a, push_b, 'a');
	push(push_a, push_b, 'a');
}

void	sort_four(t_push *push_a, t_push *push_b)
{
	if (push_a->stack[1] == 0)
		rotate(push_a->stack, push_a->len, 'a');
	else if (push_a->stack[2] == 0)
	{
		rotate(push_a->stack, push_a->len, 'a');
		rotate(push_a->stack, push_a->len, 'a');
	}
	else if (push_a->stack[3] == 0)
		reverse_rotate(push_a->stack, push_a->len, 'a');
	push(push_b, push_a, 'b');
	if (check_order(push_a) == 0)
		sort_three(push_a);
	push(push_a, push_b, 'a');
}

void	sort(t_push *push_a, t_push *push_b)
{
	if (push_a->len == 2)
		swap(push_a->stack, 'a');
	else if (push_a->len == 3)
		sort_three(push_a);
	else if (push_a->len == 4)
		sort_four(push_a, push_b);
	else if (push_a->len == 5)
		sort_five(push_a, push_b);
	else if (push_a->len > 5)
		sort_big(push_a, push_b);
}
