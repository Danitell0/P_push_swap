#ifndef PUSHSWAP_H
# define PUSHSWAP_H

// # include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef	struct simplify
{
	int	value;
	int	original_pos;
	int	simple;
}	t_list;

void	swap_cmd(t_stack *lst);

#endif