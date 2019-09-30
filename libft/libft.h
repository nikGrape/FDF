/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:26:04 by vinograd          #+#    #+#             */
/*   Updated: 2019/09/27 15:09:00 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# define MAX(A, B) (A > B ? A : B)
# define MIN(A, B) (A > B ? B : A)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;

int				ft_atoi(const char *s);
long			ft_atoi_long(char *s);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int i);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isinteger(char *nbr);
int				ft_isprint(int c);
void			*ft_memccpy(void *restrict dst, const void *restrict src, \
		int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *restrict dst, void *restrict src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcat(char *restrict str1, const char *restrict str2);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(char *s);
size_t			ft_strlcat(char *restrict dst, const char \
		*restrict src, size_t dstsize);
size_t			ft_strlen(char const *s);
char			*ft_strncat(char *str1, const char *str2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strnstr(const char *haystack, const char \
		*needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystach, const char *needle);
int				ft_tolower(int c);
int				ft_toupper(int c);
/*
**	Second part
**	ft_putstr was chended
**		now it returns number of printed characters
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);
char			*ft_itoa(int nbr);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
int				ft_putstr(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
	**Bonus part
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** Extra functions
**		ft_strjoin_free:
**			index 1 - free first parametr
**			index 2 - free second parametr
**			index 3 - free both parametrs
**		ft_stradd - add a character(ch) to the end of the line(str)
*/
void			*ft_memdup(void const *src, size_t len);
int				ft_wdcounter(char const *str, char c);
int				ft_strindex(char *haystack, char *needle);
void			ft_swap(char *c1, char *c2);
void			ft_swapi(int *c1, int *c2);
char			*ft_ftoa(double nbr, unsigned int precision);
char			*ft_ftoa_long(long double nbr, unsigned int precision);
char			*ft_itoa_unsigned(size_t nbr);
char			*ft_itoa_long(long nbr);
char			*ft_itoa_base(unsigned int nbr, int base);
char			*ft_itoa_base_unsigned(size_t nbr, int base);
void			ft_strupper(char *str);
void			ft_strlower(char *str);
char			*ft_strjoin_free(char *s1, char *s2, int indx);
char			*ft_stradd(char *str, char ch);
/*
** Extra functions II
*/
int				get_next_line(const int fd, char **line);
int				ft_printf(const char *format, ...);
char			*ft_sprintf(const char *format, ...);
int				ft_arrayfree(char **arr);
int				ft_arraylen(char **arr);
/*
** Array int library
*/
int				*arr_new(char *arr);
int				arr_len(int *arr);
int				arr_get(int *arr, int index);
void			arr_set(int *arr, int index, int nbr);
void			arr_del(int *arr, int index, ...);
void			arr_print(int *arr);
void			arr_add(int **arr, int index, int nbr);
void			arr_cat(int **arr, char *addon);

#endif
