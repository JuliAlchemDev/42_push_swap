/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:52:57 by aserio            #+#    #+#             */
/*   Updated: 2026/08/04 15:32:28 by aserio           ###   ########.fr       */
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

static t_stack	*get_stack(size_t size, char **nums)
{
	t_stack	*stack;
	char	*argv_join;
	char	*argv_tmp;
	size_t	c;
	
	c = 0;
	argv_join = ft_calloc(sizeof(char), 2);
	while (c < size)
	{
		argv_tmp = ft_strjoin(argv_join, nums[c]);
		free(argv_join);
		argv_join = ft_strjoin(argv_tmp, " ");
		free(argv_tmp);
		c++;
	}
	nums = ft_split(argv_join, ' ');
	size = 0;
	while (nums[size])
		size++;
	stack = load_stack(size, nums);
	if (!stack)
		return (NULL);
	return (stack);
}

static void	init_context(t_context *ctx)
{
	ctx->bench_flag = 0;
	ctx->strategy = NULL;
	ctx->total_ops = 0;
	init_operations_list(ctx);
}

t_context	*input_parser(int argc, char *argv[])
{
	int			i;
	t_context	*ctx;

	ctx = malloc(sizeof(t_context));
	init_context(ctx);
	i = 1;
	while ((i < argc) && (is_strategy(argv[i])
			|| is_bench(argv[i])))
	{
		if (is_strategy(argv[i]))
			ctx->strategy = argv[i];
		if (is_bench(argv[i]))
			ctx->bench_flag = 1;
		i++;
	}
	if (!ctx->strategy)
		ctx->strategy = "--adaptive";
	ctx->a = get_stack(argc - i, argv + i);
	if (!ctx->a)
		error(ctx);
	ctx->disorder = compute_disorder(ctx->a);
	ctx->b = load_stack(ctx->a->size, NULL);
	if (!ctx->b)
		error(ctx);
	return (ctx);
}
