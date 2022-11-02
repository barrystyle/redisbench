if [ ! redis-cpp/lib/libredis-cpp.a ];
then
   git submodule init
   git submodule update

   cd redis-cpp
   mkdir -p build
   cd build
   cmake ..
   make clean
   make -j2
   cd ..
fi


g++ -O3 -std=c++17 -I./ -I./redis-cpp -I./redis-cpp/include util.cpp tester.cpp redis-cpp/lib/libredis-cpp.a -o tester
