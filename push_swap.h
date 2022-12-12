/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:14:53 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/12 17:20:12 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"

typedef struct push
{
    int *stack_a;
    int *stack_b;
    int len_a;
    int len_b;
}   t_push;

int     check_num(char *num);
void    check_limits(long num);
void    check_repeated_num(t_push *push);
void    check_order(t_push *push);

#endif