cl /LD legacy_stdio_definitions.lib user32.lib Gdi32.lib ControlTyporaView.c
del *.obj
del *.exp
del *.lib

mv  ControlTyporaView.dll ControlTyporaView.x86.dll
rem::mv  ControlTyporaView.dll ControlTyporaView.x64.dll
