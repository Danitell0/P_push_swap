#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}	t_list;

typedef	struct simplify
{
	int	value;
	int	original_pos;
	int	simple;
}	t_list;

#endif