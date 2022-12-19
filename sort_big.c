/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:13:04 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/19 15:39:23 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_push *push_a, t_push *push_b)
{
	int	size;
	int	bits;
	int	i;

	bits = 0;
	i = 0;
	size = push_a->len;
	while (!check_order(push_a))
	{
		i = 0;
		while (i < size)
		{
			if (((push_a->stack[0] >> bits) & 1) == 1)
				rotate(push_a->stack, push_a->len, 'a');
			else
				push(push_b, push_a, 'b');
			i++;
		}
		while (push_b->len > 0)
			push(push_a, push_b, 'a');
		bits++;
	}
}
