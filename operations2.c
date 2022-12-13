/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:32:45 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/13 16:49:41 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, int len, char print)
{
	int	temp;
	int	i;

	i = len - 1;
	temp = stack[len - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	if (print == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (print == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	reverse_rotate(stack_a, len_a, 'l');
	reverse_rotate(stack_b, len_b, 'l');
	ft_putstr_fd("rrr\n", 1);
}
