@echo off

echo ----------Input File----------

set /p input=
echo %input%.exe

echo ----------Compling----------
g++ -finput-charset=UTF-8 -fexec-charset=UTF-8 %input%.cpp -o %input%.exe -lgdi32 -lfreeglut -lopengl32 -lglew32 -lfreetype -lz
echo ----------Running----------
%input%.exe

echo ----------End----------
pause