#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void f(void *data)
{
	
	int i = 0;
	while(data(char)[i])
	{
		data(char)[i] -= 32;
		i++;
	}
}
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if(!begin_list)
		return ;
	t_list *tmp = begin_list;
	while(begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
	begin_list = tmp;
}

int main(void)
{
	t_list *head = malloc(sizeof(t_list));
	char str[] = "hello";
	head->data = strdup(str);

	t_list *second = malloc(sizeof(t_list));
	char tr[] = "world";
	second->data = strdup(tr);
	head->next = second;

	t_list *third = malloc(sizeof(t_list));
	char r[] = "last";
	third->data = strdup(r);
	second->next = third;
	ft_list_foreach(head, f);
	if(!head)
		printf("dfdf");
	while(head)
	{
		printf("%s\n", (char *)head->data);
		head = head->next;
	}
	free(head);
	free(second);
	free(third);
}