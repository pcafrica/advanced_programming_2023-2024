FILES_MD:=$(wildcard *.md)
FILES_HTML:=$(patsubst %.md,%.html, $(FILES_MD))
FILES_BACKUP:=$(addsuffix .backup,$(FILES_MD))

MARP_EXE?=marp
MARP_OPTS?=--bespoke.progressbar --theme ../style/custom.css

all: $(FILES_HTML)

%.html: %.md
	$(MARP_EXE) $(MARP_OPTS) $< -o $@

clean:
	$(RM) $(FILES_HTML)

distclean: clean
	$(RM) $(FILES_BACKUP) *~

.PHONY: all clean
