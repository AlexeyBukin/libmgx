cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(liner.app)

# find src     -type f -name '*.c' | sed 'N;N;s/\n/ /g' |  sed '$s/\\\\\\//' | column -t
set(${PROJECT_NAME}_SOURCES
        src/buf/mgx_buf_draw_line.c
        src/buf/mgx_buf.c
        src/demo/liner.c
        src/mgx_free.c
        src/mgx_init.c
        src/mgx_loop.c
        src/mgx_lib_mlx.c
        src/win/mgx_win_buf.c
        src/win/mgx_win_init.c
        src/win/mgx_win_draw.c
        )

add_executable(${PROJECT_NAME}  ${${PROJECT_NAME}_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        ${SDL2_INCLUDE_DIR}                      )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include            )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/lib/libft/include      )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/lib/libmlx      )

add_subdirectory(./lib/libft)
target_link_libraries(${PROJECT_NAME} ft)
target_link_libraries(${PROJECT_NAME} m)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/libmlx/libmlx.a)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} )
target_link_libraries(${PROJECT_NAME} "-framework AppKit")