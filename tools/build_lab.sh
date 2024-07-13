MODE="$1"

if [ "$MODE" == "debug" ];
then

    cmake -DCMAKE_BUILD_TYPE=Debug .. -DCMAKE_C_FLAGS="-g" -DCMAKE_CXX_FLAGS="-g"
    cmake --build . --config Debug --parallel 8

else
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build . --config Release --parallel 8
fi


cmake --build . --target validateLab
cmake --build . --target benchmarkLab

