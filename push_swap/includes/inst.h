#ifndef INST_H
# define INST_H
# include <unistd.h>

typedef struct s_inst
{
    char		inst[65536];
    int			c;
    int			better;
}				t_inst;

void	write_inst(t_inst *inst, char *str, int n);
char	bef_inst(t_inst *inst, int i, int *j);
int		set_ff(t_inst *inst, int a, int b);
int		set_fff(t_inst *inst, int a, int b, int c);
int		comp_inst(t_inst *inst);
void	print_inst(t_inst *inst, int i);

#endif
