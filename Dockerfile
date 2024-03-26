# Use a base image with MinGW installed
FROM ubuntu:latest

# Install MinGW compiler and required tools
RUN apt-get update && \
    apt-get install -y mingw-w64 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /app

# Copy the necessary files into the container
COPY ./include ./include
COPY ./src ./src
COPY ./pbPlot ./pbPlot
COPY ./files ./files
COPY ./graphs ./graphs
COPY main.c .

# Compile the C project using MinGW
RUN i686-w64-mingw32-gcc -I ./include -o main.exe main.c ./src/*.c ./pbPlot/*.c -lm

# Command to run the executable when the container starts
CMD ["./main.exe"]
