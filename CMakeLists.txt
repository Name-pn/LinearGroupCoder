cmake_minimum_required(VERSION 3.23)
project(netKursov2 C)

set(CMAKE_C_STANDARD 23)

add_executable(netKursov2 main.c libs/message/message.c libs/test/testMessage.c libs/matrix/matrix.c libs/matrix/matrix.h libs/linGroupCode/linGroupCode.c libs/menu/menu.c libs/menu/menu.h)
