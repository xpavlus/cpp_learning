# Урок 06 — Templates (Шаблоны)

## Что такое шаблоны

Шаблоны — механизм **статического полиморфизма** в C++. Компилятор генерирует код на этапе компиляции для каждого конкретного типа, с которым используется шаблон. Это называется **инстанцирование** (instantiation).

Ключевое отличие от динамического полиморфизма (virtual): нет накладных расходов в рантайме, но увеличивается размер бинарника (code bloat).

---

## Шаблоны функций

```cpp
template <typename T>
T max_val(T a, T b) {
    return (a > b) ? a : b;
}

max_val(3, 5);       // T = int   — явная дедукция
max_val(3.0, 5.0);   // T = double
max_val<int>(3, 5);  // T = int   — явное указание типа
```

### Вывод типа (Template Argument Deduction)

Компилятор выводит `T` из аргументов. Если типы не совпадают — ошибка компиляции:
```cpp
max_val(3, 5.0);  // ошибка: T не может быть int и double одновременно
max_val<double>(3, 5.0);  // явно: преобразует 3 → double
```

### Несколько параметров типа

```cpp
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
// C++14: auto add(T a, U b) { return a + b; }
```

### Нетиповые параметры (Non-type parameters)

```cpp
template <int N>
void print_n_times(const std::string& s) {
    for (int i = 0; i < N; ++i) std::cout << s << '\n';
}

print_n_times<3>("hello");  // N = 3, вычислено на этапе компиляции
```

---

## Шаблоны классов

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(const T& val) { data.push_back(val); }
    void pop()              { data.pop_back(); }
    T&   top()              { return data.back(); }
    bool empty() const      { return data.empty(); }
    std::size_t size() const { return data.size(); }
};

Stack<int>         int_stack;
Stack<std::string> str_stack;
```

### Методы шаблонного класса вне тела класса

```cpp
template <typename T>
class Box {
public:
    Box(T val);
    T get() const;
private:
    T value;
};

template <typename T>
Box<T>::Box(T val) : value(val) {}

template <typename T>
T Box<T>::get() const { return value; }
```

**Важно:** определение шаблона должно быть видно в точке инстанцирования — то есть, как правило, шаблоны целиком пишутся в заголовочных файлах (`.h` / `.hpp`). Вынести реализацию в `.cpp` можно только с явным инстанцированием.

---

## Специализация шаблонов

### Полная специализация (explicit / full specialization)

```cpp
template <typename T>
std::string type_name() { return "unknown"; }

template <>
std::string type_name<int>() { return "int"; }

template <>
std::string type_name<double>() { return "double"; }
```

### Частичная специализация (partial specialization) — только для классов

```cpp
template <typename T>
class Wrapper { /* общий случай */ };

template <typename T>
class Wrapper<T*> { /* специализация для указателей */ };

template <typename T, typename U>
class Pair { /* общий случай */ };

template <typename T>
class Pair<T, T> { /* оба типа одинаковы */ };
```

Частичная специализация функций напрямую не поддерживается — используют перегрузку или `if constexpr`.

---

## `if constexpr` (C++17)

Позволяет писать ветвления, которые вычисляются на этапе компиляции, без специализаций:

```cpp
template <typename T>
void print_info(T val) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "integral: " << val << '\n';
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "float: " << val << '\n';
    } else {
        std::cout << "other\n";
    }
}
```

Неактивная ветка не компилируется вообще — это принципиально отличается от обычного `if`.

---

## Type traits (`<type_traits>`)

Позволяют интроспектировать типы на этапе компиляции:

```cpp
std::is_integral<T>::value   // true для int, char, bool, ...
std::is_integral_v<T>        // C++17 shortcut

std::is_same_v<int, int>     // true
std::is_same_v<int, double>  // false

std::is_pointer_v<T*>        // true
std::is_base_of_v<Base, Derived>  // true если Derived наследует Base

std::remove_const_t<const int>  // int
std::remove_reference_t<int&>   // int
```

---

## SFINAE (Substitution Failure Is Not An Error)

При выводе аргументов шаблона неудачная подстановка типа не является ошибкой компиляции — шаблон просто исключается из кандидатов.

```cpp
// Только для арифметических типов
template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T>
square(T x) { return x * x; }

square(5);    // ok
square("hi"); // ошибка: нет подходящей перегрузки
```

В C++20 это заменяется **концептами** (`requires`/`concept`) — более читаемый синтаксис.

---

## Variadic templates (C++11)

Шаблон с произвольным числом аргументов:

```cpp
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n';  // fold expression (C++17)
}

print(1, " hello ", 3.14);  // "1 hello 3.14"
```

`sizeof...(Args)` — количество аргументов пакета.

---

## Подводные камни

- **Сообщения об ошибках** при шаблонах могут быть огромными и нечитаемыми — особенно до C++20.
- **Code bloat**: каждая инстанция — отдельный код. `std::vector<int>` и `std::vector<double>` — разные классы.
- Шаблонный код **не компилируется до инстанцирования** — ошибки в теле шаблона проявляются позже.
- `typename` vs `class` в параметрах — полностью взаимозаменяемы для типовых параметров. `typename` обязателен для зависимых имён типов: `typename T::value_type`.

---

## Задания

- [task01_templates.cpp](src/task01_templates.cpp) — шаблоны функций, шаблон класса, специализация
