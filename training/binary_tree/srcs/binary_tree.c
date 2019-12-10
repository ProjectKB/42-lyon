/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_tree.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 21:02:05 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 22:50:23 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "binary_tree.h"

void	clean_tree(Tree *tr)
{
	if (!tr)
		return;
	printf("Deletion of %d\n", tr->value);
	clean_tree(tr->tleft);
	clean_tree(tr->tright);
	free(tr);
}

Tree	*new_tree(int x)
{
	Tree	*tr;

	if (!(tr = (Tree*)malloc(sizeof(Tree))))
		fprintf(stderr, "Memory allocation error\n");
	tr->value = x;
	tr->parent = NULL;
	tr->tleft = NULL;
	tr->tright = NULL;
	printf("Creation of %d\n", tr->value);
	return (tr);
}

Tree	*join_tree(Tree *left, Tree *right, int node)
{
	Tree *tr = new_tree(node);

	tr->tleft = left;
	tr->tright = right;
	if (left)
		left->parent = tr;
	if (right)
		right->parent = tr;
	return (tr);
}

void	print_tree_prefix(Tree *tr)
{
	if (!tr)
		return;
	if (tr->parent)
		printf("(%d) -> (%d)\n", tr->parent->value, tr->value);
	else
		printf("(%d)\n", tr->value);
	if (tr->tleft)
		print_tree_prefix(tr->tleft);
	if (tr->tright)
		print_tree_prefix(tr->tright);
}

void	print_tree_postfix(Tree *tr)
{
	if (!tr)
		return;
	if (tr->parent)
		printf("(%d) -> (%d)\n", tr->parent->value, tr->value);
	else
		printf("(%d)\n", tr->value);
	if (tr->tright)
		print_tree_prefix(tr->tright);
	if (tr->tleft)
		print_tree_prefix(tr->tleft);
}

int		count_tree_node(Tree *tr)
{
	if (!tr)
		return (0);
	return (count_tree_node(tr->tleft) + count_tree_node(tr->tright) + 1);
}
