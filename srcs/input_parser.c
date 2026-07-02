/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:52:57 by aserio            #+#    #+#             */
/*   Updated: 2026/07/01 10:00:09 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_strategy(char *s)
{
	if (!ft_strcmp(s, "--simple")
		|| !ft_strcmp(s, "--medium")
		|| !ft_strcmp(s, "--complex")
		|| !ft_strcmp(s, "--adaptive"))
		return (1);
	return (0);
}

static int	is_bench(char *s)
{
	if (!ft_strcmp(s, "--bench"))
		return (1);
	return (0);
}

static t_stack	*get_stack(int size, char **nums)
{
	t_stack	*stack;

	if (size == 1)
	{
		nums = ft_split(nums[0], ' ');
		while (nums[size])
			size++;
	}
	stack = load_stack(size, nums);
	if (!stack)
		return (NULL);
	return (stack);
}

t_parsed_input	input_parser(int argc, char *argv[])
{
	int				i;
	t_parsed_input	parsed_input;

	i = 1;
	while ((is_strategy(argv[i]))
			|| is_bench(argv[i]))
	{
		if (is_strategy(argv[i]))
			parsed_input.strategy = argv[i];
		if (is_bench(argv[i]))
			parsed_input.bench_flag = 1;
		i++;
	}
	parsed_input.stack = get_stack(argc - i, argv + i);
	return (parsed_input);
}
