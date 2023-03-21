@echo off
for %%i in (%1\*) do if exist "%2\%%~ni.*" echo fileName: %%~ni
tree %1 /f 
tree %2 /f