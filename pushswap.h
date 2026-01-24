/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:22:57 by khebert           #+#    #+#             */
/*   Updated: 2026/01/24 18:53:01 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_turk_data
{
	int	is_ra;
	int	is_rb;
	int	cost_a;
	int	cost_b;
	int	pos_cible;
	int	pos_b;
	int	cost;
	int	cheapest_value;
	int	cible;
}	t_turk_data;

/* FT_ALGO */

int			size_of_stack(t_stack **stack);
int			find_min(t_stack **stack);
void		ft_three_big_number(t_stack *stack_a, int *big1,
				int *big2, int *big3);
int			find_cible(t_stack **stack_a, int value);
int			find_position(t_stack *stack, int value);

/* FT_COST.C */

int			cost_a(t_stack *stack_a, int cible);
int			cost_b(t_stack *stack_b, int value);
int			calculate_the_cost(t_stack **stack_b, t_stack **stack_a,
				t_turk_data *data);

/* FT_FIVE_ARGS.C */

void		pos_five_args(t_stack **stack_a, int pos);
void		five_args(t_stack **stack_a, t_stack **stack_b);

/* FT_TURK.C */

void		ft_take_cible(t_stack **stack_a, t_stack **stack_b,
				t_turk_data *data);
void		ft_cost(t_stack **stack_b, t_stack **stack_a, t_turk_data *data);
void		ft_cost_2(t_stack **stack_b, t_stack **stack_a, t_turk_data *data);
void		ft_total_sort(t_stack **stack_a, t_turk_data *data);
void		ft_turk_algo(t_stack **stack_a, t_stack **stack_b);

/* FT_CONDITIONS.C */

int			is_sorted(t_stack *stack);
int			is_double(t_stack *stack);
void		two_args(t_stack **stack);
void		three_args(t_stack **stack);

/* FT_SPLIT.C */

int			count_word(char const *str, char sep);
void		write_word(char *dst, char const *str_base, int len, int start);
char		**alloc_check(char const *s, char c);
int			sep_check(char const *s, char c, int i);
char		**ft_split(char const *s, char c);

/* FT_STRUCT.C */

t_stack		*ft_stack_new(int value);
t_stack		*ft_last(t_stack **stack);
t_stack		*ft_middle(t_stack **stack);
void		ft_addtoback(t_stack **stack, t_stack *new);
int			ft_min(t_stack *stack);

/* FT_LIBFT.C */

long		ft_atoi(const char *str);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *str, int fd);

/* FT_MAIN.C */

int			is_valid_number(char *str);
int			verificate_errors(char **argv, t_stack *stack_a, int i);
int			check_errors(int argc, char **argv, t_stack *stack_a);
int			main(int argc, char **argv);

/* FT_PARSING.C */

t_stack		*ft_split_args(char *argv);
t_stack		*ft_parse_args(int argc, char *argv[]);
void		ft_print_stack(t_stack *stack);
void		free_stack(t_stack **stack);

/* FT_PUSH.C */

void		push(t_stack **dst, t_stack **src);
void		push_pa(t_stack **stack_a, t_stack **stack_b);
void		push_pb(t_stack **stack_a, t_stack **stack_b);

/* FT_REVERSE_ROTATE.C */

void		reverse_rotate(t_stack **stack);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_b, t_stack **stack_a);

/* FT_ROTATE.C */

void		rotate(t_stack **stack);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

/* FT_SWAP.C */

void		swap(t_stack **stack_a);
void		swap_sa(t_stack **stack_a);
void		swap_sb(t_stack **stack_b);
void		swap_ss(t_stack **stack_a, t_stack **stack_b);
int			size_of_stack(t_stack **stack);

#endif