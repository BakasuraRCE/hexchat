include "..\makeinc.mak"

!ifdef X64
MACHINE_FLAG = /MACHINE:X64
!else
MACHINE_FLAG = /MACHINE:X86
!endif

COMLIB = ..\common\xchatcommon.lib
PROG = xchat.exe

all: $(PROG)

mmx_cmod.o: mmx_cmod.S
	gcc -DUNDERSCORE_SYMBOLS -c mmx_cmod.S

.c.obj:
	$(CC) $(CFLAGS) -I..\..\plugins $(GLIB) $(GTK) $(SPELL) $<

$(PROG): $(FEGTK_OBJECTS) $(COMLIB) xchat-icon.obj
	$(LINK) /out:$(PROG) /entry:mainCRTStartup $(LDFLAGS) $(LIBS) $(FEGTK_OBJECTS) $(COMLIB) xchat-icon.obj

xchat.rc:
	echo XC_ICON ICON "../../xchat.ico" > xchat.rc

xchat.res: xchat.rc ../../xchat.ico
	rc /r xchat.rc

xchat-icon.obj: xchat.res
	cvtres /nologo $(MACHINE_FLAG) /OUT:xchat-icon.obj xchat.res

clean:
	del *.obj
	del fe-gtk\mmx_cmod.o
	del $(PROG)
	del xchat.rc
	del xchat.RES
