set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
cmake_minimum_required(VERSION 2.8)
SET(LIBHELLO_SRC Hello.cpp)
# 添加动态库，关键词为shared，不需要写全libhello.so，
ADD_LIBRARY (hello SHARED ${LIBHELLO_SRC})
# 添加静态库，关键词为static，不需要写全libhello_static.a
# target不能重名，因此静态库的target不同与动态库的target重名，修改为hello_static
ADD_LIBRARY (hello_static STATIC ${LIBHELLO_SRC})
# 通常，静态库名字跟动态库名字是一致的，只是扩展名不同；
# 即：静态库名为 libhello.a； 动态库名为libhello.so；
# 因此，希望"hello_static"在输出时，以"hello"的名字显示
SET_TARGET_PROPERTIES (hello_static PROPERTIES OUTPUT_NAME "hello")
GET_TARGET_PROPERTY (OUTPUT_VALUE hello_static OUTPUT_NAME)
MESSAGE (STATUS "This is the hello_static OUTPUT_NAME: " ${OUTPUT_VALUE})
# cmake在构建一个新的target时，会尝试清理掉其它使用target名字的库，
# 因此，在构建libhello.a时，就会清理掉libhello.so.
# 为了避免清理问题，比如再次使用SET_TARGET_PROPERTIES定义 CLEAN_DIRECT_OUTPUT属性。
SET_TARGET_PROPERTIES (hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES (hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set(BUILD_SHARED_LIBS shared)
message(STATUS ${BUILD_SHARED_LIBS})
#通常，动态库包含一个版本号，VERSION指代动态库版本，SOVERSION指代API版本。
SET_TARGET_PROPERTIES (hello PROPERTIES VERSION 1.2 SOVERSION 1)

#构建完成后需要将libhello.a, libhello.so.x以及hello.h安装到系统目录，
# 将hello的共享库安装到<prefix>/lib目录；
# 将hello.h安装<prefix>/include/hello目录。
INSTALL (TARGETS hello hello_static LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib)
INSTALL (FILES Hello.h DESTINATION include/hello)
