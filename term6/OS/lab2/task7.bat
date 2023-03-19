@echo off
cls
set maxsize=0
setlocal enabledelayedexpansion
for /f "tokens=* delims=" %%a in ('dir /a-d/b/s "%~1"') do (
    if %%~za gtr !maxsize! (
        set "name=%%~nxa"
        set "maxsize=%%~za"
        set "create=%%~ta"
    )
)
echo File max size
echo. %name% ^| %maxsize% ^| %create%
echo.
set minsize=%maxsize%
for /f "tokens=* delims=" %%a in ('dir /a-d/b/s "%~1"') do (
    if %%~za lss !minsize! (
        set "name=%%~nxa"
        set "minsize=%%~za"
        set "create=%%~ta"
    )
)
echo File min size
echo. %name% ^| %minsize% ^| %create%
pause>nul
exit