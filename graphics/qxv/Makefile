# New ports collection makefile for:	qxv
# Date created:		28 August 2012
# Whom:			cy
#
# $FreeBSD$
#

PORTNAME=	qxv
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://labs.freehackers.org/attachments/download/422/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A QT4 program that displays images of various formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		glib-2.0.0:${PORTSDIR}/devel/glib20 \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		iconv.3:${PORTSDIR}/converters/iconv \
		icui18n.48:${PORTSDIR}/devel/icu \
		intl.9:${PORTSDIR}/devel/gettext \
		pcre.1:${PORTSDIR}/devel/pcre \
		pthread-stubs.0:${PORTSDIR}/devel/libpthread-stubs \
		expat.6:${PORTSDIR}/textproc/expat2 \
		xcb.2:${PORTSDIR}/x11/xcb

USE_BZIP2=	yes
USE_XORG=	sm xrender xext x11 xau xdmcp ice
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
MAKE_JOBS_UNSAFE=	yes
HAS_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${QMAKE} PREFIX=${PREFIX} ${PORTNAME}.pro

do-install:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${INSTALL_PROGRAM} ${PORTNAME} ${LOCALBASE}/bin/

.include <bsd.port.mk>
