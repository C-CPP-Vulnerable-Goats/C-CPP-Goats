
rem NOTE: this batch file is to be run in a Visual Studio command prompt

rem Delete old files
del *.obj
del *.ilk
del *.exe
del *.pdb

rem Compile files into .obj files in current directory
cl /I"..\..\..\testcasesupport" /W3 /MT /GS /RTC1 /bigobj /EHsc /nologo /c main.cpp CWE*.cpp ..\..\..\testcasesupport\io.c ..\..\..\testcasesupport\std_thread.c
rem Link all .obj file into a exe
cl /FeCWE23_s05 *.obj /I"..\..\..\testcasesupport" /W3 /MT /GS /RTC1 /bigobj /EHsc /nologo
