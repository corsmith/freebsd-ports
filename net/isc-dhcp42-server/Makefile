# Ports collection makefile for:	isc-dhcp42-server
# Date created:				29 June 2011
# Whom:					Ryan Steinmetz <rpsfa@rit.edu>
#
# $FreeBSD$
#

PORTNAME=	dhcp
DISTVERSION=	4.2.4
PORTREVISION=	${DHCP_PORTREVISION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	${PORTNAME}/${DISTVERSION}-${PATCHLEVEL}
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	42-${SUBSYS}
DISTNAME=	${PORTNAME}-${DISTVERSION}-${PATCHLEVEL}

MAINTAINER=	zi@FreeBSD.org
COMMENT?=	The ISC Dynamic Host Configuration Protocol server

LICENSE=	ISCL

USE_GMAKE=	yes

PATCHLEVEL=	P2
PORTREVISION_SERVER=	2
PORTREVISION_CLIENT=	0
PORTREVISION_RELAY=	0

SUBSYS?=	server
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-${PATCHLEVEL}

UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=IPV6

.if ${SUBSYS} == server
OPTIONS_DEFINE+=	PARANOIA LDAP LDAP_SSL BIND_SYMBOLS
OPTIONS_DEFAULT+=	PARANOIA LDAP_SSL
PARANOIA_DESC=		Enable support for chroot
LDAP_SSL_DESC=		Support LDAP over SSL/TLS
BIND_SYMBOLS_DESC=	Enable BIND internal symbol table
.endif

# PORTREVISION and CONFLICTS handling
.if ${SUBSYS} == client
CONFLICTS=	isc-dhcp3?-client-[0-9]* isc-dhcp41-client-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_CLIENT}
.elif ${SUBSYS} == relay
CONFLICTS=	isc-dhcp3?-relay-[0-9]* isc-dhcp41-relay-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_RELAY}
.else
CONFLICTS=	isc-dhcp3?-server-[0-9]* isc-dhcp41-server-[0-9]*
DHCP_PORTREVISION=	${PORTREVISION_SERVER}
.endif

.if ${SUBSYS} == server
USERS=		dhcpd
GROUPS=		dhcpd
.endif

MAN_COMPRESSED=	no
GNU_CONFIGURE=	yes
CPPFLAGS+=	-D_PATH_DHCLIENT_SCRIPT='\"${PREFIX}/sbin/dhclient-script\"' -D_PATH_DHCLIENT_CONF='\"${PREFIX}/etc/dhclient.conf\"' -D_PATH_DHCPD_CONF='\"${PREFIX}/etc/dhcpd.conf\"'
SCRIPTS_ENV+=	PKG_PREFIX=${PREFIX}

.include <bsd.port.options.mk>

.if ${SUBSYS} == client
MAN5+=		dhclient.conf.5 dhclient.leases.5
MAN8+=		dhclient.8 dhclient-script.8
CONF_FILE=	dhclient.conf
.elif ${SUBSYS} == server
CONFIGURE_ARGS+=--localstatedir=/var
MAN5+=		dhcpd.conf.5 dhcpd.leases.5 dhcp-eval.5 dhcp-options.5
MAN8+=		dhcpd.8
MAN1=		omshell.1
MAN3=		dhcpctl.3 omapi.3
CFLAGS+=	-fPIC
CONF_FILE=	dhcpd.conf
.if ${PORT_OPTIONS:MIPV6}
CONF_FILE+=	dhcpd6.conf
.endif
.else
MAN8+=		dhcrelay.8
.endif

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

.if ${SUBSYS} == server
USE_RC_SUBR=	isc-dhcpd
.elif ${SUBSYS} == relay
USE_RC_SUBR=	isc-dhcrelay
.endif

SCHEMA_DIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
DATADIR=	/var/db

MSG_FILE=	${.CURDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

REINPLACE_SUB=	PREFIX="${PREFIX}"
PKGMESSAGE_SUB=	PREFIX="${PREFIX}" MAN1PREFIX="${MAN1PREFIX}" \
		DOCSDIR="${DOCSDIR}"

.if ${PORT_OPTIONS:MPARANOIA}
CONFIGURE_ARGS+=--enable-paranoia --enable-early-chroot
SUB_LIST+=	PARANOIA=yes
.else
SUB_LIST+=	PARANOIA=no
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=--with-ldap
USE_OPENLDAP=	yes
LDAP_SCRIPT=	${WRKSRC}/contrib/ldap/dhcpd-conf-to-ldap
LDAP_SCHEMA=	${WRKSRC}/contrib/ldap/dhcp.schema
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
PORTDOCS+=	README.ldap
PLIST_SUB+=	SCHEMA_DIR="${SCHEMA_DIR:S,^${PREFIX}/,,}" LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP_SSL} && ${PORT_OPTIONS:MLDAP}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ldapcrypto
CONFIGURE_ENV+=	LIBS="-lssl"
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-dhcpv6
PLIST_SUB+=	IPV6=""
.else
CONFIGURE_ARGS+=--disable-dhcpv6
PLIST_SUB+=	IPV6="@comment "
.endif

.if ${PORT_OPTIONS:MBIND_SYMBOLS}
USE_PERL5=	yes
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bind__Makefile
.endif

post-patch:
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|/usr/local||g' \
		${WRKSRC}/doc/examples/dhcpd-dhcpv6.conf
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/client/dhclient.conf

do-install:
	${MAKE} -C ${WRKSRC}/${SUBSYS} install
.if ${SUBSYS} == server
	${MAKE} -C ${WRKSRC}/dhcpctl install
	${MAKE} -C ${WRKSRC}/dst install
	${MAKE} -C ${WRKSRC}/omapip install
	${MAKE} -C ${WRKSRC}/includes install
	${MAKE} -C ${WRKSRC}/common install
	${INSTALL_DATA} ${WRKSRC}/dhcpctl/dhcpctl.h ${PREFIX}/include
.if ${PORT_OPTIONS:MIPV6}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/dhcpd-dhcpv6.conf \
		${PREFIX}/etc/dhcpd6.conf.sample
.endif
.if ${PORT_OPTIONS:MLDAP}
	@${MKDIR} ${SCHEMA_DIR}
	${INSTALL_DATA} ${LDAP_SCHEMA} ${SCHEMA_DIR}
	${INSTALL_SCRIPT} ${LDAP_SCRIPT} ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MLDAP} && !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/contrib/ldap/README.ldap ${DOCSDIR}
.endif
.endif

post-install:
.if defined(CONF_FILE)
.for FILE in ${CONF_FILE}
	if [ ! -f ${PREFIX}/etc/${FILE} ]; then \
		${CP} -p ${PREFIX}/etc/${FILE}.sample ${PREFIX}/etc/${FILE} ; \
	fi
.endfor
.endif
.if ${SUBSYS} == client
	${INSTALL_SCRIPT} ${WRKSRC}/client/scripts/freebsd ${PREFIX}/sbin/dhclient-script
.elif ${SUBSYS} == server
.if ${PORT_OPTIONS:MIPV6}
	@${LN} -sf isc-dhcpd ${PREFIX}/etc/rc.d/isc-dhcpd6
.endif
.elif ${SUBSYS} == relay
.if ${PORT_OPTIONS:MIPV6}
	@${LN} -sf isc-dhcrelay ${PREFIX}/etc/rc.d/isc-dhcrelay6
.endif
.endif
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}
#@${REINPLACE_CMD} -e '/^%%LDAP%%/d' ${PKGMESSAGE}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
