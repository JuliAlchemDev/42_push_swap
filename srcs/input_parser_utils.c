/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 20:36:30 by aserio            #+#    #+#             */
/*   Updated: 2026/08/03 20:36:31 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	count_values(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int	needs_expansion(int size, char **nums)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strchr(nums[i], ' '))
			return (1);
		i++;
	}
	return (0);
}

static char	*join_all(int size, char **nums)
{
	char	*joined;
	int		total_len;
	int		i;
	int		pos;

	total_len = 0;
	i = 0;
	while (i < size)
		total_len += ft_strlen(nums[i++]) + 1;
	joined = malloc(sizeof(char) * total_len);
	if (!joined)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < size)
	{
		pos += ft_strlcpy(joined + pos, nums[i], total_len - pos);
		if (i < size - 1)
			joined[pos++] = ' ';
		i++;
	}
	joined[pos] = '\0';
	return (joined);
}

t_stack	*get_stack(int size, char **nums)
{
	t_stack	*stack;
	char	*joined;
	char	**expanded;
	int		real_size;

	if (!needs_expansion(size, nums))
		return (load_stack(size, nums));
	joined = join_all(size, nums);
	if (!joined)
		return (NULL);
	expanded = ft_split(joined, ' ');
	free(joined);
	if (!expanded)
		return (NULL);
	real_size = count_values(expanded);
	stack = load_stack(real_size, expanded);
	free_split(expanded);
	return (stack);
}
