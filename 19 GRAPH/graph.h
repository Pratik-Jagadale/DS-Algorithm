#pragma once

/* sybolic constants */
#define TRUE 1
#define FALSE 0
#define SUCCESS 1

#define G_VERTEX_EXISTS 2
#define G_INAVLID_VERTEX 3
#define G_EDGE_EXITS 4
#define G_INVALID_EDGE 5

typedef int vertex_t;
typedef int status_t;
typedef struct hnode hnode_t;
typedef hnode_t hlist_t;
typedef struct vnode vnode_t;
typedef vnode_t vlist_t;
typedef struct graph graph_t;

struct hnode
{
    vertex_t v;
    hnode_t *h_next;
    hnode_t *h_prev;
};

struct vnode
{
    vertex_t v;
    hlist_t *ph_head_node;
    vnode_t *v_next;
    vnode_t *v_prev;
};

struct graph
{
    vlist_t *pv_head_node;
    unsigned long nr_vertices;
    unsigned long nr_edges;
};

/* graph Interfaces Routines */
graph_t create_graph(void);

status_t add_vertex(graph_t *g, vertex_t new_vertex);
status_t remove_vertex(graph_t *g, vertex_t new_vertex);
status_t add_edge(graph_t *g, vertex_t v_start, vertex_t v_end);
status_t remove_edge(graph_t *g, vertex_t v_start, vertex_t v_end);

void show_graph(graph_t *g, const char *msg);
status_t destroy_graph(graph_t **pp_g);

/* Graph Helper Routines -> Vertical List Management -> Vertical List Iternafces */
vlist_t *v_create_list(void);
status_t *v_insert_end(vlist_t *pv_list, vertex_t new_vertex);

/* Graph Helper Routines -> Vertical List Management -> Vertical List Helper routines */
void v_generic_insert(vnode_t *pv_beg, vnode_t *pv_mid, vnode_t *pv_end);
void v_generic_delete(vnode_t *pv_delete_node);
vnode_t *v_search_node(vlist_t *pv_list, vertex_t search_vertex);
vnode_t *v_get_list_node(vertex_t new_vertex);

/* Graph Helper routines -> Horizontal List Management -> Horozontal List Iterfaces */
hlist_t *h_create_list(void);
status_t h_insert_end(hlist_t *ph_list, vertex_t new_vertex);

/* Graph Helper routines -> Horizontal List Management -> Horizonatal list helper */
void h_generic_insert(hnode_t *ph_beg, hnode_t *ph_mid, hnode_t *ph_end);
void g_generic_delete(hnode_t *ph_delete_node);
hnode_t *h_search_node(hlist_t *ph_list, vertex_t search_vertex);
hnode_t *h_get_list_node(vertex_t new_vertex);

/* graph helper routines -> general purpose */
void *xmalloc(size_t nr_bytes);
