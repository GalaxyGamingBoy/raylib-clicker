mkdir -Force build/res
cp -Force res/* build/res
cp -Force res/sounds/* build/res/sounds
cp -Force res/textures/* build/res/textures
rm ./build/raylib-clicker.exe

if ((Get-Content -Path CMakeLists.md5) -eq (Get-FileHash -Path CMakeLists.txt -Algorithm MD5).hash) {
    echo 'CMakeLists.txt has not changed. Ignoring Rebuild...'
} else {
    cmake -G "MinGW Makefiles" -B build .
}

(Get-FileHash -Path CMakeLists.txt -Algorithm MD5).hash > CMakeLists.md5

cd build
make
cd ..
./build/raylib-clicker.exe