/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:59:39 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/15 16:35:10 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// void printing(t_push *stack)
// {
//     int i;

//     i = 0;
//     while (i < stack->len_a)
//     {
//         printf("%d\n", stack->stack_a[i]);
//         i++;
//     }
//     printf("STACK A\n");
//     printf("\n-----------------------------------\n\n");
//     i = 0;
//     while (i < stack->len_b)
//     {
//         printf("%d\n", stack->stack_b[i]);
//         i++;
//     }
//     printf("STACK B\n\n\n");
// }

int	main(int argc, char *argv[])
{
	int		i;
	t_push	push;

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
			push.stack_a[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		check_repeated_num(&push);
		check_order(&push);
		get_index(&push);
		sort(&push);
        free(push.stack_a);
	}
	return (0);
}
