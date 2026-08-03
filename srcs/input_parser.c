/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:52:57 by aserio            #+#    #+#             */
/*   Updated: 2026/08/03 20:45:00 by aserio           ###   ########.fr       */
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

static int	is_option(char *s)
{
	if (!ft_strncmp(s, "--", 2))
		return (1);
	return (0);
}

static t_context	*init_context(t_context *ctx)
{
	t_context	*ctx;

	ctx = malloc(sizeof(t_context));
	ctx->bench_flag = 0;
	ctx->debug_flag = 0;
	ctx->strategy = NULL;
	ctx->total_ops = 0;
	init_operations_list(ctx);
	return (ctx);
}

t_context	*input_parser(int argc, char *argv[])
{
	t_context	*ctx;
	int			i;

	ctx = init_context(ctx);
	i = 1;
	while ((i < argc) && is_option(argv[i]))
	{
		if (is_strategy(argv[i]))
			ctx->strategy = argv[i];
		if (!ft_strcmp(argv[i], "--bench"))
			ctx->bench_flag = 1;
		if (!ft_strcmp(argv[i], "--debug"))
			ctx->debug_flag = 1;
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
