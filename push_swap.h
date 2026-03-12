/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:11 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 18:35:39 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				nb;
	int				index;
	int				temp_index;
	struct s_list	*next;
	struct s_list	*prev;

}					t_list;

typedef struct s_count
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;

	float			disorder;
	int				bench_active;

}					t_count;

int					ft_printf(char const *str, ...);
int					ft_printchr(int c);
int					ft_printstr(char *s);
int					ft_printnbr(int n);
int					ft_printunbr(unsigned int n);
int					ft_printptr(void *c);
int					ft_printhexa(unsigned long c, const char *base);

float				ft_compute_disorder(t_list *stack);
long				ft_atoi(const char *str);

int					push_swap(int argc, char **argv);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
int					stack_size(t_list *stack_a);
int					ft_sqrt(int nb);
int					find_min(t_list *stack_a);
int					find_max(t_list *stack_a);
int					ft_numlen(int n);
int					find_min_index(t_list *stack_a);
int					short_way_medium(t_list **stack, int i, int range);
int					short_way_simple_adj(t_list **stack);
int					argv_isnumber(char *argv);
int					not_equal_number(t_list *stack_a, int new_number);
int					ft_switch(char *strat, t_list *stack_a,
						t_count **count_list);

char				*ft_itoa(int n);
char				**ft_split(const char *s, char c);

size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);

t_list				*ft_new_node(int nb);
t_list				*ft_lstlast(t_list *lst);

void				ft_free_split(char **split);
void				initialize_list(t_count **count_list);
void				ft_lstclear(t_list **lst);

void				benchmark(t_count *count_list, int type);
void				assign_index(t_list **stack_a);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				arg_control(char **argv, t_count **count_list);
void				rotate(t_list **stack_a, t_count **count_list, int count,
						int size);

void				sa_move(t_list **stack, t_count **count_list);
void				sb_move(t_list **stack, t_count **count_list);
void				ss_move(t_list **stack_a, t_list **stack_b,
						t_count **count_list);

void				pa_move(t_list **stack_a, t_list **stack_b,
						t_count **count_list);
void				pb_move(t_list **stack_a, t_list **stack_b,
						t_count **count_list);

void				ra_move(t_list **stack, t_count **count_list);
void				rb_move(t_list **stack, t_count **count_list);
void				rr_move(t_list **stack_a, t_list **stack_b,
						t_count **count_list);

void				rra_move(t_list **stack, t_count **count_list);
void				rrb_move(t_list **stack, t_count **count_list);
void				rrr_move(t_list **stack_a, t_list **stack_b,
						t_count **count_list);

void				ft_simple(t_list **stack_a, t_count **count_list);
void				ft_medium(t_list **stack_a, t_count **count_list);
void				ft_complex(t_list **stack_a, t_count **count_list);
void				ft_adaptive(t_list **stack_a, t_count **count_list);
void				tiny_sort(t_list **stack_a, t_count **count_list);

#endif
