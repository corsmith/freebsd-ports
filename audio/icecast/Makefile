# New ports collection makefile for: icecast
# Date created:         28 Jan 1999
# Whom:                 Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

PORTNAME=	icecast
PORTVERSION=	1.3.12
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/icecast/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A streaming mp3 audio server

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libwrap
SUB_FILES=	pkg-message

pre-patch:
	@${REINPLACE_CMD} -e 's|<history.h>|<readline/history.h>|' \
		-e 's|<readline.h>|<readline/readline.h>|' \
		${WRKSRC}/src/admin.c
	@${REINPLACE_CMD} -e 's|#undef HAVE_HISTORY_H|#undef HAVE_READLINE_HISTORY_H|g' \
		${WRKSRC}/config.h.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/icecast ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/etc/icecast/conf
	${MKDIR} ${PREFIX}/etc/icecast/templates
.for CONF in groups.aut.dist icecast.conf.dist mounts.aut.dist users.aut.dist
	${INSTALL_DATA} ${WRKSRC}/conf/${CONF} ${PREFIX}/etc/icecast/conf
.endfor
.for TEMPL in 306.html 400.html 403.html 404.html 504.html bodytag.html info.html \
	      list_directory.html mountlist.html statistics.html admin_describe.html \
	      admin.html alias_add.html manual.html alias_del.html header.html \
	      footer.html admin_change.html
	${INSTALL_DATA} ${WRKSRC}/templates/${TEMPL} ${PREFIX}/etc/icecast/templates
.endfor
	${MKDIR} ${PREFIX}/share/doc/icecast/
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${PREFIX}/share/doc/icecast/
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'

.include <bsd.port.mk>
