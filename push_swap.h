/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:14:53 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/15 15:56:02 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct push
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
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
void	pa(t_push *push);
void	pb(t_push *push);
void	sort(t_push *push);
void    get_index(t_push *push);

#endif