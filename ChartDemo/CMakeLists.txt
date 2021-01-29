cmake_minimum_required(VERSION 2.8)

project(ChartDemo)

aux_source_directory(ChartWidget SRC)
aux_source_directory(Model SRC)
aux_source_directory(DataSource SRC)


set(QT Core Gui Widgets Charts)

find_package(Qt5 REQUIRED ${QT})

add_executable(ChartDemo ${SRC})


