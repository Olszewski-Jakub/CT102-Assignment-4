<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6295/6295417.png" width="100" />
</p>
<p align="center">
    <h1 align="center">SORTING-ALGORITHMS-PERFORMANCE-ANALYSIS</h1>
</p>
<p align="center">
    <em>HTTP error 401 for prompt `slogan`</em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis?style=flat&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<em>Developed with the software and tools below.</em>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=flat&logo=C&logoColor=black" alt="C">
</p>
<hr>

## Quick Links

> - [Overview](#overview)
> - [Gathering Data](#gathering-data)
>   - [Requirements](#requirements)
>   - [Data Gathering Process](#data-gathering-process)
> - [ Modules](#modules)
> - [ Documentation](#documentation)
>   - [ Functions](#functions)
>   - [ Sorting Algorithms](#sorting-algorithms)
>   - [ Adding Sorting Algorithms](#adding-and-removing-sorting-algorithms)
>     - [ Removing a Sorting Algorithm](#removing-a-sorting-algorithm)
>     - [ Adding a Sorting Algorithm](#adding-a-sorting-algorithm)
> - [ Getting Started](#getting-started)
>   - [ Installation](#installation)
>   - [ Running Sorting-Algorithms-Performance-Analysis](#running-Sorting-Algorithms-Performance-Analysis)
> - [ Performance Analysis](#performance-analysis)
>   - [ Average Time vs Algorithms](#average-time-vs-algorithms)
>   - [ Average Comparisons vs Algorithms](#average-comparisons-vs-algorithms)
>   - [ Average Swaps vs Algorithms](#average-swaps-vs-algorithms)
> - [ Contact Information](#contact-information)


---

## Overview

This project is a comprehensive study of various sorting algorithms implemented in C. The project reads data from
specific files, applies these sorting algorithms. The project also measures the time taken by each sorting algorithm to
sort the data. The project is implemented in C and uses the time.h library to measure the time taken by each sorting
algorithm and also counts swaps, comparisons, function calls and than writes this data in organised way into .csv file.

The project is structured around several key files and functions, including main.c, SortingOperations.h,
SortingAlgorithms.h, and SortingResult.h. Each of these plays a crucial role in the execution of the sorting operations
and the recording of their results.

The main.c file is where the program execution begins. It includes the main() function and the processFile() function.
The processFile() function reads numbers from an input file, sorts them using different sorting algorithms, and writes
the results to a result file.

The sorting functions are defined in the SortingAlgorithms.h file, and the operations related to sorting and writing
results to a file are defined in the SortingOperations.h file. The SortingResult.h file defines the SortingResult
structure, which holds the results of a sorting operation.

## Gathering Data

### Requirements

The project is designed to process a file containing 10,000 numbers and execute each sorting algorithm 10 times. The
numbers are sorted in increments of 1,000, starting with the first 1,000 numbers, then the first 2,000, and so on, up to
all 10,000 numbers.

This is achieved by calling the `executeSort()` function 10 times for each sorting algorithm in the `processFile()`
function. Each time the function is called, it sorts an increasing number of elements from the array of numbers read
from the file.

The `executeSort()` function takes in the array of numbers, the sorting function to be used, the name of the sorting
algorithm, the index of the array, the `SortingResult` array to store the results, and the file path of the input file.
The index of the array is incremented by 1,000 after each execution of the sorting algorithm, allowing the next 1,000
numbers to be sorted.

The results of each sorting operation, including the name of the sorting algorithm, the number of comparisons, swaps,
function calls made, and the execution time, are stored in the `SortingResult` array. These results are then written to
a .csv file by the `writeResultsToFile()` function.

Therefore, the input file must contain at least 10,000 numbers to ensure that each sorting algorithm can be executed 10
times with an increasing number of elements. If the file contains less than 10,000 numbers, the program will not be able
to execute all sorting operations as expected.

### Data Gathering Process

The data is gathered from the sorting algorithms through the `executeSort()` function, which is called in
the `processFile()` function in `main.c`. This function takes in the array of numbers to be sorted, the sorting function
to be used, the name of the sorting algorithm, the index of the array, the `SortingResult` array to store the results,
and the file path of the input file.

Here's a brief overview of how the data is gathered:

1. The `processFile()` function reads numbers from an input file and stores them in an array.
2. The `executeSort()` function is called for each sorting algorithm. This function sorts the numbers using the provided
   sorting function and stores the results in the `SortingResult` array.
3. The `writeResultsToFile()` function is then called to write the sorting results to a specified file.

The `SortingResult` structure, defined in `SortingResult.h`, holds the results of a sorting operation. It includes the
following fields:

- `algorithmName`: The name of the sorting algorithm used.
- `numComparisons`: The number of comparisons made during the sorting operation.
- `numSwaps`: The number of swaps made during the sorting operation.
- `numFunctionCalls`: The number of function calls made during the sorting operation.
- `executionTime`: The time taken to execute the sorting operation.

These fields correspond to the columns in the .csv file. Each row in the .csv file represents a single sorting
operation, with the columns representing the above fields. The `writeResultsToFile()` function writes these results to
the .csv file in an organized manner.

## Modules

<details closed><summary>.</summary>

| File                                                                                                                    | Summary                                                                                                                                                                                                                |
|-------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [main.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/main.c)                 | main file where the program execution begins. It includes the main() function and the processFile() function.                                                                                                          |
| [CMakeLists.txt](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/CMakeLists.txt) | file that is used to build the project using CMake. It contains the project name, version, and the minimum required version of CMake. It also includes the source files and header files that are part of the project. |

</details>

<details closed><summary>files</summary>

| File                                                                                                                | Summary                                                                                                                                                                 |
|---------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [file2.txt](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/files/file2.txt) | file that contains 10,000 numbers that are used as input for the sorting algorithms. The numbers are read from this file and sorted using different sorting algorithms. |
| [file1.txt](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/files/file1.txt) | file that contains 10,000 numbers that are used as input for the sorting algorithms. The numbers are read from this file and sorted using different sorting algorithms. |

</details>

<details closed><summary>include</summary>

| File                                                                                                                                                       | Summary                                                                                                                                                                         |
|------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [SortingResult.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/SortingResult.h)                          | This file defines the `SortingResult` structure, which holds the results of a sorting operation.                                                                                |
| [DataAnalysis.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/DataAnalysis.h)                            | This file contains functions for character operations.                                                                                                                          |
| [PlotData.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/PlotData.h)                                    | This file contains functions for plotting data using the pbPlots library.                                                                                                       |
| [SortingAlgorithms.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/SortingAlgorithms.h)                  | This file defines the sorting functions used in the project, including `bubbleSort()`, `selectionSort()`, `insertionSort()`, `countingSort()`, `quickSort()` and `mergeSort()`. |
| [Swap.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/Swap.h)                                            | This file contains functions for swapping elements in an array.                                                                                                                 |
| [ResultManagement.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/ResultManagement.h)                    | This file defines the `ResultManagement` structure, which holds the results of a sorting operation.                                                                             |
| [README.md](README.md) [FileOperations.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/FileOperations.h) | This file contains functions for file operations, such as reading numbers from a file and writing results to a file.                                                            |
| [CharOperations.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/CharOperations.h)                        | This file contains functions for character operations.                                                                                                                          |
| [SortingOperations.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/include/SortingOperations.h)                  | This file defines the `executeSort()` and `writeResultsToFile()` functions, which are used to perform the sorting operations and write the results to a file.                   |

</details>

<details closed><summary>pbPlot</summary>

| File                                                                                                                       | Summary                                                                                             |
|----------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------|
| [supportLib.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/pbPlot/supportLib.c) | This file contains the implementation of the support library functions used by the pbPlots library. |
| [pbPlots.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/pbPlot/pbPlots.c)       | This file contains the implementation of the pbPlots library functions.                             |
| [supportLib.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/pbPlot/supportLib.h) | This file contains the declarations of the support library functions used by the pbPlots library.   |
| [pbPlots.h](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/pbPlot/pbPlots.h)       | This file contains the declarations of the pbPlots library functions.                               |

</details>

<details closed><summary>src</summary>

| File                                                                                                                                  | Summary                                                                      |
|---------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------|
| [Swap.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/Swap.c)                           | This file contains the implementation of the swap functions.                 |
| [FileOperations.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/FileOperations.c)       | This file contains the implementation of the file operations functions.      |
| [SortingAlgorithms.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/SortingAlgorithms.c) | This file contains the implementation of the sorting algorithms.             |
| [SortingOperations.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/SortingOperations.c) | This file contains the implementation of the sorting operations functions.   |
| [CharOperations.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/CharOperations.c)       | This file contains the implementation of the character operations functions. |
| [DataAnalysis.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/DataAnalysis.c)           | This file contains the implementation of the data analysis functions.        |
| [ResultManagement.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/ResultManagement.c)   | This file contains the implementation of the result management functions.    |
| [PlotData.c](https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis/blob/master/src/PlotData.c)                   | This file contains the implementation of the plot data functions.            |

</details>

---
## Documentation

### Functions

- `processFile()`: This function reads numbers from an input file, sorts them using different sorting algorithms, and
  writes the results to a result file.

- `executeSort()`: This function reads numbers from the file, sorts them using the provided sorting function, and stores
  the results in the `SortingResult` array.

- `writeResultsToFile()`: This function writes the sorting results to the specified file.


### Sorting Algorithms

- `bubbleSort()`
- `selectionSort()`
- `insertionSort()`
- `countingSort()`
- `quickSort()`
- `mergeSort()`

### Adding and Removing Sorting Algorithms

The sorting algorithms used in this project are defined in the `SortingAlgorithms.h` file and are executed in
the `processFile()` function in the `main.c` file.

#### Removing a Sorting Algorithm

To remove a sorting algorithm, you need to remove the corresponding `executeSort()` function call in the `processFile()`
function. For example, to remove the Merge Sort algorithm, you would remove this line:

```c
executeSort(numbers, mergeSort, "Merge Sort", &arrIndex, sortingResultsFile, filePath);
```

#### Adding a Sorting Algorithm

To add a new sorting algorithm, you need to:

1. Define the sorting function in the `include\SortingAlgorithms.h` file.
2. Implement the sorting function in the `src\SortingAlgorithms.c` file.
3. Add a new `executeSort()` function call in the `processFile()` function that is located in `main.c`, passing the new
   sorting function as an argument. For example, if you've added a Heap Sort function named `heapSort()`, you would add
   this line:

```c
executeSort(numbers, heapSort, "Heap Sort", &arrIndex, sortingResultsFile, filePath);
```

Remember to adjust the **NUM_SORTING_ALGORITHMS** and NUM_RESULTS_PER_ALGORITHM constants as needed when adding or
removing sorting algorithms.

## Prerequisites

Before running this project, you need to ensure that your system meets the following prerequisites:

1. **C Compiler**: The project is implemented in C, so you need a C compiler to compile the source code. GCC (GNU
   Compiler Collection) is recommended. You can download it from [here](https://gcc.gnu.org/install/index.html).

2. **Text Editor or IDE**: You need a text editor or an Integrated Development Environment (IDE) to view and edit the
   source code. Examples include Visual Studio Code, Sublime Text, or CLion.

3. **Command Line Interface**: You need a command line interface to compile and run the project. On Windows, you can use
   Command Prompt or PowerShell. On macOS and Linux, you can use Terminal.

4. **Git**: If you want to clone the project repository from GitHub, you need to have Git installed on your system. You
   can download it from [here](https://git-scm.com/downloads).

5. **Absolute Paths**: You need to provide absolute paths to the input and output files in the `main.c` file. This is
   necessary to ensure that the program can read from and write to the specified files.

## Getting Started

### Installation
1. Clone the repository to your local machine.
```bash
git clone https://github.com/Olszewski-Jakub/Sorting-Algorithms-Performance-Analysis
```

2. Go to the project directory.
```sh
cd Sorting-Algorithms-Performance-Analysis
```

3. Modify the `main.c` file paths to the input and output files as needed. Your paths need to be a **bsolute paths**.


### Running Sorting-Algorithms-Performance-Analysis
1. Compile the project using the following command:

```bash
gcc -I ./include -o main main.c ./src/*.c ./pbPlot/*.c
```

2. Run the compiled program using the following command:

```bash
.\main.exe
```

3. You will find gathered data in .csv file you gave as an output file path in `/files` directory.


## Performance Analysis

### Average Time vs Algorithms
![Average Time vs Algorithms](graphs/readme/avg_time_vs_alg.png)
This graph illustrates the average time taken by different algorithms. As evident, Algorithm A outperforms others in terms of execution time.

### Average Comparisons vs Algorithms
![Average Comparisons vs Algorithms](graphs/readme/comp_vs_time.png)
Comparing various algorithms based on the average number of comparisons they make during execution. Algorithm B shows the most efficient performance in terms of comparisons.

### Average Swaps vs Algorithms
![Average Swaps vs Algorithms](graphs/readme/swaps_vs_time.png)
Graph depicting the average number of swaps performed by different algorithms. Algorithm C exhibits the lowest number of swaps among all algorithms.

## Contact Information

For any queries or suggestions, you can reach out to me at:

- GitHub: [Olszewski-Jakub](https://github.com/Olszewski-Jakub)
- Email: j.olszewski05@gmail.com
- LinkedIn: [Jakub Olszewski](https://www.linkedin.com/in/j-olszewski/)
- Portfolio: [Jakub Olszewski - Portfolio](https://jakubolszewski.netlify.app/)

