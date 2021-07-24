#include "inst.h"

void	write_inst(t_inst *inst, char *str, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		inst->inst[inst->c++] = str[i];
}

char	bef_inst(t_inst *inst, int i, int *j)
{
	while (--i >= 0 && inst->inst[i] == -1)
		;
	if (i < 0)
		return (-1);
	*j = i;
	return (inst->inst[i]);
}

int		set_ff(t_inst *inst, int a, int b)
{
	inst->inst[a] = -1;
	inst->inst[b] = -1;
	inst->better -= 2;
	return (1);
}

int		set_fff(t_inst *inst, int a, int b, int c)
{
	inst->inst[a] = -1;
	inst->inst[b] = -1;
	inst->inst[c] = -1;
	inst->better -= 3;
	return (1);
}

int     useless_inst(t_inst *inst, int i, int j)
{
	if (inst->inst[i] == 0 && inst->inst[j] == 0)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 1 && inst->inst[j] == 1)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 2 && inst->inst[j] == 2)
		return (set_fff(inst, i, j, j));
	else if (inst->inst[i] == 3 && inst->inst[j] == 4)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 4 && inst->inst[j] == 3)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 5 && inst->inst[j] == 8)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 6 && inst->inst[j] == 9)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 7 && inst->inst[j] == 10)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 8 && inst->inst[j] == 5)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 9 && inst->inst[j] == 6)
		return (set_ff(inst, i, j));
	else if (inst->inst[i] == 10 && inst->inst[j] == 7)
		return (set_ff(inst, i, j));
	return (0);
}

int     messy_inst(t_inst *inst, int i, int j)
{
	int     flag;

	flag = 0;
	if ((inst->inst[i] | inst->inst[j]) == 1)
	{
		flag++;
		inst->inst[i] = 2;
		inst->inst[j] = -1;
	}
	else if ((inst->inst[i] == 5 && inst->inst[j] == 6)
		|| (inst->inst[i] == 6 && inst->inst[j] == 5))
	{
		flag++;
		inst->inst[i] = 7;
		inst->inst[j] = -1;
	}
	else if (inst->inst[i] * inst->inst[j] == 72)
	{
		flag++;
		inst->inst[i] = 10;
		inst->inst[j] = -1;
	}
	inst->better -= flag;
	return (flag);
}

int		comp_inst(t_inst *inst)
{
	int		flag;
	int		i;
	int		j;

	flag = 0;
	i = 0;
	while (++i < inst->c)
		if (inst->inst[i] != -1 && bef_inst(inst, i, &j) != -1)
		{
			flag = useless_inst(inst, i, j);
			flag = messy_inst(inst, i, j);
		}
	return (flag);
}

void	print_inst(t_inst *inst, int i)
{
	while (++i < inst->c)
	{
		if (inst->inst[i] == 0)
			write(1, "sa\n", 3);
		else if (inst->inst[i] == 1)
			write(1, "sb\n", 3);
		else if (inst->inst[i] == 2)
			write(1, "ss\n", 3);
		else if (inst->inst[i] == 3)
			write(1, "pa\n", 3);
		else if (inst->inst[i] == 4)
			write(1, "pb\n", 3);
		else if (inst->inst[i] == 5)
			write(1, "ra\n", 3);
		else if (inst->inst[i] == 6)
			write(1, "rb\n", 3);
		else if (inst->inst[i] == 7)
			write(1, "rr\n", 3);
		else if (inst->inst[i] == 8)
			write(1, "rra\n", 4);
		else if (inst->inst[i] == 9)
			write(1, "rrb\n", 4);
		else if (inst->inst[i] == 10)
			write(1, "rrr\n", 4);
	}
}