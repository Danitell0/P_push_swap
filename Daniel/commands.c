#include "pushswap.h"

void	swap_cmd(t_stack *lst)
{
	int	val1;
	int	val2;
	int temp;

	val1 = lst->content;
	lst = lst->next;
	val2 = lst->content;
	temp = val1;
	val1 = val2;
	val2 = temp;
}
