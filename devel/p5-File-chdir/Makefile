# New ports collection makefile for:	File-chdir
# Date created:	   10 December 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	File-chdir
PORTVERSION=	0.1006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A more sensible way to change directories

BUILD_DEPENDS=	p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=		File::chdir.3

.include <bsd.port.mk>
