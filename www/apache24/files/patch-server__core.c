--- ./server/core.c.orig	2012-08-14 19:59:24.000000000 -0400
+++ ./server/core.c	2012-09-08 06:56:52.921143332 -0400
@@ -3132,7 +3132,7 @@
 AP_DECLARE(const char *) ap_get_server_description(void)
 {
     return server_description ? server_description :
-        AP_SERVER_BASEVERSION " (" PLATFORM ")";
+        AP_SERVER_BASEVERSION " (FreeBSD)";
 }
 
 AP_DECLARE(const char *) ap_get_server_banner(void)
@@ -3185,7 +3185,7 @@
         ap_add_version_component(pconf, AP_SERVER_BASEPRODUCT "/" AP_SERVER_MAJORVERSION);
     }
     else {
-        ap_add_version_component(pconf, AP_SERVER_BASEVERSION " (" PLATFORM ")");
+        ap_add_version_component(pconf, AP_SERVER_BASEVERSION " (FreeBSD)");
     }
 
     /*
@@ -3195,7 +3195,7 @@
     if (ap_server_tokens != SrvTk_FULL) {
         banner_locked++;
     }
-    server_description = AP_SERVER_BASEVERSION " (" PLATFORM ")";
+    server_description = AP_SERVER_BASEVERSION " (FreeBSD)";
 }
 
 static const char *set_serv_tokens(cmd_parms *cmd, void *dummy,
