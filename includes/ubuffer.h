/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubuffer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:02:06 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 21:31:17 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UBUFFER_H
# define UBUFFER_H

# include "gl_include.h"
# include "datamodel.h"
# include "shad_struct.h"

# define NULL_NODE	(t_ubuffernode *)0

typedef struct	s_ubufferlist
{
	GLuint					gl_base;
	char					*gl_name;
	char					*gl_n_name;
	GLuint					gl_id;
	GLuint					gl_nodes_location;
	GLuint					gl_n_nodes_location;

	GLuint					has_parent;
	t_datamodel				datamodel;
	GLint					n_nodes;
	struct s_ubuffernode	*first_node;
}				t_ubufferlist;

typedef struct	s_ubuffernode
{
	GLvoid					*id;

	GLuint					n_datas;
	GLvoid					**datas;

	struct s_ubufferlist	*parent_list;
	struct s_ubuffernode	*parent_node;
	GLint					*parent_index;

	GLint					index;
	struct s_ubufferlist	*list;

	GLuint					n_children;
	GLint					**children_indexes;
	struct s_ubufferlist	**children_lists;
	struct s_ubuffernode	**children_nodes;

	struct s_ubuffernode	*prev;
	struct s_ubuffernode	*next;

	int						has_type;
}				t_ubuffernode;

struct s_context;
struct s_shad_struct;

t_ubufferlist	*ubufferlist_init(t_ubufferlist *list,
				struct s_shad_struct const *shad_struct,
				struct s_context const *context);
t_ubufferlist	*ubufferlist_addnode(t_ubufferlist *const list,
		t_ubuffernode *const node);
t_ubufferlist	*ubufferlist_bind_data(t_ubufferlist *const list,
		const GLuint program_id);
t_ubuffernode	*ubufferlist_fetch_node(t_ubufferlist *const list,
		void *const node_id);
t_ubuffernode	*ubufferlist_fetch_node_from_index(t_ubufferlist *const list,
		const int node_index);

t_ubuffernode	*ubuffernode_new(t_shad_struct const *shad_struct,
		void *const id);
t_ubuffernode	*ubuffernode_bind(t_ubuffernode *const child,
		t_ubuffernode *const parent, const GLuint slot);
t_ubuffernode	*ubuffernode_setdata(t_ubuffernode *const node);
t_ubuffernode	*ubuffernode_subdata(t_ubuffernode *const node);

#endif
