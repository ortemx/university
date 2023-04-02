Get-ChildItem | Group-Object Length | Where-Object { $_.Count -gt 1 } | ForEach-Object { $_.Group | Select-Object -ExpandProperty Name }
# Get-ChildItem | Group-Object Length | Where-Object Count -ne 1 | ForEach-Object {
#     Write-Host "Файлы с размером $($_.Name):"
#     $_.Group.FullName
# }