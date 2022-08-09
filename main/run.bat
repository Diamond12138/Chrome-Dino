@echo off

echo ----------Input File----------

set /p input=
echo %input%.exe

echo ----------Compling----------
g++ -finput-charset=gbk -fexec-charset=gbk %input%.cpp -o %input%.exe -lgdi32 -lfreeglut -lopengl32 -lglew32 -lfreetype -lz
echo ----------Running----------
%input%.exe

echo ----------End----------
pause