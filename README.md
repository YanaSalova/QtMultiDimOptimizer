# QtMultiDimOptimizer
QtMultiDimOptimizer is a C++ application for optimizing multidimensional functions with Qt visualization. It supports gradient descent and random search methods. Visualize function relief with colors, compute and plot the optimization trajectory, and display point values at each step.


### Features

1. **Set Optimization Parameters**: Define the multidimensional function, stopping criterion, search domain, and search method (gradient descent or random search).
2. **Function Visualization**: Display the function's values on a plane using color gradients to represent different values (similar to elevation maps).
3. **Trajectory Plotting**: Compute and visualize the trajectory of the function's minimum as a polyline.
4. **Step-by-Step Values**: Display the point values, function values, and local minimum values at each step of the optimization process.



### Usage

1. **Set Optimization Parameters**:
    - Define the multidimensional function to be optimized.
    - Set the stopping criterion for the optimization process.
    - Specify the domain where the minimum will be searched.
    - Choose the search method: gradient descent or random search.

2. **Run the Optimization**:
    - Start the optimization process and visualize the function's relief and the optimization trajectory on the plane.

3. **Analyze Results**:
    - Observe the polyline representing the trajectory of the function's minimum.
    - Review the point values, function values, and local minimum values at each optimization step.

### Development

This application uses Qt for the graphical user interface. Ensure you have the necessary development environment set up for building Qt applications.

### Documentation

- Documentation has been generated using Doxygen and includes:

    - **User Documentation**: A user manual detailing how to use the application, set parameters, generate samples, and interpret results. The interface is designed to be intuitive, but detailed instructions are provided for clarity.

    - **Developer Documentation**: Comprehensive documentation for developers, including:
        - **Class Descriptions**: Detailed descriptions of each class, including purpose and functionality.
        - **Method Descriptions**: Detailed descriptions of methods, including parameters, return values, and examples of usage.
        - **Code Comments**: Inline comments throughout the code to explain complex logic and algorithms.
        - **Doxygen Output**: Generated HTML and PDF documentation from comments in the code. 
