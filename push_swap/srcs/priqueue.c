#include "priqueue.h"
#include "board.h"

t_priq	*priq_init(t_board *bd)
{
	t_priq	*root;
	t_node	node;

	root = (t_priq *)malloc(sizeof(t_priq));
	root->count = 0;
	node.g = 0;
	node.f = calc_h(bd);
	node.hist = ft_strdup("");
	node.bd = board_cp(bd);
	priq_push(root, node);
	return (root);
}

void	node_swap(t_node *n1, t_node *n2)
{
	t_node	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void	priq_push(t_priq *root, t_node data)
{
	int		child;
	int		parent;

	if (root->count >= MAXQUEUE)
		err_msg("heap: max_push\n");
	root->heap[++root->count] = data;
	child = root->count;
	parent = child / 2;
	while (child > 1 && root->heap[parent].f > root->heap[child].f)
	{
		node_swap(&root->heap[parent], &root->heap[child]);
		child = parent;
		parent = child / 2;
	}
}

t_node	priq_pop(t_priq *root)
{
	t_node	result;
	int		parent;
	int		child;

	if (root->count <= 0)
		err_msg("heap: empty_pop\n");
	result = root->heap[1];
	node_swap(&root->heap[1], &root->heap[root->count--]);
	parent = 1;
	child = 2;
	if (child + 1 <= root->count)
		child = ter_tmp(root->heap[child].f < root->heap[child + 1].f,
				child, child + 1);
	while (child <= root->count && root->heap[parent].f > root->heap[child].f)
	{
		node_swap(&root->heap[parent], &root->heap[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= root->count)
			child = ter_tmp(root->heap[child].f < root->heap[child + 1].f,
					child, child + 1);
	}
	return (result);
}

void	priq_free(t_priq *root)
{
	int		i;

	i = 0;
	while (++i <= root->count)
	{
		free(root->heap[i].hist);
		board_clear(root->heap[i].bd);
	}
	free(root);
}
