# Make file for Scintilla on Windows
# Copyright 1998-2010 by Neil Hodgson <neilh@scintilla.org>
# The License.txt file describes the conditions under which this software may be distributed.
# This makefile assumes the mingw32 version of GCC 3.x or 4.x is used and changes will
# be needed to use other compilers.

.SUFFIXES: .cxx
CC = g++
DLLWRAP = g++ -shared -Wl,--kill-at
DEL = del /q

COMPONENT = ../bin/Scintilla.dll
LEXCOMPONENT = ../bin/SciLexer.dll
LEXLIB = Lexers.a

vpath %.h ../src ../include
vpath %.cxx ../src

LDFLAGS=-mwindows -lstdc++ -limm32 -lole32 -luuid -mno-cygwin
# Add -MMD to get dependencies
INCLUDEDIRS=-I ../include -I ../src
CXXBASEFLAGS=-Wall -Wno-missing-braces -Wno-char-subscripts -Wno-strict-overflow -pedantic $(INCLUDEDIRS) -fno-rtti -mno-cygwin

ifdef DEBUG
CXXFLAGS=-DDEBUG -g $(CXXBASEFLAGS)
else
CXXFLAGS=-DNDEBUG -Os $(CXXBASEFLAGS)
STRIPFLAG=-s
endif

.cxx.o:
	$(CC) $(CXXFLAGS) -c $<

ALL:	$(COMPONENT) $(LEXCOMPONENT) $(LEXLIB) ScintillaWinS.o WindowAccessor.o

clean:
	$(DEL) *.exe *.o *.obj *.dll *.res *.map

deps:
	$(CC) -MM $(CXXFLAGS) *.cxx ../src/*.cxx >deps.mak

LEXOBJS:=$(addsuffix .o,$(basename $(notdir $(wildcard ../src/Lex*.cxx))))

SOBJS	= ScintillaWin.o ScintillaBase.o Editor.o CharClassify.o Decoration.o \
	Document.o ContractionState.o CellBuffer.o CallTip.o \
	ScintRes.o PlatWin.o PositionCache.o KeyMap.o Indicator.o LineMarker.o RESearch.o RunStyles.o \
	Selection.o Style.o ViewStyle.o AutoComplete.o UniConversion.o PropSet.o XPM.o PerLine.o
$(COMPONENT): $(SOBJS) Scintilla.def
	$(DLLWRAP) --add-stdcall-alias --target=i386-mingw32 -o $@ $(SOBJS) $(LDFLAGS) $(STRIPFLAG) --relocatable

LOBJS	= ScintillaWinL.o ScintillaBaseL.o Editor.o CharClassify.o Decoration.o \
	Document.o ContractionState.o CellBuffer.o CallTip.o \
	ScintRes.o PlatWin.o PositionCache.o KeyMap.o Indicator.o LineMarker.o RESearch.o RunStyles.o \
	Selection.o Style.o ViewStyle.o AutoComplete.o UniConversion.o KeyWords.o \
	DocumentAccessor.o PropSet.o ExternalLexer.o StyleContext.o XPM.o PerLine.o $(LEXOBJS)
$(LEXCOMPONENT): $(LOBJS) Scintilla.def
	$(DLLWRAP) --add-stdcall-alias --target=i386-mingw32 -o $@ $(LOBJS) $(LDFLAGS) $(STRIPFLAG) --relocatable

$(LEXLIB): $(LEXOBJS)
	$(AR) rc $@ $^
	ranlib $@

# Automatically generate dependencies for most files with "make deps"
include deps.mak

# These dependencies are maintained by hand as they do not use the default output name
ScintillaBaseL.o: ScintillaBase.cxx Platform.h Scintilla.h SciLexer.h \
 ContractionState.h CellBuffer.h CallTip.h KeyMap.h Indicator.h \
 LineMarker.h Style.h AutoComplete.h ViewStyle.h Document.h Editor.h \
 ScintillaBase.h PropSet.h Accessor.h DocumentAccessor.h \
 KeyWords.h ExternalLexer.h PerLine.h
ScintillaWinL.o: ScintillaWin.cxx Platform.h Scintilla.h SciLexer.h \
 ContractionState.h CellBuffer.h CallTip.h KeyMap.h Indicator.h \
 LineMarker.h Style.h AutoComplete.h ViewStyle.h Document.h Editor.h \
 ScintillaBase.h PropSet.h Accessor.h KeyWords.h \
 ExternalLexer.h UniConversion.h PerLine.h
ScintillaWinS.o: ScintillaWin.cxx Platform.h Scintilla.h \
 ContractionState.h CellBuffer.h CallTip.h KeyMap.h Indicator.h \
 LineMarker.h Style.h AutoComplete.h ViewStyle.h Document.h Editor.h \
 ScintillaBase.h UniConversion.h PerLine.h

ScintillaBaseL.o:
	$(CC) $(CXXFLAGS) -D SCI_LEXER -c $< -o $@

ScintillaWinS.o:
	$(CC) $(CXXFLAGS) -D STATIC_BUILD -c $< -o $@

ScintillaWinL.o:
	$(CC) $(CXXFLAGS) -D SCI_LEXER -c $< -o $@

ScintRes.o:	ScintRes.rc PlatformRes.h
	windres ScintRes.rc $@

