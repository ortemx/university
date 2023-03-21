@echo off
for %%f in (%1\*.%2) do echo %%~nxf

dir %1