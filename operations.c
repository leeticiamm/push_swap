/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:23:22 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/13 16:40:59 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, char print)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (print == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (print == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ss(int *stack_a, int *stack_b)
{
	swap(stack_a, 'l');
	swap(stack_b, 'l');
	ft_putstr_fd("ss\n", 1);
}

void	rotate(int *stack, int len, char print)
{
	int	temp;
	int	i;

	i = 1;
	temp = stack[0];
	while (i < len)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	stack[len - 1] = temp;
	if (print == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (print == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	rotate(stack_a, len_a, 'l');
	rotate(stack_b, len_b, 'l');
	ft_putstr_fd("rr\n", 1);
}
