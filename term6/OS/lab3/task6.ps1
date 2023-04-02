# Get-Process | where {$_.CPU -gt 5}| select Id, name, WorkingSet, CPU | sort Id | Out-File "task6_output.txt"
# 
# Get-Process | where {$_.Id -gt 100} | select Name, Id, PriorityClass, UserProcessorTime, TotalProcessorTime | sort TotalProcessorTime | Out-File "task06_output.txt"

Get-Process | Where-Object {$_.Id -gt 100} | Select-Object Name, PriorityClass, ProductVersion, Id | Sort-Object Name | Out-File "task6_output.txt"