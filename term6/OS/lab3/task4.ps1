# Get-ChildItem -Path "C:\Windows" -Directory | Where-Object {$_.Name -match "[st]$"} | Sort-Object -Property Name | Select-Object -Property Name
# # рабочий, но не показывает размеры
# Get-ChildItem -Path "C:\Windows" -Directory | Where-Object {$_.Name -match "[st]$"} | Sort-Object -Property Name | Select-Object -Property Name, @{Name="Size";Expression={$.Length}}, CreationTime, Attributes
# Get-ChildItem -Path "C:\Windows" -Directory | Where-Object {$_.Name -match "[st]$"} | Sort-Object -Property Name | Select-Object -Property Name, @{Name="Size";Expression={$.Length}}, CreationTime, Attributes | Format-Table 


# рабочий, специально не показывает размер каталгов
Get-ChildItem -Path "C:\Windows" -Directory | Where-Object {$_.Name -match "[st]$"} | Sort-Object Name | Select-Object  Name, CreationTime, Attributes | Format-Table | Out-File "task4_output.txt"
