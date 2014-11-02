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
# Copyright (C) 1997-2000 by Dimitri van Heesch.
# 
# Permission to use, copy, modify, and distribute this software and its
# documentation under the terms of the GNU General Public License is hereby 
# granted. No representations are made about the suitability of this software 
# for any purpose. It is provided "as is" without express or implied warranty.
# See the GNU General Public License for more details.
# 
# Documents produced by Doxygen are derivative works derived from the
# input used in their production; they are not affected by this license.
# 

all: Makefile.vhdlparser Makefile
	$(MAKE) -f Makefile.vhdlparser    $@

Makefile.vhdlparser: vhdlparser.pro 
	$(ENV) $(PERL) "$(TMAKE)" vhdlparser.pro >Makefile.vhdlparser

tmake: 
	$(ENV) $(PERL) "$(TMAKE)" vhdlparser.pro >Makefile.vhdlparser

clean: Makefile.vhdlparser 
	$(MAKE) -f Makefile.vhdlparser    clean 

regenerate:
	$(RM) CharStream.cc CharStream.h ErrorHandler.h ParseException.cc ParseException.h \
	      Token.cc Token.h TokenManager.h TokenMgrError.cc TokenMgrError.h VhdlParser.cc VhdlParser.h \
	      VhdlParserConstants.h VhdlParserTokenManager.cc VhdlParserTokenManager.h \
              JavaCC.h
	javacc vhdlparser.jj
	patch  <vhdlparser.patch
	$(CP)  JavaCC.h.in JavaCC.h

distclean: clean
	$(RM) Makefile vhdlparser.pro

FORCE:
