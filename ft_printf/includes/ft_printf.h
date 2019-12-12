#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define ABS(x) (x > 0 ? x : -x)
# define S_INT_PREFIX ((nb < 0 || c.sign > 0 || c.space > 0) ? 1 : 0)
# define OCT_PREFIX (c.type == 'o' && prefix_len > 0 ? 1 : 0)
# define HEX_PREFIX ((c.hashtag == '#' || c.type == 'p') && nb > 0 ? 2 : 0)
# define SIZE_HH 1
# define SIZE_H 2
# define SIZE_L 3
# define SIZE_LL 4
# define SIZE_J 5
# define SIZE_Z 6
# define BUFF_SIZE 1024
# define BIGINT_SIZE 1000
# define CELL_LIMIT 999999999
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>
# include "../libft/libft.h"
# include "struct.h"
# include "bigint.h"

int 			compute_size(char **str, int count);
void 			convert_snumber(long long *nb, int size);
void 			convert_unumber(unsigned long long *nb, int size, t_conv c);
void			empty_buffer(char *buffer);
int				fill_buffer(char *buffer, char *str, int len);
char 			*ft_ftoa(double f, int precision);
int 			ft_printf(char *str, ...);
int 			get_conv_info(char **str, va_list arg_ptr, t_conv *c, char *buffer);
void 			get_decimal_part(double f, char *str, int precision);
void			get_flags(t_conv *c, char **str);
void 			get_int_part(int i, char *str, int index);
void 			get_prec(char **str, t_conv *c, va_list arg_ptr);
void 			get_size(char **str, t_conv *c);
int 			get_type(char **str, char *buffer, t_conv *c, va_list arg_ptr);
int 			get_uint_len(unsigned long long nb);
int				get_uprefix_len(unsigned long long nb, t_conv c);
void 			get_width(char **str, t_conv *c, va_list arg_ptr);
void 			init_conv(t_conv *c);
int 			int_part_len(int i);
int 			is_flag(char c);
int				is_not_number(double f);
int 			is_size(char c);
int 			is_type(char c);
int 			print_char(char l, t_conv c, char *buffer);
int 			print_float(long double f, t_conv c, char *buffer);
int				print_not_number(int code, char *buffer);
int 			print_ptr(unsigned long long nb, t_conv c, char *buffer);
int 			print_snumber(long long nb, t_conv c, char *buffer);
int 			print_string(char *str, t_conv c, char *buffer);
int 			print_unumber(unsigned long long nb, t_conv c, char *buffer);
int				put_spaces(int nb, char *buffer);
int				put_zeros(int nb, char *buffer);
char 			*unb_to_str(unsigned long long nb, t_conv c);
int				write_sprefix(long long nb, t_conv c, char *buffer);
int				write_uprefix(unsigned long long nb, t_conv c, char *buffer);
int				print_long_double(long double f, t_conv c, char *buffer);
int				print_double(double f, t_conv c, char *buffer);

#endif
