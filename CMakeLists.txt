cmake_minimum_required(VERSION 3.27)
project(question3 C)

set(CMAKE_C_STANDARD 11)

add_executable(question3 main.c
        src/SortingAlgorithms.c
        src/FileOperations.c
        src/SortingOperations.c
        src/ResultManagement.c
        src/Swap.c
        src/PlotData.c
        include/PlotData.h
        pbPlot/pbPlots.c
        pbPlot/supportLib.c
        src/CharOperations.c
        include/CharOperations.h
        src/DataAnalysis.c
        include/DataAnalysis.h
)
