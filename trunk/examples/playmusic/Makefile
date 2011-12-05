
# If PREFIX is set when calling then initialise with that,
# otherwise initialise with whatever is shown here.
PREFIX?=/usr/local
BINDIR=$(PREFIX)/bin
DATADIR=$(PREFIX)/share
PACKAGE_DATA_DIR=$(DATADIR)/$(TARGET)

# Strip comments from source files to reduce their size: true or false.
STRIP_COMMENTS?=true

# You shouldn't need to edit anything below -----------------------------------
TARGET=$(shell grep "TARGET=" main | sed 's|.*=||')
VERSION=$(shell grep "VERSION=" main | sed 's|.*=||')

.PHONY: all check dist install uninstall

all: check
	@echo
	@echo "Defaults:"
	@echo "    PREFIX=$(PREFIX)"
	@echo "    DESTDIR=$(DESTDIR)"
	@echo "    STRIP_COMMENTS=$(STRIP_COMMENTS)"
	@echo
	@echo "Usage examples:"
	@echo "    make install"
	@echo "    make STRIP_COMMENTS=false install"
	@echo "    make PREFIX=/usr install"
	@echo "    make DESTDIR=$(TARGET)-$(VERSION) install"
	@echo "    make uninstall"
	@echo "    make PREFIX=/usr uninstall"
	@echo

check:
	@if [ -z "$(TARGET)" -o -z "$(VERSION)" ]; then \
		echo "Error: TARGET and/or VERSION not set."; \
		exit 1; \
	fi

dist: check
	rm -rf $(TARGET)-$(VERSION)
	mkdir $(TARGET)-$(VERSION)
	cp background.png ChangeLog cover.png func* main Makefile \
		$(TARGET).desktop $(TARGET)*.png README $(TARGET)-$(VERSION)
	tar czvf $(TARGET)-$(VERSION).tar.gz $(TARGET)-$(VERSION)/
	rm -rf $(TARGET)-$(VERSION)

install: check
	mkdir -p $(DESTDIR)$(BINDIR)
	mkdir -p $(DESTDIR)$(DATADIR)/applications
	mkdir -p $(DESTDIR)$(DATADIR)/icons/hicolor/64x64/apps
	mkdir -p $(DESTDIR)$(PACKAGE_DATA_DIR)

	if [ "$(STRIP_COMMENTS)" = true ] ; then \
		sed -e '/## /d' -e '/ ##/d' \
			-e "s|^\(PACKAGE_DATA_DIR=\)\(.*\)|\1$(PACKAGE_DATA_DIR)|" \
			main > $(DESTDIR)$(BINDIR)/$(TARGET); \
	else \
		sed -e "s|^\(PACKAGE_DATA_DIR=\)\(.*\)|\1$(PACKAGE_DATA_DIR)|" \
			main > $(DESTDIR)$(BINDIR)/$(TARGET); \
	fi
	chmod 755 $(DESTDIR)$(BINDIR)/$(TARGET)

	sed -e "s|^\(Icon=\)\(.*\)|\1$(DATADIR)/icons/hicolor/64x64/apps/$(TARGET).png|" \
		$(TARGET).desktop > $(DESTDIR)$(DATADIR)/applications/$(TARGET).desktop; \
	cp $(TARGET)64.png $(DESTDIR)$(DATADIR)/icons/hicolor/64x64/apps/$(TARGET).png

	for func in func*; do \
		if [ "$(STRIP_COMMENTS)" = true ] ; then \
			sed -e '/## /d' -e '/ ##/d' $$func > $(DESTDIR)$(PACKAGE_DATA_DIR)/$$func; \
		else \
			cp $$func $(DESTDIR)$(PACKAGE_DATA_DIR); \
		fi; \
		chmod 755 $(DESTDIR)$(PACKAGE_DATA_DIR)/$$func; \
	done
	cp background.png cover.png README $(DESTDIR)$(PACKAGE_DATA_DIR)

uninstall: check
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
	rm -f $(DESTDIR)$(DATADIR)/applications/$(TARGET).desktop
	rm -f $(DESTDIR)$(DATADIR)/icons/hicolor/64x64/apps/$(TARGET).png
	rm -rf $(DESTDIR)$(PACKAGE_DATA_DIR)

