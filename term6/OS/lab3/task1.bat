@echo off
setlocal EnableDelayedExpansion
set "folder=C:\Windows"

for /f "tokens=*" %%a in ('dir /b /ad /on "%folder%"') do (
    set "filename=%%a"
    if /i "!filename:~-1!"=="t" (
        echo !filename!
    ) else if /i "!filename:~-1!"=="s" (
        echo !filename!
    )
)