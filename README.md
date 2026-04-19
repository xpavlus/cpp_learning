# cpp_learning

Репозиторий для изучения C++ — от основ до продвинутых тем.  
Ориентирован на **Windows (MSVC / Visual Studio 2022)**, но устроен так, чтобы без боли добавить Linux/WSL позже.

---

## Структура папок

```
cpp_learning/
├── .github/
│   └── workflows/
│       └── ci.yml          # CI: сборка на Windows (GitHub Actions)
├── docs/
│   └── 00-setup.md         # Руководство по настройке окружения
├── lessons/
│   └── 01_basics/
│       ├── notes.md        # Заметки по теме
│       └── src/
│           └── task01_hello.cpp
├── playground/
│   └── main.cpp            # Свободная зона для экспериментов
├── tools/
│   ├── build.ps1           # PowerShell-скрипт для сборки
│   └── format.ps1          # PowerShell-скрипт для форматирования кода
├── .clang-format           # Настройки форматирования
├── .gitignore
├── CMakeLists.txt          # Корневой CMake-файл
├── ROADMAP.md              # План тем
└── README.md
```

---

## Как собрать и запустить на Windows

### Вариант 1: Visual Studio 2022

1. Открой папку репозитория в Visual Studio 2022 (`File → Open → Folder…`).  
   Visual Studio автоматически обнаружит `CMakeLists.txt`.
2. Выбери конфигурацию **x64-Debug** или **x64-Release** в выпадающем списке.
3. `Build → Build All` (или `Ctrl+Shift+B`).
4. Найди исполняемые файлы в папке `out/build/<конфигурация>/`.

### Вариант 2: VS Code с расширением CMake Tools

1. Установи расширения **C/C++** и **CMake Tools** в VS Code.
2. Открой папку репозитория (`File → Open Folder…`).
3. При появлении запроса — выбери комплект (kit): `Visual Studio 2022 Release - amd64` (или аналогичный).
4. Нажми **Build** в строке состояния (или `Ctrl+Shift+P → CMake: Build`).
5. Исполняемые файлы окажутся в `build/` (или `out/build/`).

### Вариант 3: командная строка (Developer Command Prompt / PowerShell)

```powershell
# Конфигурация (генератор Visual Studio):
cmake -S . -B build -G "Visual Studio 18 2026" -A x64

# Сборка:
cmake --build build --config Debug

# Запуск playground:
.\build\Debug\playground.exe
```

Или использовать готовый скрипт:

```powershell
.\tools\build.ps1          # Debug по умолчанию
.\tools\build.ps1 Release  # Release
```

---

## Форматирование кода

```powershell
.\tools\format.ps1
```

Требует установленного `clang-format` в `PATH` (входит в состав LLVM или VS Build Tools).

---

## Позже добавим Linux / WSL

В планах — добавить CI-шаг для Ubuntu и описание сборки через GCC/Clang под WSL или нативный Linux.  
Флаги GCC/Clang уже зарезервированы в `CMakeLists.txt`.
