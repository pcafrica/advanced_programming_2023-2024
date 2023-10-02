FILES_MD:=$(shell find . -type f -name "*.md")
FILES_HTML:=$(patsubst %.md,%.html, $(FILES_MD))
FILES_BACKUP:=$(addsuffix .backup, $(FILES_MD))
FILES_TMP:=$(shell find . -type f -name "*~")

MARP_EXE?=marp
MARP_OPTS?=--bespoke.progress --theme ../style/custom.css

all: $(FILES_HTML)

%.html: %.md
	$(MARP_EXE) $(MARP_OPTS) $< -o $@

clean:
	$(RM) $(FILES_HTML)

distclean: clean
	$(RM) $(FILES_BACKUP) $(FILES_TMP)

.PHONY: all clean
