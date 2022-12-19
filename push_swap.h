/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:14:53 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/19 15:39:36 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct push
{
	int	*stack;
	int	len;
}		t_push;

int		check_num(char *num);
void	check_limits(long num);
void	check_repeated_num(t_push *push);
int		check_order(t_push *push);
void	swap(int *stack, char print);
void	ss(int *stack_a, int *stack_b);
void	rotate(int *stack, int len, char print);
void	rr(int *stack_a, int *stack_b, int len_a, int len_b);
void	reverse_rotate(int *stack, int len, char print);
void	rrr(int *stack_a, int *stack_b, int len_a, int len_b);
void	push(t_push *push_recive, t_push *push_take, char print);
void	sort(t_push *push_a, t_push *push_b);
void	get_index(t_push *push);
void	sort_big(t_push *push_a, t_push *push_b);

#endif