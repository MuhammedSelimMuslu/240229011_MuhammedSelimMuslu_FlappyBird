cmake_minimum_required(VERSION 3.10)
project(FlappyBirdClone)

# C++17 standardını zorunlu tut
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Mac (Homebrew) için kütüphane yollarını doğrudan derleyiciye veriyoruz
include_directories("/opt/homebrew/include")
link_directories("/opt/homebrew/lib")

# Çalıştırılabilir dosyamızı oluştur
add_executable(FlappyBirdClone main.cpp)

# Kütüphaneleri bağla (Fiziksel dosya isimleri küçük harflidir)
target_link_libraries(FlappyBirdClone sfml-graphics sfml-window sfml-system)