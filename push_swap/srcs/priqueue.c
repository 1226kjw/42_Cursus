#include "priqueue.h"
#include "board.h"
int		max_heap;
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
	if (root->count > max_heap)
		max_heap=root->count;
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
		child = root->heap[child].f < root->heap[child + 1].f ? child : child + 1;
	while (child <= root->count && root->heap[parent].f > root->heap[child].f)
	{
		node_swap(&root->heap[parent], &root->heap[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= root->count)
			child = root->heap[child].f < root->heap[child + 1].f ? child : child + 1;
	}
	return (result);
}
