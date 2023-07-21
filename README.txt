# Console Application: Polygon Intersection

This console application is designed to determine the status of each line segment with respect to a given polygon on an abstract plane with x and y axes. The application takes two input files:

1. `polys.txt`: Contains the list of points defining the polygon in the format `x1,y1 x2,y2 x3,y3 x4,y4`, where points are separated by spaces and coordinates x and y of each point are separated by commas.
2. `lines.txt`: Contains the list of line segments in the format `x1,y1 x2,y2` (one line per segment), where points are separated by spaces and coordinates x and y of each point are separated by commas.

The possible relationship statuses between the line segments and the polygon are as follows:
0 - The line segment is inside the polygon (both points lie inside the polygon).
1 - The line segment intersects the polygon (both points lie outside the polygon).
2 - The line segment partially intersects the polygon (one of the points lies inside the polygon, and the other lies outside).
3 - The line segment has nothing in common with the polygon (both points lie outside the polygon).

The results of the analysis will be written to an output file named `results.txt`, where each line corresponds to the relationship status of the corresponding line segment from `lines.txt` (i.e., the line numbers will match).

## Usage

1. Prepare the input files (`polys.txt` and `lines.txt`) with the appropriate format as described above.
2. Run the console application providing the input files in the same directory as the executable.
3. The program will analyze each line segment with respect to the given polygon and write the status of each line segment to `results.txt`.

## Example Input

`polys.txt`:
```
0,0 4,0 4,3 0,3
```

`lines.txt`:
```
1,1 2,2
3,3 5,5
0,0 2,1
```

## Example Output

`results.txt`:
```
0
3
2
```

## Building and Running

To build the application, follow these steps:

1. Make sure you have a C++ compiler and standard libraries installed on your system.
2. Place the `main.cpp` file in a directory.
3. Open a terminal and navigate to the directory containing `main.cpp`.
4. Compile the source code using the following command:
   ```
   g++ main.cpp -o polygon_intersection
   ```
   Note: Ensure that the name `polygon_intersection` does not conflict with other files in the directory.
5. Run the compiled application:
   ```
   ./polygon_intersection
   ```
6. The results will be generated in the `results.txt` file.

## Dependencies

This program was designed to be implemented using only the standard C++ library. However, if there are additional dependencies or third-party libraries required to build and run the application on your specific Linux system, please ensure they are installed and properly configured.

Feel free to explore the code and modify it to handle more complex scenarios or extend the functionality to work with polygons with a greater number of vertices.

Please refer to the provided `main.cpp` file for the actual implementation of the application. Happy coding!