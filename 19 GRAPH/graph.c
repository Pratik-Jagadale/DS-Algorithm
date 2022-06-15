#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* graph Interfaces Routines */
graph_t create_graph(void);

status_t add_vertex(graph_t *g, vertex_t new_vertex);
status_t remove_vertex(graph_t *g, vertex_t new_vertex);
status_t add_edge(graph_t *g, vertex_t v_start, vertex_t v_end);
status_t remove_edge(graph_t *g, vertex_t v_start, vertex_t v_end);

void show_graph(graph_t *g, const char *msg);
status_t destroy_graph(graph_t **pp_g);

/* Graph Helper Routines -> Vertical List Management -> Vertical List Iternafces */
vlist_t *v_create_list(void)
{
    vnode_t *pv_head_node = NULL;
    pv_head_node = (vnode_t *)xmalloc(sizeof(vnode_t));

    pv_head_node->ph_head_node = NULL;
    pv_head_node->v_next = pv_head_node;
    pv_head_node->v_prev = pv_head_node;
    return (pv_head_node);
}

status_t *v_insert_end(vlist_t *pv_list, vertex_t new_vertex)
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list);
    return (SUCCESS);
}

/* Graph Helper Routines -> Vertical List Management -> Vertical List Helper routines */
void v_generic_insert(vnode_t *pv_beg, vnode_t *pv_mid, vnode_t *pv_end)
{
    pv_mid->v_next = pv_end;
    pv_mid->v_prev = pv_beg;
    pv_mid->v_next = pv_end;
    pv_mid->v_prev = pv_beg;
}

void v_generic_delete(vnode_t *pv_delete_node)
{
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next;
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev;
    free(pv_delete_node);
    pv_delete_node = NULL;
}

vnode_t *v_search_node(vlist_t *pv_list, vertex_t search_vertex)
{
    vnode_t *pv_run = NULL;

    for (pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next)
    {
        if (pv_run->v == search_vertex)
            return (pv_run);
    }
    return (NULL);
}

vnode_t *v_get_list_node(vertex_t new_vertex)
{
    vnode_t *pv_new_node = NULL;

    pv_new_node = (vnode_t *)xmalloc(sizeof(vnode_t));

    pv_new_node->v = new_vertex;
    pv_new_node->ph_head_node = h_create_list();
    pv_new_node->v_next = NULL;
    pv_new_node->v_prev = NULL;

    return (pv_new_node);
}

/* Graph Helper routines -> Horizontal List Management -> Horizontal List Iterfaces */
hlist_t *h_create_list(void)
{
    hlist_t *ph_head_node = NULL;

    ph_head_node = h_get_list_node(-1);
    ph_head_node->h_next = ph_head_node;
    ph_head_node->h_prev = ph_head_node;

    return (ph_head_node);
}
status_t h_insert_end(hlist_t *ph_list, vertex_t new_vertex)
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex), ph_list);
    return (SUCCESS);
}

/* Graph Helper routines -> Horizontal List Management -> Horizonatal list helper */
void h_generic_insert(hnode_t *ph_beg, hnode_t *ph_mid, hnode_t *ph_end)
{
    ph_mid->h_next = ph_beg;
    ph_mid->h_prev = ph_end;
    ph_beg->h_next = ph_mid;
    ph_end->h_prev = ph_mid;
}

void g_generic_delete(hnode_t *ph_delete_node)
{
    ph_delete_node->h_prev = ph_delete_node->h_next;
    ph_delete_node->h_next - ph_delete_node->h_prev;
    free(ph_delete_node);
    ph_delete_node = NULL;
}

hnode_t *h_search_node(hlist_t *ph_list, vertex_t search_vertex)
{
    hnode_t *ph_run = NULL;

    for (ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next)
    {
        if (ph_run->v == search_vertex)
        {
            return ph_run;
        }
    }
    return NULL;
}

hnode_t *h_get_list_node(vertex_t new_vertex)
{
    hnode_t *ph_new_node = NULL;

    ph_new_node = (hnode_t *)xmalloc(sizeof(hnode_t) * 1);
    ph_new_node->v = new_vertex;
    ph_new_node->h_next = NULL;
    ph_new_node->h_prev = NULL;
    return ph_new_node;
}

/* graph helper routines -> general purpose */
void *xmalloc(size_t nr_bytes)
{
    void *p = NULL;
    p = malloc(nr_bytes);

    if (p == NULL)
    {
        printf("Malloc Failed...");
    }
    return p;
}
