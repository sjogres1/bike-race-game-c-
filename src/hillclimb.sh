#/bin/sh


cd Box2D_v2.1.2/Box2D/Build/
cmake ..
make -j 6
cd ..
cd ..
cd ..
make clean main -j 6
sleep 10;
./main
