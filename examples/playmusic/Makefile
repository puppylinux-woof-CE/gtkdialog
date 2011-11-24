
# If PREFIX is set when calling then initialise with that,
# otherwise initialise with whatever is shown here.
PREFIX?=/usr/local
BINDIR=$(PREFIX)/bin
DATADIR=$(PREFIX)/share
PACKAGE_DATA_DIR=$(DATADIR)/$(TARGET)

# Strip comments from source files to reduce their size: true or false.
STRIP_COMMENTS?=true

# You shouldn't need to edit anything below -----------------------------------
TARGET=playmusic
VERSION=$(shell grep "VERSION=" $(TARGET) | sed 's|.*=||')

.PHONY: all install uninstall

all:
	@echo
	@echo "PREFIX=$(PREFIX)"
	@echo "DISTDIR=$(DISTDIR)"
	@echo "STRIP_COMMENTS=$(STRIP_COMMENTS)"
	@echo
	@echo "Usage examples:"
	@echo "    make install"
	@echo "    make STRIP_COMMENTS=false install"
	@echo "    make PREFIX=/usr install"
	@echo "    make DISTDIR=$(TARGET)-$(VERSION) install"
	@echo "    make uninstall"
	@echo "    make PREFIX=/usr uninstall"
	@echo

install:
	mkdir -p $(DISTDIR)$(BINDIR)
	mkdir -p $(DISTDIR)$(DATADIR)/applications
	mkdir -p $(DISTDIR)$(DATADIR)/icons/hicolor/scalable/apps
	mkdir -p $(DISTDIR)$(PACKAGE_DATA_DIR)

	if [ "$(STRIP_COMMENTS)" = true ] ; then \
		sed -e '/## /d' -e '/ ##/d' \
			-e "s|^\(PACKAGE_DATA_DIR=\)\(.*\)|\1$(PACKAGE_DATA_DIR)|" \
			$(TARGET) > $(DISTDIR)$(BINDIR)/$(TARGET); \
		chmod 755 $(DISTDIR)$(BINDIR)/$(TARGET); \
	else \
		sed -e "s|^\(PACKAGE_DATA_DIR=\)\(.*\)|\1$(PACKAGE_DATA_DIR)|" \
			$(TARGET) > $(DISTDIR)$(BINDIR)/$(TARGET); \
		chmod 755 $(DISTDIR)$(BINDIR)/$(TARGET); \
	fi

	sed -e "s|^\(Icon=\)\(.*\)|\1$(DATADIR)/icons/hicolor/scalable/apps/$(TARGET).svg|" \
		$(TARGET).desktop > $(DISTDIR)$(DATADIR)/applications/$(TARGET).desktop; \
	cp $(TARGET).svg $(DISTDIR)$(DATADIR)/icons/hicolor/scalable/apps

	for func in func*; do \
		if [ "$(STRIP_COMMENTS)" = true ] ; then \
			sed -e '/## /d' -e '/ ##/d' $$func > $(DISTDIR)$(PACKAGE_DATA_DIR)/$$func; \
		else \
			cp $$func $(DISTDIR)$(PACKAGE_DATA_DIR); \
		fi; \
		chmod 755 $(DISTDIR)$(PACKAGE_DATA_DIR)/$$func; \
	done
	cp background.png $(DISTDIR)$(PACKAGE_DATA_DIR)

uninstall:
	rm -f $(DISTDIR)$(BINDIR)/$(TARGET)
	rm -f $(DISTDIR)$(DATADIR)/applications/$(TARGET).desktop
	rm -f $(DISTDIR)$(DATADIR)/icons/hicolor/scalable/apps/$(TARGET).svg
	rm -rf $(DISTDIR)$(PACKAGE_DATA_DIR)

