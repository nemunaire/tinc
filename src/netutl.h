/*
    netutl.h -- header file for netutl.c
    Copyright (C) 1998-2002 Ivo Timmermans <zarq@iname.com>
                  2000-2002 Guus Sliepen <guus@sliepen.warande.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    $Id: netutl.h,v 1.2.4.9 2002/02/11 10:16:18 guus Exp $
*/

#ifndef __TINC_NETUTL_H__
#define __TINC_NETUTL_H__

#include "net.h"

extern char *hostlookup(unsigned long);
extern ipv4_t str2address(char*);
extern char *address2str(ipv4_t);

#endif /* __TINC_NETUTL_H__ */