# New ports collection makefile for:	tiff2png
# Date created:				Tue 04 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	tiff2png
PORTVERSION=	0.91
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/png-mng/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts TIFF images to PNG format

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	tiff2png

PORTDOCS=	README
PLIST_FILES=	bin/tiff2png

CFLAGS+=	-DINVERT_MINISWHITE -DFAXPECT -DDEFAULT_DESTDIR_IS_CURDIR \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpng -lz -ltiff -ljpeg -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tiff2png ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
