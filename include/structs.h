/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:03:07 by aserio            #+#    #+#             */
/*   Updated: 2026/06/29 18:50:38 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_stack
{
	int		*data;
	size_t	size;
}	t_stack;

typedef struct s_parsed_input
{
	int		bench_flag;
	char	*strategy;
	t_stack	*stack;
}	t_parsed_input;

#endif
