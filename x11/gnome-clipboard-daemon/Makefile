# New ports collection makefile for:	gnome-clipboard-daemon
# Date created:				24 January 2004
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gnome-clipboard-daemon
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that keeps the content of your X clipboard in memory

PLIST_FILES=	bin/gnome-clipboard-daemon
USE_BZIP2=	yes
USE_GNOME=	gtk20

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
