# New ports collection makefile for:    fep
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	fep
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/fep/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose front end for command line editing

MAN1=		fep.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/fep

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800039
BROKEN=		Does not compile without sgtty
.endif

.include <bsd.port.post.mk>
