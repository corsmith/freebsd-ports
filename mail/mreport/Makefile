# New ports collection makefile for:	mreport
# Date created:		19 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	mreport
PORTVERSION=	0.9
CATEGORIES=	mail sysutils
MASTER_SITES=	http://yenigul.net/mreport/

MAINTAINER=	ismail@EnderUNIX.org
COMMENT=	Sendmail logfile summary tool

ALL_TARGET=	ALL
MAN8=		mreport.8
PLIST_FILES=	sbin/mreport

post-patch:
	@${REINPLACE_CMD} -e "s/^.TH mreport 1/.TH mreport 8/g; s/^.LO 1/.LO 8/g;" \
		${WRKSRC}/mreport.1
	@${REINPLACE_CMD} -E -e "s/^CC.+//g; s|-Wall -c -O2|${CFLAGS} -c|g;" \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mreport ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/mreport.1 ${PREFIX}/man/man8/mreport.8

.include <bsd.port.mk>
