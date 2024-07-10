@echo off
set /A mode = %1

if %mode% == 0 (
    echo "Building programm..."
    g++ Histogram.cpp Histogram.hpp libsvgc++.cpp libsvgc++.hpp main.cpp -o main.exe
    echo "Done."
)
echo "Running main.exe"
main.exe < input.txt > output.xml 2>NUL