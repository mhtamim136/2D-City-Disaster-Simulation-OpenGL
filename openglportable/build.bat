@echo off
cd /d "%~dp0"

g++ main.cpp -I"..\freeglut\include" -L"..\freeglut\lib\x64" -lfreeglut -lopengl32 -lglu32 -o "bin\Debug\openglportable.exe"

cd bin\Debug
openglportable.exe

pause
