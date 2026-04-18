<#
.SYNOPSIS
    Форматирует все *.cpp / *.h / *.hpp файлы проекта с помощью clang-format.

.DESCRIPTION
    Обходит папки: playground/, lessons/, src/, include/ (если существуют)
    и применяет clang-format -i к каждому найденному файлу.

.EXAMPLE
    .\tools\format.ps1
#>

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

# Проверка наличия clang-format в PATH
if (-not (Get-Command clang-format -ErrorAction SilentlyContinue)) {
    Write-Error "clang-format не найден в PATH.`nУстановите LLVM (https://releases.llvm.org/) или включите компонент Clang в Visual Studio Installer."
    exit 1
}

# Папки для форматирования (относительно корня репозитория)
$RepoRoot = Split-Path -Parent $PSScriptRoot
$Folders = @('playground', 'lessons', 'src', 'include') | ForEach-Object {
    Join-Path $RepoRoot $_
} | Where-Object { Test-Path $_ }

if ($Folders.Count -eq 0) {
    Write-Warning "Не найдено ни одной папки для форматирования."
    exit 0
}

$Extensions = @('*.cpp', '*.h', '*.hpp')
$FileCount = 0

foreach ($Folder in $Folders) {
    foreach ($Ext in $Extensions) {
        $Files = Get-ChildItem -Path $Folder -Recurse -Filter $Ext -File
        foreach ($File in $Files) {
            Write-Host "  Форматирую: $($File.FullName)"
            clang-format -i $File.FullName
            $FileCount++
        }
    }
}

Write-Host "`nГотово. Отформатировано файлов: $FileCount"
