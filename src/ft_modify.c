/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:32:32 by kamofoke          #+#    #+#             */
/*   Updated: 2019/09/12 11:35:10 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_sort_time(t_files *curr, t_files *node)
{
	if (ft_strcmp(curr->next->name, node->name) > 0)
	{
		node->next = curr->next;
		curr->next = node->next; // print time when it was modified
	}
	else
	{
		while (curr->next != NULL &&
				curr->next->mtime - node->mtime == 0)
		{
			curr = curr->next;
			node->next = curr->next;
			curr = node->next;
		}
	}
}

void	ft_sort_time_b(t_files **stack, t_files new_node)
{
	t_files *curr;

	if (*stack == NULL || (*stack)->mtime - new_node->mtime < 0)
	{
		new_node->next = *stack;
		*stack = new_node;
	}
	else
	{
		curr = *stack;
		while (curr->next != NULL &&
				curr->next->mtime - new_node->mtime > 0)
			curr = curr->next;
		if (curr->next != NULL &&
				curr->next->mtime - new_node->mtime == 0)
			ft_sort_time(curr, new_node);
		else
		{
			curr = curr->next;
			node->next = curr->next;
			curr = node->next;
		}
}
