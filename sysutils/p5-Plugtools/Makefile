# New ports collection makefile for:	sysutils/p5-Plugtools
# Date created:		2009-10-31
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Plugtools
PORTVERSION=	1.3.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Manages POSIX users in LDAP and is extensible via a plugin system

RUN_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Sys-User-UIDhelper>=0:${PORTSDIR}/sysutils/p5-Sys-User-UIDhelper \
		p5-Sys-Group-GIDhelper>=0:${PORTSDIR}/sysutils/p5-Sys-Group-GIDhelper \
		p5-Net-LDAP-posixAccount>=0:${PORTSDIR}/net/p5-Net-LDAP-posixAccount \
		p5-Net-LDAP-posixGroup>=0:${PORTSDIR}/net/p5-Net-LDAP-posixGroup \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-String-ShellQuote>=0:${PORTSDIR}/textproc/p5-String-ShellQuote \
		p5-File-BaseDir>=0:${PORTSDIR}/devel/p5-File-BaseDir \
		p5-Config-IniHash>=0:${PORTSDIR}/devel/p5-Config-IniHash

PERL_CONFIGURE=	yes

MAN3=		Plugtools.3 \
		Plugtools::Plugins::Dump.3

.include <bsd.port.mk>
