# New ports collection makefile for:	django
# Date created:				2005-11-19
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	django
PORTVERSION=	1.3.3
CATEGORIES=	www python
MASTER_SITES=	http://www.djangoproject.com/m/releases/${PORTVERSION:R}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Django-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	High-level Python Web framework

LICENSE=	BSD

LATEST_LINK=	${PYTHON_PKGNAMEPREFIX}django13

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Django

CONFLICTS=	py2[0-9]-django-devel-[0-9]* py2[0-9]-django-1.[24]*

DOCSDIR=	${PREFIX}/share/doc/py-django

OPTIONS_DEFINE=	PGSQL MYSQL SQLITE FASTCGI HTMLDOCS
OPTIONS_DEFAULT=

HTMLDOCS_DESC=	Build and install the HTML documentation (requires Sphinx)

MAN1=		daily_cleanup.1 django-admin.1 gather_profile_stats.1

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/_psycopg.so:${PORTSDIR}/databases/py-psycopg2
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-changeset_16520.diff
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MFASTCGI}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup
.endif

.if ${PORT_OPTIONS:MHTMLDOCS}
.	if defined(NOPORTDOCS)
IGNORE=	you cannot build documentation while setting NOPORTDOCS
.	endif
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-changeset_16223_16231.diff
PORTDOCS=	*
.endif

post-build:
.if ${PORT_OPTIONS:MHTMLDOCS}
	cd ${WRKSRC}/docs && ${MAKE} html
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${MAN1PREFIX}/man/man1
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"			* See http://docs.djangoproject.com/ for complete documentation"
	@${ECHO_MSG}	""
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
