<#
.SYNOPSIS
    Конфигурирует и собирает C++ проект через CMake.

.PARAMETER Config
    Конфигурация сборки: Debug (по умолчанию) или Release.

.EXAMPLE
    .\tools\build.ps1           # собирает Debug
    .\tools\build.ps1 Release   # собирает Release
#>

param(
    [ValidateSet('Debug', 'Release', 'RelWithDebInfo', 'MinSizeRel')]
    [string]$Config = 'Debug'
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

# Проверка наличия cmake в PATH
if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Error "cmake не найден в PATH.`nУстановите CMake (https://cmake.org/) или запустите скрипт из Developer PowerShell for VS 2022."
    exit 1
}

$RepoRoot  = Split-Path -Parent $PSScriptRoot
$BuildDir  = Join-Path $RepoRoot 'build'

Write-Host "==> Конфигурация: $Config"
Write-Host "==> Папка сборки: $BuildDir"
Write-Host ""

# Шаг 1: Configure
Write-Host "--- CMake configure ---"
cmake -S $RepoRoot -B $BuildDir -G "Visual Studio 17 2022" -A x64
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

# Шаг 2: Build
Write-Host ""
Write-Host "--- CMake build ($Config) ---"
cmake --build $BuildDir --config $Config
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host ""
Write-Host "==> Сборка завершена успешно."
Write-Host "    Исполняемые файлы: $BuildDir\$Config\"
