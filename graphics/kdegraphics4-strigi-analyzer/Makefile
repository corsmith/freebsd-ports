# New ports collection makefile for:	kdegraphics-strigi-analyzer
# Date created:				5 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics-strigi-analyzer
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi analyzers for various graphics file formats

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 strigi
KDE4_BUILDENV=	yes
USE_QT4=	corelib qmake_build moc_build uic_build rcc_build
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
