/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:23:59 by lmachado          #+#    #+#             */
/*   Updated: 2024/10/17 18:48:39 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../include/push_swap.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;
void				add_to_stack(t_stack **stack_a, int *numbers, int size);
// void				print_stack(t_stack *stack);
void				pb(t_stack **a, t_stack **b);
void				process_b(t_stack **a, t_stack **b);
void				move_cheapest_and_target(t_stack **a, t_stack **b,
						t_stack *cheapest, t_stack *target);
void				adjust_positions(t_stack **b, t_stack *cheapest);
void				adjust_positions_a(t_stack **a, t_stack *target);
void				stacks(t_stack **a, t_stack **b);
void				stacks(t_stack **a, t_stack **b);
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **a);
void				rrb(t_stack **stack);
void				rrr(t_stack **stack_a, t_stack **stack_b);
t_stack				*stack_min(t_stack **a);
t_stack				*stack_max(t_stack **a);
void				order_element_a(t_stack **a);
t_stack				*target_element(t_stack *element, t_stack **a);
int					pos_element(t_stack *element, t_stack *stack);
int					cost(t_stack *element, t_stack **stack);
void				ft_update_cost(t_stack *stack);
int					calc_cost(t_stack *element, t_stack **stack);
int					cost_total(t_stack *target, t_stack *element_b, t_stack **a,
						t_stack **b);
t_stack				*stack_cheapest_element(t_stack **a, t_stack **b);
void				topo_stack_a(t_stack **a);
void				ft_swap(t_stack **stack);
void				ft_push(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
void				rotate_reverse(t_stack **stack);
int					cost(t_stack *element, t_stack **stack);
int					verify_int(char *str);
int					veritfy_space_empty(char *str);
long				ft_strtol(char *nptr, char **end_ptr);
int					verify_order_array(int *number, int size);
int					number_duplicate(int *number, int size);
void				free_array(char **array, int pos);
int					ft_arraylen(char **array);
void				ft_lstfree(t_stack *lst);
void				ft_error(void);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_update_index(t_stack *lst);
t_stack				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*last_value_stack(t_stack *stack);
t_stack				*last_value_prev(t_stack *stack);
int					*convert_args(int ac, char **av, int *size);

#endif
