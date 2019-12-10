/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 21:01:26 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 22:44:10 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "binary_tree.h"

int	main(void)
{
	Tree	*tree = join_tree(join_tree(new_tree(8), new_tree(3), 2), new_tree(4), 6);
	print_tree_prefix(tree);
	print_tree_postfix(tree);
	printf("Node number : %d\n", count_tree_node(tree));
	clean_tree(tree);
	return (0);
}
