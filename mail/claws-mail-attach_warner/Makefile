# New ports collection makefile for:	claws-mail-attach_warner
# Date created:	2 March 2007
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	attach_warner
PORTVERSION=	0.2.24
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	attachwarner-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Not attached file warning plugin for claws-mail

LICENSE=	GPLv3

BUILD_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.1:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-iconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
