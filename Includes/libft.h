/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:23:38 by aouichou          #+#    #+#             */
/*   Updated: 2023/08/17 13:16:08 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_printf
{
	va_list			args;
	int				wdth;
	int				precision;
	int				zero;
	int				point;
	int				dash;
	int				rtrn;
	int				sign;
	int				percent;
	int				space;
	int				hash;
}					t_printf;

int			ft_atoi(const char *str);
long		ft_atoi_base(char *str, char *base);
void		ft_bzero(void *s, size_t n);

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(char c);

size_t		ft_strlen(const char *str);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memcpy(void *str1, const void *str2, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *nw);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *nw);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char		*ft_strnew(size_t size);
char		*ft_strtok(const char *s, int c);
char		*ft_strrtok(const char *s, int c);
char		**ft_str_split_white_spaces(char const *s);
char		*ft_strstr(const char *string, const char *to_find);
char		*ft_str_find_replace(char *str, char *str_find, char *str_replace);
int			ft_strchri(const char *s, int c);
int			ft_strchri_set(const char *s, char *set);
int			ft_countchar(char *s, char c);

int			ft_printf(const char *str, ...);
int			ft_printchar(char c);
int			ft_printstr(char *str);
void		ft_printnbr(long long n, t_printf **flgs);

int			is_specifier(char c);
void		flgs_init(t_printf *flgs);
int			left_padding(int n, int mod);
int			right_padding(int n);
int			number_p_len(unsigned long long nb, int base);
int			number_len(long long nb, int base);
char		*ft_itoa_base(unsigned long long value, char *base);
int			ft_print_arg(t_printf **flgs, char *str, int i);

void		ft_print_x(long long nb, t_printf **flgs, char c);
void		ft_print_p(void *ptr, t_printf **flgs);
void		ft_print_u(unsigned int nb, t_printf **flgs);
void		ft_print_d_i(long long nb, t_printf **flgs);
void		ft_print_s(char *str, t_printf **flgs);
void		ft_print_c(char c, t_printf **flgs);

char		*get_next_line(int fd);
char		*ft_substr_free(char *s, unsigned int start, size_t len, int mod);
char		*ft_strjoin_free(char *s1, char *s2, int mod);

int			ft_array_size(char **array);
char		**ft_array_dup(char **array);
char		**ft_array_expand(char **array, char *str);
void		ft_array_free(char ***array);
char		**ft_array_contract(char ***array, int z);
char		**ft_array_replace(char ***big, char **small, int n);
void		ft_array_print_fd(char **array, int mod, int fd);
char		**ft_array_sort(char **array);

char		*ft_strcpy_non_static(char *src, int i);

void		*ft_free(void ***ptr);
void		ft_clean_array(void **array, void (*del)(void *));
double		ft_atof(const char *str);
void		*ft_realloc(void *ptr, size_t ptr_size, size_t size);
int			ft_arradd_int(int **array, int n, size_t size);
char		*ft_strcpy_end(char *dest, char *src);
t_list		*ft_lstfind(t_list *lst, void *content);

#endif
