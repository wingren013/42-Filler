/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 18:20:51 by smifsud           #+#    #+#             */
/*   Updated: 2016/12/05 19:04:42 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** flags are grouped into sections of 8
** (with 8 uppercase versions for a total of 16)
** with corresponding h and hh flags at +32 and +64 respectively
**
** placing
** non alphabetical flags  and x and X are handled specially
**
** y and Y are reserved as lx and lX
** { is reserved as hx and + 32 hhx
** } is reserved as hX and + 32 hhX
** 187 and beyond are for extra modifier
**
** flag modifiers
** (#, 0, +, -, ' ' are handled by modifying the output string in the parser)
**
** non printables should be used for special case flags
*/

void	setup_hh(void)
{
	g_types['d' + 64] = 0x24;
	FUNCS['d' + 64] = &hhd_flag;
	g_types['i' + 64] = 0x24;
	FUNCS['i' + 64] = &hhd_flag;
	g_types['o' + 64] = 0x26;
	FUNCS['o' + 64] = &hho_flag;
	g_types['u' + 64] = 0x28;
	FUNCS['u' + 64] = &hhu_flag;
	g_types['{' + 32] = 0x2A;
	FUNCS['{' + 32] = &hhx_flag;
	g_types['}' + 32] = 0x2C;
	FUNCS['}' + 32] = &hhupperhex_flag;
	FUNCS['d' + 96] = &zd_flag;
	FUNCS['i' + 96] = &zd_flag;
	FUNCS['o' + 96] = &zo_flag;
	FUNCS['~'] = &zo_flag;
	FUNCS['u' + 96] = &zu_flag;
	FUNCS['{' + 64] = &zx_flag;
	FUNCS['}' + 64] = &zupperhex_flag;
	FUNCS['d' + 128] = &jd_flag;
	g_types['d' + 128] = 0x40;
	FUNCS['u' + 128] = &ju_flag;
	FUNCS['o' + 128] = &jo_flag;
	FUNCS['}' + 128] = &jupperhex_flag;
}

void	setup_h(void)
{
	g_types['d' + 32] = 0x14;
	FUNCS['d' + 32] = &hd_flag;
	g_types['i' + 32] = 0x14;
	FUNCS['i' + 32] = &hd_flag;
	g_types['o' + 32] = 0x16;
	FUNCS['o' + 32] = &ho_flag;
	g_types['u' + 32] = 0x18;
	FUNCS['u' + 32] = &hu_flag;
	g_types['{'] = 0x1A;
	FUNCS['{'] = &hx_flag;
	g_types['}'] = 0x1C;
	FUNCS['}'] = &hupperhex_flag;
	g_types['d' + 96] = 0x30;
	g_types['i' + 96] = 0x30;
	g_types['o' + 96] = 0x31;
	g_types['~'] = 0x31;
	g_types['u' + 96] = 0x32;
	g_types['{' + 64] = 0x33;
	g_types['}' + 64] = 0x34;
	FUNCS['{' + 128] = &jx_flag;
	setup_hh();
}

void	setup_types(void)
{
	g_types['s'] = 0x1;
	g_types['S'] = 0x2;
	g_types['p'] = 0x3;
	g_types['d'] = 0x4;
	g_types['D'] = 0x5;
	g_types[3] = 0x5;
	g_types['i'] = 0x4;
	g_types['I'] = 0x5;
	g_types['o'] = 0x6;
	g_types['O'] = 0x7;
	g_types['O' - 32] = 0x7;
	g_types['u'] = 0x8;
	g_types['U'] = 0x9;
	g_types[2] = 0x9;
	g_types['x'] = 0xA;
	g_types['y'] = 0xB;
	g_types['X'] = 0xC;
	g_types['Y'] = 0xD;
	g_types['c'] = 0xE;
	g_types['C'] = 0xF;
	g_types['%'] = 0x10;
	setup_h();
}

void	setup_funcs(void)
{
	FUNCS['s'] = &s_flag;
	FUNCS['S'] = &ls_flag;
	FUNCS['p'] = &p_flag;
	FUNCS['d'] = &d_flag;
	FUNCS['D'] = &ld_flag;
	FUNCS[3] = &ld_flag;
	FUNCS['i'] = &d_flag;
	FUNCS['I'] = &ld_flag;
	FUNCS['o'] = &o_flag;
	FUNCS['O'] = &lo_flag;
	FUNCS['O' - 32] = &lo_flag;
	FUNCS['u'] = &u_flag;
	FUNCS['U'] = &lu_flag;
	FUNCS[2] = &lu_flag;
	FUNCS['x'] = &x_flag;
	FUNCS['y'] = &lx_flag;
	FUNCS['X'] = &upperhex_flag;
	FUNCS['Y'] = &lupperhex_flag;
	FUNCS['c'] = &c_flag;
	FUNCS['C'] = &lc_flag;
	FUNCS['%'] = &percentpercent;
	setup_types();
}
