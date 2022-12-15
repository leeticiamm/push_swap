/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:29:14 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/15 15:53:27 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_index(t_push *push, int *sorted)
{
    int *temp;
    int i;
    int j;

    temp = malloc(sizeof(int) * push->len_a);
    i = 0;
    j = 0;
    while (i < push->len_a)
    {
        while (j < push->len_a)
        {
            if (push->stack_a[i] == sorted[j])
                temp[i] = j;
            j++;
        }
        i++;
        j = 0;
    }
    while (j < push->len_a)
    {
        push->stack_a[j] = temp[j];
        j++;
    }
    free(temp);
}

void    get_index(t_push *push)
{
    int i;
    int *temp;
    int swap;

    i = 0;
    temp = malloc(sizeof(int) * push->len_a);
    while (i < push->len_a)
    {
        temp[i] = push->stack_a[i];
        i++;
    }
    i = 0;
    while (i < (push->len_a - 1))
    {
        if (temp[i] > temp[i + 1])
        {
            swap = temp[i];
            temp[i] = temp[i + 1];
            temp[i + 1] = swap;
            i = 0;
        }
        else
            i++;
    }
    stack_index(push, temp);
    free(temp);
}