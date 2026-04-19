# 00 — Настройка окружения (Windows)

## Требования

| Инструмент | Минимальная версия | Где взять |
|---|---|---|
| Visual Studio 2022 или Build Tools | 17.x | [visualstudio.microsoft.com](https://visualstudio.microsoft.com/) |
| CMake | 3.20+ | [cmake.org](https://cmake.org/download/) или через VS Installer |
| Git | любая свежая | [git-scm.com](https://git-scm.com/) |
| VS Code *(опционально)* | любая | [code.visualstudio.com](https://code.visualstudio.com/) |
| Ninja *(опционально)* | 1.10+ | [ninja-build.org](https://ninja-build.org/) или `winget install Ninja-build.Ninja` |

---

## Шаг 1 — Visual Studio 2022 / Build Tools

1. Запусти **Visual Studio Installer**.
2. В разделе **Workloads** выбери:  
   **Desktop development with C++** (включает MSVC, CMake, Clang, Windows SDK).
3. Убедись, что компонент **C++ CMake tools for Windows** включён (он входит в workload по умолчанию).
4. При желании добавь компонент **Clang** для использования `clang-format`.

> **Build Tools** (без IDE) — это облегчённый вариант для сборки из командной строки.  
> Устанавливается отдельно: на сайте VS выбери «Tools for Visual Studio → Build Tools for Visual Studio 2022».

---

## Шаг 2 — CMake

CMake **уже входит** в состав VS workload «Desktop development with C++» и доступен в Developer Command Prompt/PowerShell.

Если нужна отдельная установка:
```powershell
winget install Kitware.CMake
```

Проверь версию:
```powershell
cmake --version
```

---

## Шаг 3 — Выбор генератора CMake

### Visual Studio generator (рекомендуется для начала)

```powershell
cmake -S . -B build -G "Visual Studio 18 2026" -A x64
cmake --build build --config Debug
```

Плюсы: не требует дополнительных инструментов, открывает `.sln` в IDE.

### Ninja generator (быстрее, хорошо с VS Code)

```powershell
# Запускать из "Developer PowerShell for VS 2022" (чтобы компилятор был в PATH)
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Установка Ninja:
```powershell
winget install Ninja-build.Ninja
```

---

## Шаг 4 — VS Code (опционально)

1. Установи расширения:
   - **C/C++** (Microsoft)
   - **CMake Tools** (Microsoft)
2. Открой папку репозитория.
3. При запросе комплекта (kit) выбери `Visual Studio 2022 Release - amd64`.
4. Используй кнопку **Build** в строке состояния или `Ctrl+Shift+P → CMake: Build`.

---

## Шаг 5 — Проверка сборки

```powershell
# из корня репозитория
.\tools\build.ps1        # → собирает Debug в папку build/

# или вручную:
cmake -S . -B build -G "Visual Studio 18 2026" -A x64
cmake --build build --config Debug

# запуск:
.\build\Debug\playground.exe
```

---

## WSL / Linux — будет добавлено позже

В будущем добавим:
- Установку GCC/Clang под WSL 2 (Ubuntu).
- Отдельный CI-шаг для Linux.
- Возможность переключаться между MSVC и GCC/Clang через CMake Presets.
