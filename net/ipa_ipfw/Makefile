# New ports collection makefile for:	ipa_ipfw
# Date created:				27 December 2005
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa_ipfw
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	SF/ipa-system/modules/ipa_ipfw

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA accounting module for FreeBSD IP Firewall

LICENSE=	BSD

NO_PACKAGE=	Needs to be built uniquely for each host

USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

LOCALINCLUDE?=	${LOCALBASE}/include
MAKE_ENV+=	DEBUG_FLAGS="" PREFIX=${PREFIX} LOCALINCLUDE=${LOCALINCLUDE}

BUILD_DEPENDS+=	${LOCALBASE}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

PLIST_FILES=	lib/ipa_ipfw.so

MANCOMPRESSED=	yes
MAN8=		ipa_ipfw.8
MANLANG=	"" ru.KOI8-R

do-install:
	cd ${WRKSRC} && ${MAKE} install
	cd ${WRKSRC}/man && ${MAKE} LANG_DIR_SRC=ru.KOI8-R clean all install

.include <bsd.port.post.mk>
