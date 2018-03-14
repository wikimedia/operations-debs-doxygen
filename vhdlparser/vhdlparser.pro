#
# This file was generated from vhdlparser.pro.in on Thu Aug 21 10:48:35 CEST 2014
#

TEMPLATE	= lib
CONFIG		= warn_on staticlib debug
HEADERS		= CharStream.h \
		  ErrorHandler.h \
                  JavaCC.h \
                  ParseException.h \
		  TokenManager.h \
		  Token.h \
		  vhdlstring.h \
		  VhdlParser.h \
		  VhdlParserConstants.h \
		  VhdlParserTokenManager.h \
		  TokenMgrError.h \
	          VhdlParserIF.h \
                  VhdlParserErrorHandler.hpp

SOURCES		= CharStream.cc \
		  ParseException.cc \
		  Token.cc \
		  TokenMgrError.cc \
		  VhdlParser.cc \
		  VhdlParserTokenManager.cc \
                  VhdlParserIF.cpp

INCLUDEPATH = . ../src ../qtools generated_src/doxygen
#TMAKE_CXXFLAGS += -DQT_NO_CODECS -DQ T_LITE_UNICODE

#must enable -fexceptions because we have try catch blocks in VhdlParser.cc
TMAKE_CXXFLAGS +=-w -fexceptions -DQT_LITE_UNICODE
win32:TMAKE_CXXFLAGS += -fexceptions -DQT_NODLL
win32-g++:TMAKE_CXXFLAGS += -fexceptions -D__CYGWIN__ -DALL_STATIC
OBJECTS_DIR = ../objects/vhdlparser
DESTDIR = ../lib
TMAKE_MOC = /usr/bin/moc
LIBS += -L/opt/local/lib
INCLUDEPATH += /opt/local/include
