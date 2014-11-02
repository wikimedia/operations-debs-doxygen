#
# This file was generated from Makefile.in on Thu Aug 21 10:48:35 CEST 2014
#

DOXYGEN   = /Users/dimitri/doxygen
TMAKEPATH = /Users/dimitri/doxygen/tmake/lib/macosx-c++
ENV       = env TMAKEPATH="$(TMAKEPATH)"
TMAKE     = /Users/dimitri/doxygen/tmake/bin/tmake
MAKE      = /opt/local/bin/gmake
PYTHON    = /opt/local/bin/python2
PERL      = /opt/local/bin/perl
LEX       = /usr/bin/flex
RM        = rm -f
CP        = cp
VERSION   = 1.8.8
INSTALL   = /usr/local
INSTTOOL  = /opt/local/bin/ginstall
DOXYDOCS  = ..
DOCDIR    = $(INSTALL)/share/doc/packages/doxygen
QTDIR     = /usr
HAVE_DOT  = /usr/local/bin/dot
MKSPECS   = -spec macx-g++
#
# 
#
# Copyright (C) 1997-2014 by Dimitri van Heesch.
#
# Permission to use, copy, modify, and distribute this software and its
# documentation under the terms of the GNU General Public License is hereby 
# granted. No representations are made about the suitability of this software 
# for any purpose. It is provided "as is" without express or implied warranty.
# See the GNU General Public License for more details.
#
# Documents produced by Doxygen are derivative works derived from the
# input used in their production; they are not affected by this license.

all: language config.doc FORCE
	DOXYGEN_DOCDIR=$(DOXYDOCS); \
	export DOXYGEN_DOCDIR; \
        VERSION=$(VERSION) ; \
	export VERSION; \
	"$(DOXYGEN)/bin/doxygen"
	@rm -f ../latex/refman.tex
	@cp doxygen_logo*.gif ../html
	@cp Makefile.latex ../latex/Makefile
	@sed -e "s/\$$VERSION/$(VERSION)/g" doxygen_manual.tex >../latex/doxygen_manual.tex
	@sed -e "s/\$$VERSION/$(VERSION)/g" doxygen.sty >../latex/doxygen.sty 
	@epstopdf doxygen_logo.eps --outfile=../latex/doxygen_logo.pdf

clean: 
	rm -rf ../html ../latex *.bak 

language: language.doc 

language.doc: $(wildcard ../src/translator*.h) maintainers.txt language.tpl translator.py
	$(PYTHON) translator.py

config.doc:  ../src/config.xml ../src/configgen.py
	$(PYTHON) ../src/configgen.py -doc ../src/config.xml > config.doc

FORCE:
