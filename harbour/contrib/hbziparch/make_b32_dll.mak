#
# $Id$
#
# 旼컴컴컴컴컴컴컴컴컴컴�
# � general definition  넴
# 읕컴컴컴컴컴컴컴컴컴컴昴
#  賽賽賽賽賽賽賽賽賽賽賽�
# BIN_DIR is defined in dll_55.bat, please adjust accordingly

CC          = bcc32

# 旼컴컴컴컴컴컴컴컴커
# � source directory 넴
# 읕컴컴컴컴컴컴컴컴켸�
#  賽賽賽賽賽賽賽賽賽賽
# This is standard per repository

COMMON_DIR        = .

# 旼컴컴컴컴컴컴컴컴컴컴컴컴컴�
# � obj file output directory 넴
# 읕컴컴컴컴컴컴컴컴컴컴컴컴컴昴
#  賽賽賽賽賽賽賽賽賽賽賽賽賽賽�
# Please adjust according to your environment

OBJ_DIR           = obj\dll\b32

# 旼컴컴컴컴컴컴컴컴컴�
# � include directory 넴
# 읕컴컴컴컴컴컴컴컴컴昴
#  賽賽賽賽賽賽賽賽賽賽�

INCLUDE_DIR  = include;..\..\include;

# 旼컴컴컴컴컴컴컴커
# � compiler flags 넴
# 읕컴컴컴컴컴컴컴켸�
#  賽賽賽賽賽賽賽賽賽


C_USR          = -tW -D__WIN32__ -D__EXPORT__
CLIBFLAGS      = $(C_USR) -a8 -OS -O2 -6 -c -I$(INCLUDE_DIR) -d -w-

# 旼컴컴컴커
# � output 넴
# 읕컴컴컴켸�
#  賽賽賽賽賽
# Please adjust according to your environment

HARBOUR_DLL = ..\..\lib\b32\hbziparchdll.dll

# 旼컴컴컴컴컴컴컴컴컴�
# � HARBOUR_DLL rules 넴
# 읕컴컴컴컴컴컴컴컴컴昴
#  賽賽賽賽賽賽賽賽賽賽�

HARBOUR_DLL_OBJS = \
   $(OBJ_DIR)\ziparchive.obj\
   $(OBJ_DIR)\zip.obj\
   $(OBJ_DIR)\zipplatform.obj\
   $(OBJ_DIR)\zipstorage.obj\
   $(OBJ_DIR)\zipstring.obj\
   $(OBJ_DIR)\zipplatformcomm.obj\
   $(OBJ_DIR)\zippathcomponent.obj\
   $(OBJ_DIR)\zipmemfile.obj\
   $(OBJ_DIR)\zipfileheader.obj\
   $(OBJ_DIR)\zipfile.obj\
   $(OBJ_DIR)\zipnew.obj\
   $(OBJ_DIR)\zipcomp.obj\
   $(OBJ_DIR)\zipexception.obj\
   $(OBJ_DIR)\zipcompatibility.obj\
   $(OBJ_DIR)\zipcentraldir.obj\
   $(OBJ_DIR)\zipautobuffer.obj\
   $(OBJ_DIR)\stdafx.obj


# 旼컴컴컴컴�
# � project 넴
# 읕컴컴컴컴昴
#  賽賽賽賽賽�

all: \
   $(HARBOUR_DLL)

CLEAN:
   -@if exist $(HARBOUR_DLL) del $(HARBOUR_DLL) >nul
   -@if exist ..\..\lib\b32\hbziparchdll.tds del ..\..\lib\b32\hbziparchdll.tds >nul
   -@if exist ..\..\lib\b32\hbziparchdll.map del ..\..\lib\b32\hbziparchdll.map >nul
   -@if exist $(OBJ_DIR)\*.obj del $(OBJ_DIR)\*.obj >nul
   -@if exist $(OBJ_DIR)\*.c del $(OBJ_DIR)\*.c >nul
   -@if exist $(OBJ_DIR)\*.h del $(OBJ_DIR)\*.h >nul

