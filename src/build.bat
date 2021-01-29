@echo off
if not exist "..\build" mkdir ..\build
pushd ..\build
cl ..\src\main.c user32.lib
popd
