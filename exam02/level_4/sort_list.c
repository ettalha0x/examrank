#include<unistd.h>
//#include "list.h"

typedef struct s_list
{
	int			data;
	struct s_list	*next;
}	t_list;


t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head;
	head = lst;
	int temp = 0;
	while (lst->next)
	{
		if (!cmp(lst->data, lst->next->data))
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return head;
}
