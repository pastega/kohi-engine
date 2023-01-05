rem Build Script for testbed
@echo off
setlocal enableDelayedExpansion

rem Get a list of all .c files
for /r %%f in (*.c) do (
  set cFilenames=!cFilenames! %%f
)

set assembly=testbed

set compilerFlags=-g

set includeFlags=-Isrc -I../engine/src

set linkerFlags=-L../bin/ -lengine.lib

set defines=-D_DEBUG -DKIMPORT

echo "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%
