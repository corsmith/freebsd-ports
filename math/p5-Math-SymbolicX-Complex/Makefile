# New ports collection makefile for:	Math-SymbolicX-Complex
# Date created:				15 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-SymbolicX-Complex
PORTVERSION=	1.00
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complex number support for the Math::Symbolic parser

BUILD_DEPENDS=	p5-Math-Symbolic>=0:${PORTSDIR}/math/p5-Math-Symbolic \
		p5-Math-SymbolicX-ParserExtensionFactory>=0:${PORTSDIR}/math/p5-Math-SymbolicX-ParserExtensionFactory
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Math::SymbolicX::Complex.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
