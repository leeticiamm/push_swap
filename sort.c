/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:11:33 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/15 18:52:32 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push *push)
{
	if (push->stack_a[0] > push->stack_a[1] && push->stack_a[0] < push->stack_a[2])
		swap(push->stack_a, 'a');
	else if (push->stack_a[0] < push->stack_a[1] && push->stack_a[0] > push->stack_a[2])
		reverse_rotate(push->stack_a, push->len_a, 'a');
	else if (push->stack_a[0] < push->stack_a[1] && push->stack_a[1] > push->stack_a[2])
	{
		swap(push->stack_a, 'a');
		rotate(push->stack_a, push->len_a, 'a');
	}
	else if (push->stack_a[0] > push->stack_a[1] && push->stack_a[1] < push->stack_a[2])
		rotate(push->stack_a, push->len_a, 'a');
	else
		{
			swap(push->stack_a, 'a');
			reverse_rotate(push->stack_a, push->len_a, 'a');
		}
}

void	sort_five(t_push *push)
{
	
}

void	sort(t_push *push)
{
	if (push->len_a == 2)
		swap(push->stack_a, 'a');
	if (push->len_a == 3)
		sort_three(push);
}