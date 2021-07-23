#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct		s_list
{
	int				n;
	struct s_list	*next;
	struct s_list	*bef;
}					t_list;

t_list				*ft_lstnew(int n);
void				ft_lst_merge(t_list **a, t_list *b);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_last(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstdel_front(t_list **lst);
void				ft_lstclear(t_list **lst);
int					ft_lstsorted(t_list *lst);
int					ft_lstiseq(t_list *lst1, t_list *lst2);

#endif
