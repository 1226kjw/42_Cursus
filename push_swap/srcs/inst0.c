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

int	set_ff(t_inst *inst, int a, int b)
{
	inst->inst[a] = -1;
	inst->inst[b] = -1;
	inst->better -= 2;
	return (1);
}

int	set_fff(t_inst *inst, int a, int b, int c)
{
	inst->inst[a] = -1;
	inst->inst[b] = -1;
	inst->inst[c] = -1;
	inst->better -= 3;
	return (1);
}
