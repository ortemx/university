@echo off
setlocal enabledelayedexpansion
set /p cat=ENTER PATH: 
set /a m=-1
for /r %cat% %%f in (.) do set /a m=m+1
echo count=%m%
tree %cat%