# New ports collection makefile for:	xkbset
# Date created:		12 May 2001
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=	xkbset
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.math.missouri.edu/~stephen/software/xkbset/

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Manage various XKB features of X Window

MAN1=		xkbset.1
USE_XORG=	x11
USE_PERL5_BUILD=	yes

MAKE_ARGS=	X11BASE="${LOCALBASE}" X11PREFIX="${PREFIX}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

OPTIONS=	GUI "Install Tk GUI" off

.include <bsd.port.pre.mk>

.if defined(WITH_GUI)
RUN_DEPENDS+=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk
PLIST_SUB=	GUI=""
MAKE_ARGS+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
.else
PLIST_SUB=	GUI="@comment "
MAKE_ARGS+=	INSTALL_SCRIPT=:
.endif

post-build:
	@${REINPLACE_CMD} "s%#!/usr/bin/perl%#!${PERL}%" ${WRKSRC}/xkbset-gui

.include <bsd.port.post.mk>
