# New ports collection makefile for:	www/p5-Catalyst-Controller-RequestToken
# Date created:				24 July 2009
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Controller-RequestToken
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Generate and validate unique tokens across HTTP requests (anti-CSRF)

BUILD_DEPENDS=	p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Controller::RequestToken.3 \
	Catalyst::Controller::RequestToken::Action::CreateToken.3 \
	Catalyst::Controller::RequestToken::Action::RemoveToken.3 \
	Catalyst::Controller::RequestToken::Action::ValidateToken.3

.include <bsd.port.mk>
