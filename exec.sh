if [ $1 == 2 ]; then
    g++ -c libsvgc++.hpp libsvgc++.cpp
elif [ $1 == 1 ]; then
    g++ -o main Histogram.cpp Histogram.hpp libsvgc++.cpp libsvgc++.hpp main.cpp
else
    ./main < test1.txt > output.xml
fi
