# New ports collection makefile for:    husky-smapi
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	smapi
PORTVERSION=	2.2.4
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/2.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	MSGAPI for Husky Fidosoft Project

CONFLICTS=	husky-smapi-devel-[0-9]*

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
