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
        src/CharOperations.c
        src/DataAnalysis.c
        include/DataAnalysis.h
        include/PlotData.h
        include/CharOperations.h
        include/ResultManagement.h
        include/SortingOperations.h
        include/SortingAlgorithms.h
        include/FileOperations.h
        include/Swap.h
        pbPlot/pbPlots.c
        pbPlot/supportLib.c
        pbPlot/supportLib.h
        pbPlot/pbPlots.h
)
