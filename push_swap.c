/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:59:39 by lmagalha          #+#    #+#             */
/*   Updated: 2022/12/19 15:47:47 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_push	push_a;
	t_push	push_b;

	i = 1;
	push_a.len = argc - 1;
	push_b.len = 0;
	while (argv[i])
		check_num(argv[i++]);
	if (argc < 3)
		return (0);
	push_a.stack = malloc(sizeof(int) * push_a.len);
	i = 0;
	while (argv[++i])
		push_a.stack[i - 1] = ft_atoi(argv[i]);
	check_repeated_num(&push_a);
	if (check_order(&push_a) == 1)
	{
		free(push_a.stack);
		return (0);
	}
	get_index(&push_a);
	sort(&push_a, &push_b);
	free(push_a.stack);
	return (0);
}
