# Get-ChildItem -Path "C:\windows" -Include "*.jpg", "*.bmp" -Recurse | Measure-Object -property length –sum
# Get-ChildItem -Path "C:\Windows" -Recurse -Include ".bmp",".jpg" | Measure-Object -Property Length -Sum | Select-Object -ExpandProperty Sum
# Get-ChildItem -Path "C:\" -Include "*.jpg", "*.bmp" -Recurse | Measure-Object -property length –sum

Get-ChildItem -Path "C:\Windows" -Include "*.jpg", "*.bmp" -Recurse | Measure-Object -property length –sum