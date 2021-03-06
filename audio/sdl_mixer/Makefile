# New ports collection makefile for:	sdl_mixer
# Date created:				24 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.12
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library

USE_AUTOTOOLS=	libtool
USE_SDL=	sdl
USE_GNOME=	pkgconfig gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-DCONFIG_FILE_ETC_TIMIDITY=\"${LOCALBASE}/etc/timidity.cfg\"
USE_LDCONFIG=	yes

OPTIONS=	MIKMOD		"Enable MOD music via libMikMod"	On \
		SMPEG		"Enable MP3 music via SMPEG"		On \
		FLAC		"Enable FLAC encoding support via flac"	On \
		VORBIS		"Enable Ogg Vorbis music"		On \
		TIMIDITYPLUS	"Use Timidity++ instead of Timidity"	Off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MIKMOD)
CONFIGURE_ARGS+=--disable-music-mod
.else
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--enable-music-mod
.endif

.if defined(WITHOUT_FLAC)
CONFIGURE_ARGS+=--disable-music-flac
.else
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-music-flac
.endif

.if defined(WITHOUT_SMPEG)
CONFIGURE_ARGS+=--disable-music-mp3
.else
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--enable-music-mp3
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-music-ogg
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-music-ogg
.endif

post-patch:
.if defined(WITH_TIMIDITYPLUS)
	@${REINPLACE_CMD} -e 's|"${LOCALBASE}/lib/timidity"|"${LOCALBASE}/share/timidity"|g' \
		${WRKSRC}/timidity/config.h
.endif

.include <bsd.port.post.mk>
