/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_tree.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 21:02:24 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 22:40:57 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BINARY_TREE_H

# define BINARY_TREE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	Btree
{
	int				value;
	struct Btree	*tleft;
	struct Btree	*tright;
	struct Btree	*parent;
}				Tree;

Tree	*new_tree(int x);
void	clean_tree(Tree *tr);
Tree	*join_tree(Tree *left, Tree *right, int node);
void	print_tree_prefix(Tree *tr);
void	print_tree_postfix(Tree *tr);
int		count_tree_node(Tree *tr);

#endif
