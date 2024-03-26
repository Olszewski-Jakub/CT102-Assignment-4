# Use a base image with GCC installed
FROM gcc:6.3.0

# Set the working directory inside the container
WORKDIR /app

# Copy the necessary files into the container
COPY ./include ./include
COPY ./src ./src
COPY ./pbPlot ./pbPlot
COPY ./files ./files
COPY ./graphs ./graphs
COPY main.c .

# Compile the C project using GCC
RUN gcc -I ./include -o main main.c ./src/*.c ./pbPlot/*.c -lm

# Command to run the executable when the container starts
CMD ["./main"]