# New ports collection makefile for:	ffmpegthumbnailer
# Date created:		Mo 18 Feb 2008 06:11:13 CET
# Whom:			Dierk Sacher <dierk@blaxxtarz.de>
#
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.0.7
PORTREVISION=	2
CATEGORIES=	multimedia graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	dierk@blaxxtarz.de
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		swscale:${PORTSDIR}/multimedia/ffmpeg \
		jpeg.11:${PORTSDIR}/graphics/jpeg

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-gio

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig _glib20
USE_LDCONFIG=	yes

MAN1=		ffmpegthumbnailer.1

SUB_FILES=	pkg-message

post-install:
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} install-pkgconfigDATA
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/bind-nautilus.sh ${DATADIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
