# New ports collection makefile for:	ocaml-classes
# Date created:			Ven 16 ao� 2002 02:05:08 CEST
# Whom:				Micha�l Gr�newald
#
# $FreeBSD$
#

PORTNAME=	classes
PORTVERSION=	3.05
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/\
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/olabl/\
		ftp://ftp.inria.fr/lang/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ocaml Object interface for ocaml's standard library modules

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS:=	${BUILD_DEPENDS}

post-extract:
	@${CP} ${FILESDIR}/META ${WRKSRC}

.include <bsd.port.mk>
