/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:52:57 by aserio            #+#    #+#             */
/*   Updated: 2026/07/21 16:07:14 by aserio           ###   ########.fr       */
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

static void	init_context(t_context *ctx)
{
	ctx->disorder = compute_disorder(ctx->a);
	ctx->total_ops = 0;
	if(!ctx->strategy)
		ctx->strategy = "--adaptive";
	ctx->sa = 0;
	ctx->sb = 0;
	ctx->ss = 0;
	ctx->pa = 0;
	ctx->pb = 0;
	ctx->ra = 0;
	ctx->rb = 0;
	ctx->rr = 0;
	ctx->rra = 0;
	ctx->rrb = 0;
	ctx->rrr = 0;
}

void	input_parser(int argc, char *argv[], t_context *ctx)
{
	int				i;

	i = 1;
	ctx->bench_flag = 0;
	ctx->strategy = NULL;
	while ((is_strategy(argv[i]))
		|| is_bench(argv[i]))
	{
		if (is_strategy(argv[i]))
			ctx->strategy = argv[i];
		if (is_bench(argv[i]))
			ctx->bench_flag = 1;
		i++;
	}
	ctx->a = get_stack(argc - i, argv + i);
	ctx->b = load_stack(ctx->a->size, NULL);
	init_context(ctx);
}