# 旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커
# � Library dependencies and build rules 넴
# 읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸�
#  賽賽賽賽賽賽賽賽賽賽賽賽賽賽賽賽賽賽賽賽

$(HARBOUR_DLL)  : \
   $(HARBOUR_DLL_OBJS)

# 旼컴컴컴컴컴컴컴컴컴컴�
# � HARBOUR_DLL linking 넴
# 읕컴컴컴컴컴컴컴컴컴컴昴
#  賽賽賽賽賽賽賽賽賽賽賽�
  echo. $(OBJ_DIR)\ziparchive.obj        + > hdll.tmp
  echo. $(OBJ_DIR)\zip.obj               + >> hdll.tmp
  echo. $(OBJ_DIR)\zipplatform.obj       + >> hdll.tmp
  echo. $(OBJ_DIR)\zipstorage.obj        + >> hdll.tmp
  echo. $(OBJ_DIR)\zipstring.obj         + >> hdll.tmp
  echo. $(OBJ_DIR)\zipplatformcomm.obj   + >> hdll.tmp
  echo. $(OBJ_DIR)\zippathcomponent.obj  + >> hdll.tmp
  echo. $(OBJ_DIR)\zipmemfile.obj        + >> hdll.tmp
  echo. $(OBJ_DIR)\zipfileheader.obj     + >> hdll.tmp
  echo. $(OBJ_DIR)\zipfile.obj           + >> hdll.tmp
  echo. $(OBJ_DIR)\zipnew.obj            + >> hdll.tmp
  echo. $(OBJ_DIR)\zipcomp.obj           + >> hdll.tmp
  echo. $(OBJ_DIR)\zipexception.obj      + >> hdll.tmp
  echo. $(OBJ_DIR)\zipcompatibility.obj  + >> hdll.tmp
  echo. $(OBJ_DIR)\zipcentraldir.obj     + >> hdll.tmp
  echo. $(OBJ_DIR)\zipautobuffer.obj     + >> hdll.tmp
  echo. $(OBJ_DIR)\stdafx.obj            + >> hdll.tmp
  echo. c0d32w.obj,                      + >> hdll.tmp
  echo. $(HARBOUR_DLL),                  + >> hdll.tmp
  echo. ,                                + >> hdll.tmp
  echo. cw32.lib                         + >> hdll.tmp
  echo. ..\..\lib\harbour.lib            + >> hdll.tmp
  echo. import32.lib                     + >> hdll.tmp
  echo. uuid.lib                           >> hdll.tmp
  ILINK32 -aa -Tpd -Gn @hdll.tmp

# 旼컴컴컴컴컴컴컴컴컴컴커
# � object file creation 넴
# 읕컴컴컴컴컴컴컴컴컴컴켸�
#  賽賽賽賽賽賽賽賽賽賽賽賽

$(OBJ_DIR)\ziparchive.obj : $(COMMON_DIR)\ziparchive.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zip.obj : $(COMMON_DIR)\zip.c
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipplatform.obj : $(COMMON_DIR)\zipplatform.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipstorage.obj : $(COMMON_DIR)\zipstorage.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipstring.obj : $(COMMON_DIR)\zipstring.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipplatformcomm.obj : $(COMMON_DIR)\zipplatformcomm.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zippathcomponent.obj : $(COMMON_DIR)\zippathcomponent.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipmemfile.obj : $(COMMON_DIR)\zipmemfile.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipfileheader.obj : $(COMMON_DIR)\zipfileheader.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipfile.obj : $(COMMON_DIR)\zipfile.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipnew.obj : $(COMMON_DIR)\zipnew.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipcomp.obj : $(COMMON_DIR)\zipcomp.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipexception.obj : $(COMMON_DIR)\zipexception.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipcompatibility.obj : $(COMMON_DIR)\zipcompatibility.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipcentraldir.obj : $(COMMON_DIR)\zipcentraldir.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\zipautobuffer.obj : $(COMMON_DIR)\zipautobuffer.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**

$(OBJ_DIR)\stdafx.obj : $(COMMON_DIR)\stdafx.cpp
   $(CC) $(CLIBFLAGS) -o$@ $**
