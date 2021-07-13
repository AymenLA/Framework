# sdl2 cmake project-config input for ./configure scripts

set(prefix "/usr") 
set(exec_prefix "${prefix}")
set(libdir "${prefix}/lib/x86_64-linux-gnu")
set(SDL2_PREFIX "/usr")
set(SDL2_EXEC_PREFIX "/usr")
set(SDL2TTF_INCLUDE_DIRS "${prefix}/include/SDL2")
set(SDL2TTF_LIBRARIES " -lSDL2_ttf")
string(STRIP "${SDL2TTF_LIBRARIES}" SDL2TTF_LIBRARIES)