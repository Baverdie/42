#include "push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
		*stack = new;
	else
	{
		last = ft_stacklast(*stack);
		last->next = new;
	}
	return ;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = new->value;
	new->value = tmp;
	new->next = *stack;
	*stack = new;
	return ;
}

int	ft_verif_nb(char const *str)
{
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}

t_stack *fill_struct(int ac, char **av)
{
	int	i;
	int	j;
	char ***tab;
	t_stack *stack;

	i = 1;
	j = 0;
	tab = malloc(sizeof(int) * ac);
	while (i < ac)
	{
		tab[j] = ft_split(av[i], ' ');
		j++;
		i++;
	}
	while (tab[i])
	{
		if (ft_verif_nb(tab[i]))
		{
			stack = ft_stacknew(atoi(tab[i]));
			i++;
		}
	}
	ft_free(tab);
	return (stack);
}

int	verif_double(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	while (stack->next)
	{
		while (stack->value != tmp)
			stack = stack->next;
		if (stack->value == tmp)
			return (0);
		tmp = stack->value;
		stack = stack->next;
	}
	return (1);
}

//j'espere que le debut étais pas trop dur car voici un premier gros defi
// tu dois "lisser" toutes les valeur, a partir de 0, et il n'y aura pas d'ecart superieur a 1
// pour ca tu va assiger a chaque maillon->nb une valeur
// qui depend de toute les nb_init de la list
// 0 1000 2 2000 -> 0 2 1 3
// -4 1 9 5 2 8 4 -> 0 1 6 4 2 5 3
// une vision simple de le voir/le coder:
//compter combien d'element dans toute la liste possede un nb_init en dessous du nb_init conserner
void	replace_nb_init(t_stack *stack)
{
	/*assigne pour chaque maillon, un nb,
	ce nb est la possition finale dans la liste trier qu'il aura*/
}



// mtn que tu a modifier tous et simplifier les nb_init dans nb
// a partir de mtn tu ne touche plus du tout a nb_init,
// uniquement a nb

int	is_sorted(t_stack *stack_a)
{
	t_stack	*head;

	head = stack_a;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}



// il va falloir attendre la v2 pour les tests des fonctions a partir de mtn
//, et pour les explications plus soffistiquer de la sutie:)
// mais tu peux quand meme les faire sans aide ? :)

void	sa(t_stack *stack_a)
{
	int	tmp;

	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
	ft_printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{

}

void	pb(t_stack *stack_a, t_stack *stack_b)
{

}

void	ra(t_stack *stack_a)
{
	int	tmp;

	tmp = stack_a->value;
	while (stack_a->next)
	{
		stack_a->value = stack_a->next->value;
		stack_a = stack_a->next;
	}
	stack_a->value = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	int	tmp;

	tmp = stack_b->value;
	while (stack_b->next)
	{
		stack_b->value = stack_b->next->value;
		stack_b = stack_b->next;
	}
	stack_b->value = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	tmp = stack_a->value;
	while (stack_a->next)
	{
		stack_a->value = stack_a->next->value;
		stack_a = stack_a->next;
	}
	stack_a->value = tmp;
	tmp = stack_b->value;
	while (stack_b->next)
	{
		stack_b->value = stack_b->next->value;
		stack_b = stack_b->next;
	}
	stack_b->value = tmp;
	ft_printf("rr\n");
}

// void	rra(t_stack *stack_a)
// {

// }

// void	rrb(t_stack *stack_b)
// {
// 	/*envoie l'element en bas de la pile b -> en haut de la pile b
// 	print "rrb"*/
// }

// void	rrr(t_stack *stack_a, t_stack *stack_b)
// {
// 	/*effectue rra et rrb
// 	print "rrr"*/
// }
