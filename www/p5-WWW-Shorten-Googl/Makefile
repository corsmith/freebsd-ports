# New ports collection makefile for:	p5-WWW-Shorten-Googl
# Date created:				September 9 2011
# Whom:					Jonathan Pater <cowboyneal@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten-Googl
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cowboyneal@gmail.com
COMMENT=	Perl interface to goo.gl

BUILD_DEPENDS=	p5-WWW-Shorten>=1.98:${PORTSDIR}/www/p5-WWW-Shorten \
		p5-libwww>=5.75:${PORTSDIR}/www/p5-libwww \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Shorten::Googl.3

.include <bsd.port.mk>
