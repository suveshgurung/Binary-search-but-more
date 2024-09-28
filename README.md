# Binary Search But More

This is just an ordinary binary search. Binary seach requires an array to be sorted first. So this project has two purposes, one to sort a random array generated using **rand()** and store the sorted array in a file called **sorted_array.txt**. Then you can use the binarySearch algorithm to find the number you are looking for!!!

# Build

To build this project, simply run the command:
```sh
make
```
This should generate two files executable files: **sort** and **binarySearch**.

# Usage

After building the project, to start sorting and searching, first run the command:
```sh
./sort
```
This should produce a new file called **sorted_array.txt** which will store the randomly generated array in ascending order.\
Now to search for a number in the given sorted array, run the command:
```sh
./binarySearch
```
This will prompt you for the number you want to search and voilla, the binary search comes into action and gives you the position of the number if it is present in the generated array.
