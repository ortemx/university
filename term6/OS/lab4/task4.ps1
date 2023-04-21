# # Получить список имен счетчиков для каждого ядра процессора
# $counterNames = @()
# $processor = Get-WmiObject Win32_Processor
# $cores = $processor.NumberOfCores
# for ($i = 0; $i -lt $cores; $i++) {
#     $counterNames += "\Processor($i)\% User Time", "\Processor($i)\% Privileged Time"
# }

# # Получить информацию о времени, затраченном каждым ядром процессора на выполнение пользовательских и системных задач
# $load = Get-Counter -Counter $counterNames -ErrorAction Stop

# # Вывести информацию о времени, затраченном каждым ядром процессора на выполнение пользовательских и системных задач
# for ($i = 0; $i -lt $cores; $i++) {
#     $userTime = $load.CounterSamples[2*$i].CookedValue
#     $sysTime = $load.CounterSamples[2*$i+1].CookedValue
#     $totalTime = $userTime + $sysTime
#     $userPercent = $userTime / $totalTime * 100
#     $sysPercent = $sysTime / $totalTime * 100
#     Write-Host "Core $($i): User $($userPercent)% System $($sysPercent)%"
# }

Start-Service -Name "Performance Counter"
