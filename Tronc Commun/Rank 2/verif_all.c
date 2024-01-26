#include <stdio.h>
#include <stdlib.h>

void	afficher_KO_OK(int i)
{
	if (i == 1)
		printf("ok ");
	else
		printf("ERREUR ");
}

/* si tu modif un prototype de fonction: modif la aussi*/
typedef struct s_stack
{
	int				nb_init;
	int				nb;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_stacknew(int content);
int	ft_stacksize(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_front(t_stack **stack, t_stack *new);

int	ft_verif_nb(char const *str);
t_stack *fill_struct(int ac, char **av);
int	verif_double(t_stack *stack);
void	replace_nb_init(t_stack *stack);
int	is_sorted(t_stack *stack_a);



void	main_stacknew()
{
	printf("stacknew: ");
	t_stack *new = ft_stacknew(1000);
	afficher_KO_OK(new->nb_init == 1000);
	afficher_KO_OK(new->next == NULL);
	printf("\n");
}

void	main_stacksize()
{
	printf("stacksize: ");
	t_stack *new = ft_stacknew(1000);
	afficher_KO_OK(ft_stacksize(new) == 1);
	t_stack *new2 = ft_stacknew(1);
	new->next = new2;
	afficher_KO_OK(ft_stacksize(new) == 2);
	afficher_KO_OK(ft_stacksize(NULL) == 0);
	printf("\n");
}

void	main_stackadd_back()
{
	printf("stackadd_back: ");
	t_stack *new = ft_stacknew(1000);
	t_stack *new2 = ft_stacknew(1);
	t_stack *new3 = ft_stacknew(2);
	ft_stackadd_back(&new, new2);
	ft_stackadd_back(&new, new3);
	afficher_KO_OK(ft_stacksize(new) == 3);
	afficher_KO_OK(new->nb_init == 1000);
	afficher_KO_OK(new->next->nb_init == 1);
	afficher_KO_OK(new->next->next->nb_init == 2);
	printf("\n");
}

void	main_stacklast()
{
	printf("stacklast: ");
	t_stack *new = ft_stacknew(1000);
	t_stack *new2 = ft_stacknew(1);
	t_stack *new3 = ft_stacknew(2);
	new2->next = new3;
	new->next = new2;
	afficher_KO_OK(ft_stacklast(new)->nb_init == 2);
	afficher_KO_OK(ft_stacklast(new)->next == NULL);
	t_stack *new4 = ft_stacknew(6);
	new3->next = new4;
	afficher_KO_OK(ft_stacklast(new)->nb_init == 6);
	afficher_KO_OK(ft_stacklast(new)->next == NULL);
	afficher_KO_OK(ft_stacklast(new2)->nb_init == 6);
	afficher_KO_OK(ft_stacklast(new2)->next == NULL);
	printf("\n");
}

void	main_stackadd_front()
{
	printf("stackadd_front: ");
	t_stack *new = ft_stacknew(1000);
	t_stack *new2 = ft_stacknew(1);
	t_stack *new3 = ft_stacknew(2);
	ft_stackadd_front(&new, new2);
	ft_stackadd_front(&new, new3);
	afficher_KO_OK(ft_stacksize(new) == 3);
	afficher_KO_OK(new->nb_init == 2);
	afficher_KO_OK(new->next->nb_init == 1);
	afficher_KO_OK(new->next->next->nb_init == 1000);
	printf("\n");
}

void	main_stack()
{
	main_stacknew();
	main_stacksize();
	main_stackadd_back();
	main_stacklast();
	main_stackadd_front();
}

void	main_verif_nb()
{
	printf("verif_nb: ");
	afficher_KO_OK(ft_verif_nb("0") == 1);
	afficher_KO_OK(ft_verif_nb("1000") == 1);
	afficher_KO_OK(ft_verif_nb("-1000") == 1);
	afficher_KO_OK(ft_verif_nb("2147483647") == 1);
	afficher_KO_OK(ft_verif_nb("2147483648") == 0);
	afficher_KO_OK(ft_verif_nb("-2147483648") == 1);
	afficher_KO_OK(ft_verif_nb("-2147483649") == 0);
	afficher_KO_OK(ft_verif_nb("1234567890123456") == 0);
	printf("\n");
}

void	main_fill_struct()
{
	int	ac = 4;
	char **av = (char *[]){"1  2 3", "4 5  6","7    8        9" "10"};
	t_stack *stack = fill_struct(ac, av);
	afficher_KO_OK(ft_stacksize(stack) == 10);
	afficher_KO_OK(stack->nb_init == 1 && 
		stack->next->nb_init == 2 && 
		stack->next->next->nb_init == 3 &&
		stack->next->next->next->nb_init == 4 && 
		stack->next->next->next->next->next->nb_init == 5 && 
		stack->next->next->next->next->next->next->nb_init == 6 &&
		ft_stacklast(stack)->nb_init == 10);

	ac = 1;
	av = (char *[]){"1 2 3 4 5 6 7 8 9 10"};
	stack = fill_struct(ac, av);
	afficher_KO_OK(ft_stacksize(stack) == 10);
	afficher_KO_OK(stack->nb_init == 1 && 
		stack->next->nb_init == 2 && 
		stack->next->next->nb_init == 3 &&
		stack->next->next->next->nb_init == 4 && 
		stack->next->next->next->next->next->nb_init == 5 && 
		stack->next->next->next->next->next->next->nb_init == 6 &&
		ft_stacklast(stack)->nb_init == 10);

	ac = 10;
	av = (char *[]){"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
	stack = fill_struct(ac, av);
	afficher_KO_OK(ft_stacksize(stack) == 10);
	afficher_KO_OK(stack->nb_init == 1 && 
		stack->next->nb_init == 2 && 
		stack->next->next->nb_init == 3 &&
		stack->next->next->next->nb_init == 4 && 
		stack->next->next->next->next->next->nb_init == 5 && 
		stack->next->next->next->next->next->next->nb_init == 6 &&
		ft_stacklast(stack)->nb_init == 10);

	ac = 10;
	av = (char *[]){"1", "2", "3", "4", "5", "6", "7", "8", "9", "2147483648"};
	stack = fill_struct(ac, av);
	afficher_KO_OK(stack == NULL);
}

void	main_verif_double()
{
	printf("verif_double: ");
	t_stack *new = ft_stacknew(0);
	t_stack *new2 = ft_stacknew(1);
	t_stack *new3 = ft_stacknew(3);
	new2->next = new3;
	new->next = new2;
	afficher_KO_OK(verif_double(new2) == 1);
	afficher_KO_OK(verif_double(new) == 1);
	t_stack *new4 = ft_stacknew(0);
	new3->next = new4;
	afficher_KO_OK(is_sorted(new) == 0);
	new->nb_init = -1;
	afficher_KO_OK(is_sorted(new) == 0);
	printf("\n");
}

void	main_replace_nb_init()
{
	printf("verif_double: ");
	t_stack *new = ft_stacknew(1000);
	t_stack *new2 = ft_stacknew(1);
	t_stack *new3 = ft_stacknew(20000);
	new2->next = new3;
	new->next = new2;
	replace_nb_init(new);
	afficher_KO_OK(new->nb == 1 && new->next->nb == 0 && new->next->next->nb == 2);
	t_stack *new4 = ft_stacknew(0);
	new3->next = new4;
	replace_nb_init(new);
	afficher_KO_OK(new->nb == 2 && new->next->nb == 1 && new->next->next->nb == 3 && new->next->next->next->nb == 0);
	printf("\n");
}

void	main_is_sorted()
{
	printf("stackis_sorted: ");
	t_stack *new = ft_stacknew(1000);
	new->nb = 1000;
	t_stack *new2 = ft_stacknew(1);
	new2->nb = 1;
	t_stack *new3 = ft_stacknew(3);
	new3->nb = 3;
	new2->next = new3;
	new->next = new2;
	afficher_KO_OK(is_sorted(new2) == 1);
	afficher_KO_OK(is_sorted(new) == 0);
	t_stack *new4 = ft_stacknew(2);
	new4->nb = 2;
	new3->next = new4;
	new->nb = 0;
	afficher_KO_OK(is_sorted(new) == 0);
	new4->nb = 6;
	afficher_KO_OK(is_sorted(new) == 1);
	printf("\n");
}

int	main()
{
	main_stack();
	main_verif_nb();
	main_fill_struct();
	main_is_sorted()
	main_verif_double()
	main_replace_nb_init()
}