#include<stdio.h>
#include <dcll.h>


list_t* create_list(void)
{
	list_t* p_list = NULL;
	p_list = (list_t*)malloc(sizeof(list_t));
	if(p_list == NULL)
	{
		printf("ERROR WHILE CREATING LIST\n");
		return ;
	}
	p_list->data = 0;
	p_list->next = p_list;
	p_list->prev = p_list;
	return p_list;
}

status_t insert_beg(list_t* p_list, data_t new_data)
{

}
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t new_data);
status_t insert_before(list_t* p_list, data_t new_data);

status_t get_beg(list_t* p_list, data_t *p_data);
status_t get_end(list_t* p_list, data_t* p_data);
status_t pop_beg(list_t* p_list, data_t* p_data);
status_t pop_end(list_t* p_list, data_t* p_data);

status_t remove_beg(list_t* p_list);
status_t remove_end(list_t *p_list);
status_t remove_data(list_t *p_list, data_t* r_data);

len_t get_length(list_t* p_list);
bool contains(list_t* p_list, data_t serch_data);
bool is_list_empty(loist_t* p_list);
int get_repeate_count(list_t* p_list, data_t serch_data);
void show_list(list_t* p_list, const char* msg);

list_t *concate_list(list_t* p_list1 ,list_t* p_list2 );

/* list auxillary routines */

void generic_insert(node_t *p_beg, node_t* p_mid, node_t* p_end)
{
	p_mid->prev = p_beg;
	p_mid->next = p_end;
	p_beg->next = p_mid;
	p_end->prev = p_mid;
}

void generic_delete(node_t* p_delete_node)
{

}

node_t* locate_node(list_t* p_list, data_t search_data);
node_t* get_list_node(data_t new_data);

/* memory allocation routines */

void* xmalloc(size_t size_in_bytes)
{
	void* p = NULL;
	p = malloc(size_in_bytes);
	if(p == NULL)
	{
		printf("OUT OF MEMORY...malloc Failed\n");
		return ;
	}
	return p;
}
