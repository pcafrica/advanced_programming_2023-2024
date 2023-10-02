FILES_MD:=$(shell find . -type f -name "*.md")
FILES_HTML:=$(patsubst %.md,%.html, $(FILES_MD))
FILES_BACKUP:=$(addsuffix .backup, $(FILES_MD))
FILES_TMP:=$(shell find . -type f -name "*~")

SUBDIRS:=lectures labs

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

clean:
	$(RM) $(FILES_HTML)

distclean: clean
	$(RM) $(FILES_BACKUP) $(FILES_TMP)

.PHONY: all clean distclean $(MAKECMDGOALS) $(SUBDIRS)
