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
    
if ($Action -eq "clean") {
    cmake -G Ninja ..
}

ninja
./opengl_minecraft.exe
cd ..\scripts\
