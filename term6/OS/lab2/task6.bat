@echo off

md "%~1\exe" "%~1\doc" "%~1\cmd" "%~1\txt" "%~1\other"

for %%f in (%~1\Files\*.*) do (
	if "%%~xf"==".exe" (
		copy %%f "%~1\exe"
	) else if "%%~xf"==".doc" (
		copy %%f "%~1\doc"
	) else if "%%~xf"==".cmd" (
		copy %%f "%~1\cmd"
	) else if "%%~xf"==".txt" (
		copy %%f "%~1\txt"
	) else copy %%f "%~1\other"	
)
 
FOR /F delims^= %%A IN ('DIR/AD/B/S^|SORT/R') DO RD "%%A"
cls
dir %1