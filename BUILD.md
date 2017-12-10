# Сборка проекта
## Подготовка
После начала склонируйте репо:
```
git clone https://github.com/alekseik1/cpp_mipt_study
```
Затем инициализируйте подмодули:
```
git submodule init
git submodule update
```
## Работа с IDE
После подготовки папку **3sem** можно открыть в Clion
(или любой другой IDE, умеющей работать с системой _CMake_).
Чтобы собрать проект, достаточно воспользоваться предолженными целями в IDE.
## Ручная сборка
Если IDE не удалось определить файлы или же вы хотите собрать все руками, выполните следующее:
```
cd 3sem/
mkdir build
cd build/
cmake ..
make
```
Собранные файлы будут лежат в папке **build/contests**.
Для сборки отдельной программы можно указать цель:
```
cd 3sem/
mkdir build
cd build/
cmake ..
make 7-A
```
где **7** - номер недели, **A** - буква задания.