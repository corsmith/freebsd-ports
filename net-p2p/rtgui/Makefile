# $FreeBSD$

PORTNAME=	rtgui
PORTVERSION=	0.2.7
PORTREVISION=	3
CATEGORIES=	net-p2p www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A web based front end for rTorrent

OPTIONS=	APACHE "Use Apache for web interface" On \
		LIGHTTPD "Use LightHTTPD for web interface" Off

BUILD_DEPENDS+=	xmlrpc-c-config:${PORTSDIR}/net/xmlrpc-c

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APACHE)
USE_APACHE_RUN=	22+
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_scgi.so:${PORTSDIR}/www/mod_scgi
.elif defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

USE_PHP=	xmlrpc session mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR=${WWWDIR} \
		PORTNAME=${PORTNAME}

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -r ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
