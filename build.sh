git submodule init
git submodule update

cd redis-cpp
mkdir -p build
cd build
cmake ..
make clean
make -j2
cd ..
