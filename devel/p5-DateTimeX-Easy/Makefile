# New ports collection makefile for:	devel/p5-DateTimeX-Easy
# Date created:				23 Jun 2009
# Whom:					Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	DateTimeX-Easy
PORTVERSION=	0.089
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Parse a date/time string using the best method available

RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-DateParse>=0:${PORTSDIR}/devel/p5-DateTime-Format-DateParse \
		p5-DateTime-Format-Flexible>=0:${PORTSDIR}/devel/p5-DateTime-Format-Flexible \
		p5-DateTime-Format-ICal>=0:${PORTSDIR}/devel/p5-DateTime-Format-ICal \
		p5-DateTime-Format-Natural>=0:${PORTSDIR}/devel/p5-DateTime-Format-Natural \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

PERL_CONFIGURE=	yes

MAN3=	DateTimeX::Easy.3 \
	DateTimeX::Easy::DateParse.3

.include <bsd.port.mk>
