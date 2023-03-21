@echo off
SETLOCAL ENABLEDELAYEDEXPANSION
set /a n=%1
if %1 lss 0 goto:TooSmallError
if %1 gtr 12 goto:TooLargeError
set /a res=1
for /L %%f in (1,1,%n%) do set /a res=res*%%f
echo %1^^! = %res%
endlocal
goto:eof
:TooSmallError
echo The entered number is less than 0
goto:eof
:TooLargeError
echo The entered number is greater than 12
