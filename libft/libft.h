/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ieschall <ieschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:48:09 by ieschall          #+#    #+#             */
/*   Updated: 2021/08/08 15:08:12 by ieschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>

# define EOL ('\n')
# define EOS ('\0')

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
** LIBS FUNCTIONS **************************************************************
*/

char				*ft_strnstr(const char *s, const char *find, size_t slen);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *dst, int c, size_t len);
char				*ft_strrchr(const char *s, int c);
void				*ft_calloc(size_t n, size_t size);
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *s, size_t len);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** ADDITIONAL FUNCTIONS ********************************************************
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strtrim(char const *s, char const *set);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);

#endif
