# Make file for SciTE on Windows
# Copyright 1998-2000 by Neil Hodgson <neilh@scintilla.org>
# The License.txt file describes the conditions under which this software may be distributed.
# This makefile assumes the mingw32 version of GCC 2.95.2 is used and changes will
# be needed to use other compilers.

.SUFFIXES: .cxx
CC = g++
DLLWRAP = dllwrap

PROG	= ../bin/SciTE.exe
PROGSTATIC = ../bin/Sc1.exe

vpath %.h ../src ../../scintilla/include ../../scintilla/win32
vpath %.cxx ../src
vpath %.o ../../scintilla/win32

LDFLAGS = -lkernel32 -lgdi32 -luser32 -lwinmm -lcomdlg32 -lcomctl32 -limm32 -lole32 -luuid
#CXXFLAGS = -W -Wall
# Add -MMD to get dependencies
#CXXFLAGS = -g -pg -pedantic -Os -fno-exceptions -fvtable-thunks -fno-rtti
INCLUDEDIRS=-I ../../scintilla/include -I ../../scintilla/win32 -I ../src 
RCINCLUDEDIRS=--include-dir ../../scintilla/win32 --include-dir ../src 
CXXFLAGS = -pedantic $(INCLUDEDIRS) -Os -fno-exceptions -fvtable-thunks -fno-rtti

.cxx.o:
	$(CC) $(CXXFLAGS) -c $< -o $@

OBJS	= SciTEBase.o SciTEWin.o Accessor.o KeyWords.o PropSet.o PlatWin.o SciTERes.o

ALL:	$(PROG) $(PROGSTATIC)

clean:
	del /q *.exe *.o *.obj *.dll *.res *.map

$(PROG): $(OBJS)
	$(CC) "-Wl,-s" -Xlinker --subsystem -Xlinker windows -o $(PROG) $^ $(LDFLAGS)

OBJSSTATIC = Sc1.o SciTEBase.o ScintillaWinS.o ScintillaBase.o Editor.o Accessor.o KeyWords.o PropSet.o \
	ContractionState.o Document.o CellBuffer.o CallTip.o Sc1Res.o PlatWin.o \
	KeyMap.o Indicator.o LineMarker.o Style.o ViewStyle.o AutoComplete.o

$(PROGSTATIC): $(OBJSSTATIC)
	$(CC) "-Wl,-s" -Xlinker --subsystem -Xlinker windows -o $(PROGSTATIC) $^ $(LDFLAGS)

SciTEBase.o: SciTEBase.cxx Platform.h SciTE.h PropSet.h Accessor.h \
 KeyWords.h Scintilla.h SciLexer.h SciTEBase.h
SciTEWin.o: SciTEWin.cxx Platform.h SciTE.h PropSet.h Accessor.h \
 KeyWords.h Scintilla.h SciTEBase.h

#	$(CC) -Xlinker --subsystem -Xlinker windows -o $(PROGSTATIC) $(OBJSSTATIC) $(LDFLAGS)

Sc1.o: SciTEWin.cxx SciTE.h Accessor.h KeyWords.h PropSet.h Scintilla.h
	$(CC) $(CXXFLAGS) -D STATIC_BUILD -c $< -o Sc1.o

SciTERes.o:	SciTERes.rc SciTE.h PlatformRes.h
	windres $(RCINCLUDEDIRS) SciTERes.rc SciTERes.o

Sc1Res.o:	SciTERes.rc SciTE.h PlatformRes.h
	windres $(RCINCLUDEDIRS) SciTERes.rc --define STATIC_BUILD Sc1Res.o
