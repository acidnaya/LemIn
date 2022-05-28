/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:15:49 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/27 15:48:23 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

int					ft_isalnum(int i);

int					ft_isalpha(int i);

int					ft_isascii(int c);

int					ft_isdigit(int i);

int					ft_isprint(int i);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *mem, int val, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t num);

void				*ft_memmove(void *dst, const void *src, size_t n);

void				*ft_memset(void *memptr, int val, size_t num);

char				*ft_strcat(char *dst, const char *src);

char				*ft_strchr(const char *str, int symbol);

int					ft_strcmp(const char *s1, const char *s2);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strdup(const char *src);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

size_t				ft_strlen(const char *str);

char				*ft_strncat(char *dst, const char *src, size_t num);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strncpy(char *dst, const char *src, size_t n);

char				*ft_strnstr(const char *str, const char *to_find,
					size_t len);

char				*ft_strrchr(const char *str, int symbol);

char				*ft_strstr(const char *str, const char *to_find);

int					ft_tolower(int i);

int					ft_toupper(int i);

char				*ft_itoa(int n);

void				ft_memdel(void **ap);

void				*ft_memalloc(size_t size);

void				ft_putchar_fd(char c, int fd);

void				ft_putchar(char c);

void				ft_putendl_fd(const char *str, int fd);

void				ft_putendl(char const *str);

void				ft_putnbr_fd(int nb, int fd);

void				ft_putnbr(int nb);

void				ft_putstr_fd(char const *str, int fd);

void				ft_putstr(char const *str);

void				ft_strclr(char *s);

void				ft_strdel(char **as);

int					ft_strequ(char const *s1, char const *s2);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strnew(size_t size);

char				**ft_strsplit(char const *s, char c);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strtrim(char const *s);

t_list				*ft_lstnew(void const *content, size_t content_size);

t_list				*ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					get_next_line(const int fd, char **line);

int					ft_strchr_index(char *s, char c);

char				**ft_strsplit_symbols(char *str, char *c);

#endif
