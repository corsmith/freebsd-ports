# New ports collection makefile for:	clusterssh
# Date created:				2005-08-15
# Whom:					David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	clusterssh
PORTVERSION=	3.28
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	SF/${PORTNAME}/1.%20ClusterSSH%20Series%203/${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Controls multiple hosts simultaneously via xterms and ssh

RUN_DEPENDS=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-X11-Protocol>=0:${PORTSDIR}/x11/p5-X11-Protocol

USE_PERL5=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cssh
MAN1=		cssh.1

.include <bsd.port.mk>
