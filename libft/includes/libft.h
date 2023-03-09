/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:24:27 by jehubert          #+#    #+#             */
/*   Updated: 2023/03/09 17:03:30 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 400

# endif

# ifdef __APPLE__

#  define NPTR "0x0"

# else

#  define NPTR "(nil)"

# endif

typedef struct s_list	t_list;

struct s_list
{
	int				x;
	struct s_list	*n;
	struct s_list	*p;
} ;

void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
size_t		ft_strlcat(char *dest, char *src, size_t size);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(int x);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
size_t		gnl_strlen(const char *s);
size_t		gnl_strlcat(char *dest, char *src, size_t size);
int			gnl_strchr(char *s, int c);
char		*gnl_strjoin(char *s1, char *s2);
size_t		gnl_strlcpy(char *dest, char *src, size_t size);
char		*gnl_substr(char const *s, unsigned int start, size_t len);
char		*buf(int fd);
char		*cleanline(char *line);
char		*get_next_line(int fd, char *lim);
int			linelen(char *str);
int			ft_printf(const char *av, ...);
int			checkflag(char flag, va_list *args);
int			hexmaster(unsigned long long nb, int size, int isptr);
void		putnbrhex(unsigned long long nb, int *i, int size);
int			ftputnbr(int nb);
int			ftputstr(char *str);
int			ftputchar(char c);
int			uintmaster(unsigned int nb);
void		put_uint(unsigned int nb, int *i);
void		*ft_realloc(void *ptr, size_t size);
void		ft_join(char *s1, char s2);

#endif
