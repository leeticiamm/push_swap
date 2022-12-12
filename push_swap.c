/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:59:39 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/12 17:20:58 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int     i;
    t_push  push;

    i = 1;
    push.len_a = argc - 1;
    if (argc > 2)
    {
        while (argv[i])
        {
            check_num(argv[i]);
            i++;
        }
        push.stack_a = malloc(sizeof(int) * push.len_a);
        i = 1;
        while (argv[i])
        {
            push.stack_a[i] = ft_atoi(argv[i]);
            printf("%d\n", push.stack_a[i]);
            i++;
        }
        check_repeated_num(&push);
        check_order(&push);
    }
    return (0);
}
