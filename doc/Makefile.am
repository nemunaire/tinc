## Process this file with automake to get Makefile.in

info_TEXINFOS = tinc.texi

man_MANS = tincd.8 tinc.conf.5

EXTRA_DIST = tincinclude.texi.in tincd.8.in tinc.conf.5.in sample-config.tar.gz

CLEANFILES = *.html tincd.8 tinc.conf.5 tincinclude.texi

# Use `ginstall' in the definition of man_MANS to avoid
# confusion with the `install' target.  The install rule transforms `ginstall'
# to install before applying any user-specified name transformations.
transform = s/ginstall/install/; @program_transform_name@

# For additional rules usually of interest only to the maintainer,
# see GNUmakefile and Makefile.maint.

sample-config.tar.gz: $(srcdir)/sample-config
	$(AM_V_GEN)GZIP=$(GZIP_ENV) $(AMTAR) chozf $@ --exclude .svn $<

texi2html: tinc.texi
	$(AM_V_GEN)texi2html -split=chapter $<

tincd.8.html: tincd.8
	$(AM_V_GEN)w3mman2html $< > $@

tinc.conf.5.html: tinc.conf.5
	$(AM_V_GEN)w3mman2html $< > $@

substitute = sed \
	-e s,'@PACKAGE\@',"$(PACKAGE)",g \
	-e s,'@VERSION\@',"$(VERSION)",g \
	-e s,'@sysconfdir\@',"$(sysconfdir)",g \
	-e s,'@localstatedir\@',"$(localstatedir)",g

tincd.8: $(srcdir)/tincd.8.in
	$(AM_V_GEN)$(substitute) $< > $@

tinc.conf.5: $(srcdir)/tinc.conf.5.in
	$(AM_V_GEN)$(substitute) $< > $@

tincinclude.texi: $(srcdir)/tincinclude.texi.in
	$(AM_V_GEN)$(substitute) $< > $@

tinc.texi: tincinclude.texi
