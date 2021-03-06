# New ports collection makefile for:	devel/p5-MooseX-Storage
# Date created:				2008/09/06
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	MooseX-Storage
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An serialization framework for Moose classes

BUILD_DEPENDS=	p5-JSON-Any>=1.15:${PORTSDIR}/converters/p5-JSON-Any \
		p5-Moose>=0.99:${PORTSDIR}/devel/p5-Moose \
		p5-String-RewritePrefix>=0.004:${PORTSDIR}/textproc/p5-String-RewritePrefix
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-JSON>=0.06:${PORTSDIR}/devel/p5-Test-JSON \
		p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Without-Module>=0:${PORTSDIR}/devel/p5-Test-Without-Module \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	yes

MAN3=		MooseX::Storage.3 \
		MooseX::Storage::Base::WithChecksum.3 \
		MooseX::Storage::Basic.3 \
		MooseX::Storage::Deferred.3 \
		MooseX::Storage::Engine.3 \
		MooseX::Storage::Engine::IO::AtomicFile.3 \
		MooseX::Storage::Engine::IO::File.3 \
		MooseX::Storage::Engine::Trait::DisableCycleDetection.3 \
		MooseX::Storage::Engine::Trait::OnlyWhenBuilt.3 \
		MooseX::Storage::Format::JSON.3 \
		MooseX::Storage::Format::Storable.3 \
		MooseX::Storage::Format::YAML.3 \
		MooseX::Storage::IO::AtomicFile.3 \
		MooseX::Storage::IO::File.3 \
		MooseX::Storage::IO::StorableFile.3 \
		MooseX::Storage::Meta::Attribute::DoNotSerialize.3 \
		MooseX::Storage::Meta::Attribute::Trait::DoNotSerialize.3 \
		MooseX::Storage::Traits::DisableCycleDetection.3 \
		MooseX::Storage::Traits::OnlyWhenBuilt.3 \
		MooseX::Storage::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
