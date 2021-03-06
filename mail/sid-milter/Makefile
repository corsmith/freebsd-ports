# New ports collection makefile for:	sid-milter
# Date created:				18. Dec 2004
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sid-milter
PORTVERSION=	1.0.0
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/SenderID%20Milter/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An sid and spf milter for Sendmail

RESTRICTED=	may incorporate intellectual property, possible patent issues

WCONF=		${WRKSRC}/devtools/Site
MAN8=		sid-filter.8
DOCSFILES=	FEATURES INSTALL KNOWNBUGS LICENSE README README-SenderID \
		RELEASE_NOTES rfc4406.txt rfc4407.txt rfc4408.txt
INSTALL_WRKSRC=	${WRKSRC}/sid-filter
PLIST_FILES=	libexec/sid-filter
PORTDOCS=	${DOCSFILES}

.if !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

SITE+=		${FILESDIR}/site.config.m4
.if defined(WITH_SIDMILTER_AR)
MAN3=		ar.3
PLIST_FILES+=	include/libar.h lib/libar.a
.endif
USE_RC_SUBR=	milter-sid

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e "s|\`-O'|\`${CFLAGS}'|g" \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${SITE} > ${WCONF}/site.config.m4
.if defined(WITH_NH_MFROM)
	${ECHO_CMD} \
		'APPENDDEF(`confENVDEF'\'', `-D_FFR_NH_MFROM'\'')' \
		>> ${WCONF}/site.config.m4
.endif

post-install:
.for i in ${MAN8}
	@${RM} -f ${MANPREFIX}/man/cat8/${i} ${MANPREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man8/
.endfor
.if defined(WITH_SIDMILTER_AR)
	@(cd ${WRKSRC}/libar && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.for i in ${MAN3}
	@${RM} -f ${MANPREFIX}/man/cat3/${i} ${MANPREFIX}/man/cat3/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man3/
.endfor
	${INSTALL_DATA} ${WRKSRC}/libar/ar.h ${PREFIX}/include/libar.h
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
