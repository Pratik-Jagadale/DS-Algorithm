#include <stdio.h>
#include "list.h"

/*interface Routines*/

list_t* create_list(void)
{
	node_t* p_dummy_node = get_node(0);
	p_dummy_node->prev = p_dummy_node;
	p_dummy_node->next = p_dummy_node;
	return (p_dummy_node);
}

/*Interface Routine -> insertion routines */
ret_t insert_start(list_t* p_list, data_t _new_data)
{
	generic_insert(p_list, get_node(new_data), p_list->next);
	return (SUCCESS);
}

ret_t insert_end(list_t* p_list, data_t new_data)
{
	generic_insert(p_list->prev, get_node(new_data), p_list);
	return(SUCCESS);
}

ret_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
	node_t* p_ext_node = search_node(p_list, e_data);
	if(p_ext_node == NULL)
		return (LIST_DATA_NOT_FOUND);

	generic_insert(p_ext_node , get_node(new_data), p_ext_node->next);
	return (SUCCESS);
}

ret_t insert_before(list_t* p_list, data_t e_data, data_t new_data);
{
	node_t* p_ext_node = search_node(p_list, e_data);
	if (p_ext_node == NULL)
		return (LIST_DATA_NOT_FOUND);
	generic_insert(p_ext_node->prev , new_node( new_data), p_ext_node);
	return (SUCCESS);
}

/*Interface Routine -> get / pop rotines */
ret_t get_start(list_t* p_list, data_t* p_start_data)
{
	if(list_is_empty(p_list))
		return (LIST_EMPTY);
	*p_start_data = p_list->next->data;
	return (SUCCESS);
}

ret_t get_end(list_t* p_list, data_t* p_end_data)
{
	if(list_is_empty(p_list))
		return (LIST_EMPTY);
	*p_end_data = p_list->prev->data;
	return (SUCCESS);
}
ret_t pop_start(list_t* p_list, data_t* p_start_data)
{
	if(list_is_empty(p_list))
		return (LIST_EMPTY);
	*p_start_data = p_list->next->data;
	generic_delete(p_list->next);
	return (SUCESS);
}

ret_t pop_end(list_t* p_list, data_t* p_end_data)
{
	if(is_list_empty(p_list))
		retrun (LIST_EMPTY);
	*p_start_data = p_list->prev->data;
	generic_delete(p_list->prev);
	return (SUCCESS);
}

/* Interface Routines -> Data removal rotines */
ret_t remove_beg(list_t* p_list)
{
	if(is_list_empty(p_list))
		return (LIST_EMPTY);
	generic_delete(p_list->next);
	return (SUCCESS);
}

ret_t remove_end(data_t* p_list)
{
	if(is_list_empty(p_list))
		return (LIST_EMPTY);
	generic_delete(p_list->prev);
	return (SUCCESS);
}

ret_t remove_data(list_t* p_list, data_t r_data)
{
	node_t* p_ext_node = search_node(p_list , r_data);
	if(is_list_empty(p_list))
		return (LIST_EMPTY);
	generic_delete(p_ext_node);
	return (SUCCESS);
}

/* Inertface Routine -> Misc */
ret_t find_list(list_t* p_list, data_t f_data)
{
	node_t* p_ext_node = search_node(p_list , f_data);
	if(is_list_empty(p_list))
		return (LIST_EMPTY);
	return (p_ext_node != NULL);
}

let_t get_length(list_t* p_list)
{
	node_t* p_run;
	len_t list_len;
	for(p_run = p_list->next , list_len = 0 ; p_run != p_list ; p_run->next, ++list_len );

	return (list_len);
}

ret_t is_list_empty(list_t* p_list)
{
	return(p_list->prev == p_list && p_list->next == p_list);
}

void show(list_t* p_list)
{
	node_t* p_run;

	puts("[start]<->");

	while(p_run != p_run->data)
	{
		printf("[%d]\n",p_run->data );
		p_run = p_run->next;
	}
	puts("<->[END]");
}

/* interface Routines->  destroy routines */
ret_t destroy_list(list_t* p_list)
{
	node_t* p_run;
	node_t* p_tmp;

	p_run = p_list->next;
	while(p_run != p_list)
	{
		p_tmp = p_run->next;
		free(p_run);
		p_run = p_tmp;
	}
	free(p_list);
	return (SUCCESS);
}



/*Helper routines*/
static void generic_insert(node_t* p_peg, node_t* p_mid, node_t* p_end)
{
	p_mid->next = p_end;
	p_mid->prev = p_beg;
	p_beg->next = p_mid;
	p_end->prev = p_mid;
}

static void generic_delete(node_t* p_delete_node)
{
	p_delete_node->prev->next = p_delete_node->next;
	p_delete_node->next->prev = p_delete_node->prev;
	free(p_delete_node);
}

static node_t* get_node(data_t new_data)
{
	node_t* p_new_node = (node_t*)malloc(szieeof(node_t));
	p__new_node=>data = new_data;
	p_new_node->prev = NULL;
	p__new_node->next = NULL;
	return (p_new_node);
}

static node_t* search_node(node_t* p_list, data_t data)
{
	node_t* p_run;
	p_run = p_list->next;

	while(p_run->data != p_list)
	{
		if(p_run == data)
			return (p_run);
		p_run = p_run->next;
	}
	return (NULL);
}

