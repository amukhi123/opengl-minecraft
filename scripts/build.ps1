param(
    [string]$Action
)

cd ..

if ($Action -eq "clean") {
    if (Test-Path "build\") {
        rm -r -Force build
    }   
    mkdir build
}

cd build
    
if ($Action -eq "build") {
    cmake -G Ninja .. -DCMAKE_BUILD_TYPE=Debug
    ninja
}

./opengl_minecraft.exe
cd ..\scripts\
