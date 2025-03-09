mkdir -Force build
cmake -S . -B build
cmake --build build
build\MyProject.exe