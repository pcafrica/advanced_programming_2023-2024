MD_FILES:=$(wildcard *.md)
HTML_FILES:=$(patsubst %.md,%.html, $(MD_FILES))

MARP_EXE?=marp
MARP_OPTS?=--bespoke.progressbar --theme ../style/custom.css

all: $(HTML_FILES)

%.html: %.md
	$(MARP_EXE) $(MARP_OPTS) $< -o $@

clean:
	rm -rf $(HTML_FILES)

.PHONY: all clean
