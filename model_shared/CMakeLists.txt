# CMakeList.txt: projeto de CMake para model_shared, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.

option(BUILD_STATIC_LIBS "Build the current lib as static" OFF)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE MODEL_SHARED_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./include/*.hpp")
file(GLOB_RECURSE MODEL_SHARED_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./lib/*.cpp")

set(LIB_FORMAT)

if(BUILD_STATIC_LIBS)
	set(LIB_FORMAT STATIC)
else()
	set(LIB_FORMAT SHARED)
endif()

add_library (model_shared ${LIB_FORMAT} ${MODEL_SHARED_HDRS} ${MODEL_SHARED_SRCS})
target_include_directories(model_shared PRIVATE "./include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET model_shared PROPERTY CXX_STANDARD 20)
endif()

install(TARGETS model_shared
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/myproject)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}./include DESTINATION ./include)

# TODO: Adicione testes e instale destinos, se necessário.
