$OutputEncoding = [System.Text.Encoding]::UTF8
$repoPath = 'D:\GH\university\term3\VS\lab 2\WindowsFormsApplication1 - ркопия без обработчиков'
$pathUtf8 = $repoPath | ConvertTo-UTF8String
# Переходим в каталог репозитория
Set-Location $pathUtf8

# Получаем список всех файлов в репозитории
$files = Get-ChildItem -Recurse

# # Проходимся по каждому файлу
# foreach ($file in $files) {
#     # Проверяем, является ли файл неотслеживаемым
#     if ($null -ne (git ls-files --error-unmatch $file.FullName)) {
#         # Если файл неотслеживаемый, то удаляем его
#         Remove-Item $file.FullName
#         Write-Host "Файл $($file.FullName) был удален."
#     }
# }

# Write-Host 'Все неотслеживаемые файлы были удалены.'