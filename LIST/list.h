#ifndef _LIST_H
#define _LIST_H


#define SUCCESS				1
#define FAILURE				0
#define LIST_EMPTY			3
#define LIST_DATA_NOT_FOUND 3

typedef int data_t ;
typedef int ret_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;

struct node
{
	data_t data;
	struct node* prev;
	struct node* next;
}

/*interface Routines*/

list_t* create_list(void);

/*Interface Routine -> insertion routines */
ret_t insert_start(list_t* p_list, data_t data_t_new_data);
ret_t insert_end(list_t* p_list, data_t new_data);
ret_t insert_after(list_t* p_list, data_t e_data, data_t new_data);
ret_t insert_before(list_t* p_list, data_t e_data, data_t new_data);

/*Interface Routine -> get / pop rotines */
ret_t get_start(list_t* p_list, data_t* p_start_data);
ret_t get_end(list_t* p_list, data_t* p_end_data);
ret_t pop_start(list_t* p_list, data_t* p_start_data);
ret_t pop_end(list_t* p_list, data_t* p_end_data);

/* Interface Routines -> Data removal rotines */
ret_t remove_beg(list_t* p_list);
ret_t remove_end(data_t* p_list);
ret_t remove_data(list_t* p_list, data_t r_data);

/* Inertface Routine -> Misc */
ret_t find_list(list_t* p_list, data_t f_data);
let_t get_length(list_t* p_list);
ret_t is_list_empty(list_t* p_list);
void show(list_t* p_list);

/* interface Routines->  destroy routines */
ret_t destroy_list(list_t* p_list);


/*Helper routines*/
void generic_insert(node_t* p_peg, node_t* p_mid, node_t* p_end);
void generic_delete(node_t* p_delete_node);
node_t* get_node(data_t new_data);
node_t* search_node(node_t* p_list, data_t data);

#endif/* _LIST_H */