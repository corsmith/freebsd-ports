--- ./e2fsck/unix.c.orig	2012-03-23 14:15:37.000000000 +0100
+++ ./e2fsck/unix.c	2012-04-01 17:15:48.000000000 +0200
@@ -9,8 +9,6 @@
  * %End-Header%
  */
 
-#define _XOPEN_SOURCE 600 /* for inclusion of sa_handler in Solaris */
-
 #include "config.h"
 #include <stdio.h>
 #ifdef HAVE_STDLIB_H
@@ -560,6 +558,24 @@
 	return 0;
 }
 
+static int e2fsck_progress_once(e2fsck_t ctx, int pass, unsigned long cur, unsigned long max)
+{
+	char buf[80];
+	float percent;
+
+	if (pass == 0)
+		return 0;
+	
+	percent = calc_percent(&e2fsck_tbl, pass, cur, max);
+	e2fsck_simple_progress(ctx, ctx->device_name,
+			percent, 0);
+
+	printf("\n");
+	ctx->progress = 0;
+	return 0;
+}
+
+
 #define PATH_SET "PATH=/sbin"
 
 /*
@@ -592,6 +608,17 @@
 	ctx->progress = e2fsck_update_progress;
 }
 
+static void signal_progress_now(int sig EXT2FS_ATTR((unused)))
+{
+	e2fsck_t ctx = e2fsck_global_ctx;
+
+	if (!ctx)
+		return;
+
+	ctx->progress = e2fsck_progress_once;
+	ctx->progress_fd = 0;
+}
+
 static void signal_progress_off(int sig EXT2FS_ATTR((unused)))
 {
 	e2fsck_t ctx = e2fsck_global_ctx;
@@ -960,6 +987,8 @@
 	sigaction(SIGUSR1, &sa, 0);
 	sa.sa_handler = signal_progress_off;
 	sigaction(SIGUSR2, &sa, 0);
+	sa.sa_handler = signal_progress_now;
+	sigaction(SIGINFO, &sa, 0);
 #endif
 
 	/* Update our PATH to include /sbin if we need to run badblocks  */
