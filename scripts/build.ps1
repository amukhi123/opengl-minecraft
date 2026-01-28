param(
    [string]$Action
)

cd ..

if ($Action -eq "clean") {
    if (Test-Path "build\") {
        rm -r -Force build
    }   
    mkdir build
	cd scripts\
}

if ($Action -eq "gensln") {
    if (-not (Test-Path "build\")) {
        mkdir build\
    }
    cd build\
    cmake -G "Visual Studio 18 2026" .. -DCMAKE_BUILD_TYPE=Debug
    cd ..\scripts
}

if ($Action -eq "opensln") {
    cd build\
    ./opengl_minecraft.slnx
    cd ../scripts
}

if ($Action -eq "build") {
    if (-not (Test-Path "build\")) {
        mkdir build
    }
    cd build
    cmake -G "Ninja" .. -DCMAKE_BUILD_TYPE=Debug
    ninja
    cd ..\scripts\
}

if ($Action -eq "run") {
    cd build/
    ./opengl_minecraft.exe
    cd ..\scripts\
}
