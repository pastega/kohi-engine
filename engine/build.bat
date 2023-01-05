rem Build Script for the Engine
@echo off
setlocal enableDelayedExpansion

rem Get a list of all .c files
for /r %%f in (*.c) do (
  set cFilenames=!cFilenames! %%f
)

rem echo "Files:" %cFilenames%

set assembly=engine

set compilerFlags=-g -shared -Wvarargs -Wall -Werror

set includeFlags=-Isrc -I%VULKAN_SDK%/Include

set linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib

set defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS

ECHO "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%