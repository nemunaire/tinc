/*
    net.h -- header for net.c
    Copyright (C) 1998-2001 Ivo Timmermans <zarq@iname.com>
                  2000,2001 Guus Sliepen <guus@sliepen.warande.net>

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

    $Id: net.h,v 1.9.4.36 2001/10/27 13:13:35 guus Exp $
*/

#ifndef __TINC_NET_H__
#define __TINC_NET_H__

#include <sys/time.h>

#include "config.h"

#define MAXSIZE 1700	/* should be a bit more than the MTU for the tapdevice */
#define MTU 1600
#define SALTLEN	2	/* to spice things up for the NSA... */

#define MAC_ADDR_S "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_ADDR_V(x) ((unsigned char*)&(x))[0],((unsigned char*)&(x))[1], \
                      ((unsigned char*)&(x))[2],((unsigned char*)&(x))[3], \
                      ((unsigned char*)&(x))[4],((unsigned char*)&(x))[5]

#define IP_ADDR_S "%d.%d.%d.%d"

#ifdef WORDS_BIGENDIAN
# define IP_ADDR_V(x) ((unsigned char*)&(x))[0],((unsigned char*)&(x))[1], \
                      ((unsigned char*)&(x))[2],((unsigned char*)&(x))[3]
#else
# define IP_ADDR_V(x) ((unsigned char*)&(x))[3],((unsigned char*)&(x))[2], \
                      ((unsigned char*)&(x))[1],((unsigned char*)&(x))[0]
#endif

#define MAXBUFSIZE 4096 /* Probably way too much, but it must fit every possible request. */

/* tap types */
#define TAP_TYPE_ETHERTAP 0
#define TAP_TYPE_TUNTAP   1

typedef struct mac_t
{
  unsigned char x[6];
} mac_t;

typedef unsigned long ipv4_t;

typedef struct ip_mask_t {
  ipv4_t address;
  ipv4_t mask;
} ip_mask_t;

typedef struct ipv6_t
{
  unsigned short x[8];
} ipv6_t;

typedef unsigned short port_t;

typedef short length_t;

typedef struct vpn_packet_t {
  length_t len;			/* the actual number of bytes in the `data' field */
  unsigned char salt[SALTLEN];	/* two bytes of randomness */
  unsigned char data[MAXSIZE];
} vpn_packet_t;

typedef struct queue_element_t {
  void *packet;
  struct queue_element_t *prev;
  struct queue_element_t *next;
} queue_element_t;

typedef struct packet_queue_t {
  queue_element_t *head;
  queue_element_t *tail;
} packet_queue_t;

extern int maxtimeout;
extern int seconds_till_retry;

extern char *request_name[256];
extern char *status_text[10];

#include "connection.h"		/* Yes, very strange placement indeed, but otherwise the typedefs get all tangled up */

extern void send_packet(struct node_t *, vpn_packet_t *);
extern void receive_packet(struct node_t *, vpn_packet_t *);
extern void receive_tcppacket(struct connection_t *, char *, int);
extern void broadcast_packet(struct node_t *, vpn_packet_t *);
extern int setup_network_connections(void);
extern void close_network_connections(void);
extern void main_loop(void);
extern void terminate_connection(connection_t *, int);
extern void flush_queue(struct node_t *);
extern int read_rsa_public_key(struct connection_t *);
extern RETSIGTYPE try_outgoing_connections(int);

#endif /* __TINC_NET_H__ */
