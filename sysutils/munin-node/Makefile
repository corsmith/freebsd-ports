# New ports collection makefile for:	munin-node
# Date created:				25 Januar 2004
# Whom:					Lupe Christoph <lupe@lupe-christoph.de>
#
# $FreeBSD$
#

PORTNAME=	munin
PORTVERSION=	${MUNIN_VERSION}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MUNIN_SITES}
PKGNAMESUFFIX=	-node

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Node-specific part of Munin

BUILD_DEPENDS=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build \
		p5-DateTime-HiRes>=0:${PORTSDIR}/devel/p5-DateTime-HiRes \
		munin-common>=0:${PORTSDIR}/sysutils/munin-common \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-DateTime-HiRes>=0:${PORTSDIR}/devel/p5-DateTime-HiRes \
		munin-common>=0:${PORTSDIR}/sysutils/munin-common \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		bash:${PORTSDIR}/shells/bash

DISTINFO_FILE=	${MUNIN_DISTINFO}
EXTRA_PATCHES+=	${MUNIN_PATCHES}
USE_PERL5=	yes
USE_GMAKE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
REINPLACE_ARGS=	-i ""

.include "${.CURDIR}/../munin-common/munin.mk"

ALL_TARGET=	build-node build-plugins
INSTALL_TARGET=	install-node-prime install-plugins-prime

MAN1=		munin-node-configure.1 \
		munin-node.1 \
		munin-run.1 \
		munin-sched.1 \
		munindoc.1
MAN3_NODE=	Munin::Node::Config.3 \
		Munin::Node::Configure::Debug.3 \
		Munin::Node::Configure::History.3 \
		Munin::Node::Configure::HostEnumeration.3 \
		Munin::Node::Configure::Plugin.3 \
		Munin::Node::Configure::PluginList.3 \
		Munin::Node::Logger.3 \
		Munin::Node::OS.3 \
		Munin::Node::ProxySpooler.3 \
		Munin::Node::SNMPConfig.3 \
		Munin::Node::Server.3 \
		Munin::Node::Service.3 \
		Munin::Node::Session.3 \
		Munin::Node::SpoolReader.3 \
		Munin::Node::SpoolWriter.3 \
		Munin::Node::Utils.3
MAN3_PLUGIN=	Munin::Plugin.3 \
		Munin::Plugin::Pgsql.3 \
		Munin::Plugin::SNMP.3
MAN3=		${MAN3_NODE} ${MAN3_PLUGIN}
MAN5=		munin-node.conf.5
MAN8=		munin.8

SUB_FILES=	pkg-message munin-node-revive.sh
USE_RC_SUBR=	munin-node munin-sched

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/node/sbin/munin-node \
		${WRKSRC}/node/sbin/munin-node-configure \
		${WRKSRC}/node/sbin/munin-run
	@${FIND} ${WRKSRC}/node/sbin -type f -name "*.orig" -delete

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/munin-node \
		${PREFIX}/etc/rc.d/munin-node
	@${INSTALL_DATA} ${WRKSRC}/build/node/munin-node.conf \
		${ETCDIR}/munin-node.conf.sample
	@if [ ! -f ${ETCDIR}/munin-node.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/munin-node.conf.sample \
			${ETCDIR}/munin-node.conf; \
	fi
	@${INSTALL_DATA} ${FILESDIR}/plugins.conf \
		${ETCDIR}/plugin-conf.d/plugins.conf.sample
	@if [ ! -f ${ETCDIR}/plugin-conf.d/plugins.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/plugin-conf.d/plugins.conf.sample \
			${ETCDIR}/plugin-conf.d/plugins.conf; \
	fi
	@(cd ${WRKSRC}/node/blib/bindoc && for man in ${MAN1}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man1; \
	done)
	@(cd ${WRKSRC}/node/blib/libdoc && for man in ${MAN3_NODE}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man3; \
	done)
	@(cd ${WRKSRC}/plugins/blib/libdoc && for man in ${MAN3_PLUGIN}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man3; \
	done)
	@(cd ${WRKSRC}/build/doc && for man in ${MAN5}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man5; \
	done)
	@(cd ${WRKSRC}/build/doc && for man in ${MAN8}; do \
		${INSTALL_MAN} -C $$man ${PREFIX}/man/man8; \
	done)
	@${ECHO} ${PORTVERSION} > ${PREFIX}/etc/munin/VERSION.node
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
