/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:52:05 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/21 19:32:09 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	int				content;
	int				nb;
	struct s_stack	*next;
}					t_stack;

int			ft_abs(int nb);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_magic_free(char *str, ...);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_printf(const char *s, ...);
int			ft_printf_fd(int fd, const char *str, ...);
int			ft_putchar(int c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_puthexa(long long int n, char *base);
size_t		ft_putlchar(int c);
size_t		ft_putlchar_fd(int c, int fd);
size_t		ft_putlhexa_low(unsigned long int nb);
size_t		ft_putlhexa_low_fd(unsigned long int nb, int fd);
size_t		ft_putlhexa_up(unsigned long int nb);
size_t		ft_putlhexa_up_fd(unsigned long int nb, int fd);
size_t		ft_putlnbr(int n);
size_t		ft_putlnbr_fd(int n, int fd);
size_t		ft_putlpoint(void *p);
size_t		ft_putlpoint_fd(void *p, int fd);
size_t		ft_putlstr(char *s);
size_t		ft_putlstr_fd(char *s, int fd);
size_t		ft_putlunbr_fd(unsigned int n, int fd);
size_t		ft_putlunbr(unsigned int n);
size_t		ft_putmultstr(char **strs);
size_t		ft_putmultstr_fd(char **strs, int fd);
int			ft_putnbr(long long int n);
void		ft_putnbr_fd(int n, int fd);
int			ft_putptr(unsigned long long ptr, char *base);
int			ft_putstr(char *s);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(const char *s, char c);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack		*ft_stacklast(t_stack *stack);
t_stack		*ft_stackbeforelast(t_stack *stack);
t_stack		*ft_stacknew(int content);
int			ft_stacksize(t_stack *stack);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, int start, int len);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_vjoin(size_t nb_str, char *sep, ...);

#endif
