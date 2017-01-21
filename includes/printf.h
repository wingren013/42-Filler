/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:39:56 by smifsud           #+#    #+#             */
/*   Updated: 2016/12/05 19:08:47 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <wchar.h>
# include <stdarg.h>

typedef size_t			(*t_strfunc)();
typedef struct			s_holder
{
	size_t				width;
	size_t				prec;
	char				pound_flag;
	char				zero_flag;
	char				minus_flag;
	char				space_flag;
	char				plus_flag;
	int					error;
	size_t				ip;
	size_t				ret;
	wchar_t				*wstr;
	size_t				size;
	int					null;
}						t_holder;

size_t					s_flag(const char *str, char **ret);
size_t					ls_flag(const wchar_t *str, char **ret);
size_t					p_flag(void *ptr, char **ret);
size_t					d_flag(int num, char **ret);
size_t					ld_flag(long num, char **ret);
size_t					o_flag(unsigned int num, char **ret);
size_t					lo_flag(unsigned long num, char **ret);
size_t					x_flag(unsigned int num, char **ret);
size_t					lx_flag(unsigned long num, char **ret);
size_t					upperhex_flag(unsigned int num, char **ret);
size_t					lupperhex_flag(unsigned long num, char **ret);
size_t					u_flag(unsigned int num, char **ret);
size_t					lu_flag(unsigned long num, char **ret);
size_t					c_flag(unsigned int c, char **ret, t_holder *holder);
size_t					lc_flag(wint_t c, char **ret, t_holder *holder);
size_t					hd_flag(unsigned int nb, char **ret);
size_t					hu_flag(unsigned int nb, char **ret);
size_t					ho_flag(unsigned int nb, char **ret);
size_t					hx_flag(unsigned int nb, char **ret);
size_t					hupperhex_flag(unsigned int nb, char **ret);
size_t					hhd_flag(unsigned int nb, char **ret);
size_t					hhu_flag(unsigned int nb, char **ret);
size_t					hho_flag(unsigned int nb, char **ret);
size_t					hhx_flag(unsigned int nb, char **ret);
size_t					hhupperhex_flag(unsigned int nb, char **ret);
size_t					zd_flag(ssize_t n, char **ret);
size_t					zu_flag(size_t n, char **ret);
size_t					zx_flag(size_t n, char **ret);
size_t					zo_flag(size_t n, char **ret);
size_t					zupperhex_flag(size_t n, char **ret);
size_t					jd_flag(intmax_t n, char **ret);
size_t					ju_flag(uintmax_t n, char **ret);
size_t					jx_flag(uintmax_t n, char **ret);
size_t					jo_flag(uintmax_t n, char **ret);
size_t					jupperhex_flag(uintmax_t n, char **ret);
void					setup_funcs(void);
size_t					func_switch(va_list argp, unsigned const char *fmt,
		t_holder *h, char **ret);
void					clearholder(t_holder *holder);
char					*flags_modstr(char *str, t_holder *holder,
		unsigned char conver);
char					*poundmod(char *str, unsigned char conver,
		t_holder *holder);
char					*spacemod(char *str, unsigned char conver,
		t_holder *holder);
char					*plusmod(char *str, unsigned char conver,
		t_holder *holder);
size_t					percentpercent(char **ret);
size_t					p_ls(wchar_t *wstr, size_t prec, char **ret);
char					*negative_handle_printf(char *str, int y,
		t_holder *holder);
void					length_modifiers(unsigned char **fmt);
char					*widthmod(char *str, t_holder *holder,
		unsigned char conver, size_t *textlen);

extern t_strfunc		g_strfuncs[];
extern unsigned char	g_types[];

# define STOP(x) (x=='%')
# define FLAG(x) (x=='#'||x=='0'||x=='-'||x==' '||x=='+')
# define HEXCONVERP2(x) (x=='{'||x=='}'||x=='{'+32||x=='}'+32)
# define HEXCONVERP(x) (x=='x'||x=='y'||x=='X'||x=='Y'||HEXCONVERP2(x))
# define SINGEDC(x) (x=='i'+32||x=='i'+64||x=='I')
# define CONVERP3(x) (x=='d'||x=='i'||x=='D'||x=='d'+32||x=='d'+64)
# define SIGNEDCONVERP(x) (CONVERP3(x)||SINGEDC(x))
# define OCTFLAG(x) (x=='o'||x=='O'||x=='o'+32||x=='o'+64)
# define DFLAG(x) (x=='d'||x=='i'||x=='u'||x=='D'||x=='d'+32||x=='d'+64)
# define INTFLAG(x) (x=='I'||x=='i'+32||x=='i'+64||DFLAG(x))
# define NUMERCON(x) (HEXCONVERP(x)||OCTFLAG(x)||INTFLAG(x))
# define CAP(x) (x=='I'||x=='D'||x=='O'||x=='C'||x=='c')
# define CAPFORM(x) (CAP(x)||x=='S'||x=='s'||x=='z'||x=='Z')
# define FUNCS g_strfuncs

# define PRINTF_FUNC1 int __attribute__((format (printf, 1, 2)))
# define PRINTF_FUNC2 int __attribute__((format (printf, 2, 3)))
# define PRINTF_FUNC3 int __attribute__((format (printf, 3, 4)))

PRINTF_FUNC2			ft_asprintf(char **strp, const char *fmtstr, ...);
PRINTF_FUNC1			ft_printf(const char *fmtstr, ...);
int						ft_vasprintf(char **strp,
		const char *fmtstr, va_list argp);
int						ft_dprintf(int fd, const char *fmtstr, ...);
int						ft_sprintf(char *str, const char *fmtstr, ...);
int						ft_snprintf(char *str, size_t size,
		const char *fmtstr, ...);

#endif
