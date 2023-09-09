/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:32:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 14:38:05 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// convert.c
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

// ft_printf.c
int		ft_putu(unsigned long n, char c, int b);
int		ft_printf(const char *str, ...);

// ft_split.c
char	*ft_strndup(const char *s, int len);
char	**ft_split(char const *s, char c);

// get_next_line.c
int		ft_strlen_nl(char *str, int detect_nl);
char	*ft_strjoin_gnl(char *dest, char *src);
char	*get_next_line(int fd);

// isX.c
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);

// mem.c
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

// misc.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		isin(const char *buffer, char c);

// put_fd.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);

// put.c
int		ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char *str);
int		ft_putnbr(int n);

// str.c
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

// strfunc.c
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//strrare.c
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ft_list.c
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	delone(t_list **ptr);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	lstclear(t_list **lst);

// list_actions.c
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif