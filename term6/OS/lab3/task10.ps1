# [Console]::outputEncoding = [System.Text.Encoding]::GetEncoding('utf-8')
# [Console]::outputEncoding
chcp 65001
$c = New-Object System.Collections.ArrayList
for ($i = 1; $i -le 10; $i++) {
    $c.Add((Measure-Command { Get-ChildItem }).TotalMilliseconds) > $null
}
Write-Output "results for command dir: "
$c | Measure-Object -Maximum -Minimum -Average

$c = New-Object System.Collections.ArrayList
for ($i = 1; $i -le 10; $i++) {
    $c.Add((Measure-Command { Get-Process }).TotalMilliseconds) > $null
}
Write-Output "results for command ps: "
$c | Measure-Object -Maximum -Minimum -Average
