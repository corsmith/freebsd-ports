--- cpp.orig/src/IceSSL/TrustManager.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceSSL/TrustManager.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -20,7 +20,7 @@
 using namespace std;
 using namespace IceSSL;
 
-IceUtil::Shared* IceInternal::upCast(IceSSL::TrustManager* p) { return p; }
+IceUtil::Shared* IceSSL::upCast(IceSSL::TrustManager* p) { return p; }
 
 TrustManager::TrustManager(const Ice::CommunicatorPtr& communicator) :
     _communicator(communicator)
