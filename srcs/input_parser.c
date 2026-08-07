/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:52:57 by aserio            #+#    #+#             */
/*   Updated: 2026/08/07 13:41:37 by aserio           ###   ########.fr       */
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
	if (is_strategy(s)
		|| !ft_strcmp(s, "--bench"))
		return (1);
	return (0);
}

static t_context	*init_context(void)
{
	t_context	*ctx;

	ctx = malloc(sizeof(t_context));
	ctx->a = NULL;
	ctx->b = NULL;
	ctx->bench_flag = 0;
	ctx->strategy = NULL;
	ctx->total_ops = 0;
	init_operations_list(ctx);
	return (ctx);
}

static	void	set_option(char *option, t_context *ctx)
{
	if (is_strategy(option))
	{
		if (ctx->strategy == NULL)
			ctx->strategy = option;
		else
			exit_with_code(1, ctx);
	}
	if (!ft_strcmp(option, "--bench"))
	{
		if (ctx->bench_flag)
			exit_with_code(1, ctx);
		else
			ctx->bench_flag = 1;
	}
}

t_context	*input_parser(int argc, char *argv[])
{
	t_context	*ctx;
	int			i;

	ctx = init_context();
	i = 1;
	while ((i < argc) && is_option(argv[i]))
	{
		set_option(argv[i], ctx);
		i++;
	}
	if (!ctx->strategy)
		ctx->strategy = "--adaptive";
	if (argc - i == 0)
		exit_with_code(0, ctx);
	ctx->a = get_stack(argc - i, argv + i);
	if (!ctx->a)
		exit_with_code(1, ctx);
	ctx->disorder = compute_disorder(ctx->a);
	ctx->b = load_stack(ctx->a->size, NULL);
	if (!ctx->b)
		exit_with_code(1, ctx);
	return (ctx);
}
