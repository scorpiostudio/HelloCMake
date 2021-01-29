# CMake版本约束
cmake_minimum_required(VERSION 2.8.3)
#工程名称
project(CMakeDemo)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")
set(CMAKE_BUILD_TYPE "Debug")
# 增加子目录ChartWidget的源码到变量SOURCES
aux_source_directory(ChartWidget SOURCES)
# 增加子目录Model的源码到变量SOURCES
aux_source_directory(Model SOURCES)
# 设置QT安装路径
set(CMAKE_PREFIX_PATH "/usr/local/Trolltech/Qt5.10.1/5.10.1/gcc_64")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# 开启Qt MOC
set(CMAKE_AUTOMOC ON)
#开启Qt ROC
set(CMAKE_AUTORCC ON)
# 开启Qt UIC
set(CMAKE_AUTOUIC ON)
set(QT Core Gui Widgets Charts)
# 查找Qt库
find_package(Qt5 REQUIRED ${QT})
if(Qt5_FOUND)
    include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS}
        ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Charts_INCLUDE_DIRS})
    set(QT_LIBRARIES ${Qt5Widgets_LIBRARIES} ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5Charts_LIBRARIES})
    # 增加可执行文件
    add_executable(${PROJECT_NAME} ${SOURCES} main.cpp MainWindow.cpp)
    target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
endif(Qt5_FOUND)


