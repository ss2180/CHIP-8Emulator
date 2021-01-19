@echo off
if not exist "..\build" mkdir ..\build
pushd ..\build
cl ..\src\main.c ..\src\disassembler.c
popd
