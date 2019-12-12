#ifndef BIGINT_H

# define BIGINT_H

void    add_bigints(bigint *result, bigint *to_add);
void    create_unit(bigint *tab, unsigned int size, int expo);
void	divide_bigint_by_2(bigint *tab);
unsigned int divide_by_10(unsigned int nb, int power);
void	filling_zeros(unsigned int nb);
void	get_bigint_info(bigint *result, int16_t expo, int prec, t_bigint_info *info);
int		get_first_int_case(int16_t expo, t_bigint_info *info, bigint *result);
int		get_last_dec_case(int16_t expo, int prec, t_bigint_info info);
int		get_last_digit_rank(int16_t expo, int prec, t_bigint_info info);
int		get_next_figure(bigint *result, t_bigint_info
	 info);
void	cut_result(bigint *result, t_bigint_info
	 info);
void	get_prec_to_add(bigint *to_add, int index);
void    init_bigint(bigint *tab);
int		manage_dbl(t_dbl *dbl, int prec, int *to_print, char *buffer);
int		manage_ldbl(t_ldbl *ldbl, int prec, int *to_print, char *buffer);
void    multiply_bigint_by_2(bigint *tab);
int		only_nine(unsigned int nb);
int		print_big_dbl(int16_t expo, bigint *result, int prec, t_bigint_info
	 *info, char *buffer);
int		print_big_ldbl(int16_t expo, bigint *result, int prec, t_bigint_info
	 *info, char *buffer);
int		print_dbl(int16_t expo, bigint *result, int prec, t_bigint_info
	 *info, char *buffer);
void	print_dec_part(bigint *result, t_bigint_info info, int prec, int16_t expo, char *buffer);
void	print_first_dec(unsigned int nb, int *prec, int *i, char *buffer);
int		print_int_part(bigint *result, int16_t expo, int prec, t_bigint_info info, char *buffer);
int		print_ldbl(int16_t expo, bigint *result, int prec, t_bigint_info *info, char *buffer);
int		print_small_dbl(int16_t expo, bigint *result, int prec, t_bigint_info *info, char *buffer);
void	store_big_dbl(t_dbl dbl, bigint *result);
void	store_big_ldbl(t_ldbl ldbl, bigint *result);
void	store_small_dbl(t_dbl dbl, bigint *result);
void	store_small_ldbl(t_ldbl ldbl, bigint *result);
int		main_ld(long double f, t_conv conv, char *buffer);
int		main_d(double f, t_conv conv, char *buffer);

#endif
