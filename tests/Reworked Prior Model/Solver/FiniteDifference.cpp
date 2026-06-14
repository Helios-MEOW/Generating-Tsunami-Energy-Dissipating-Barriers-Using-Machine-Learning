#include <vector>
#include <iostream>
#include "FiniteDifference.hpp"
#include <cmath>
#define _USE_MATH_DEFINES // For pi

// Defining Domain properties via lambda function

FiniteDifference::Domain FiniteDifference::Mesh_Generation()
{
    FiniteDifference::Domain domain;
    domain.Lx = 10;                    // Number of grid points in x direction
    domain.Ly = 10;                    // Number of grid points in y direction
    domain.dx = 0.1;                   // Grid spacing in x direction
    domain.dy = 0.1;                   // Grid spacing in y direction
    domain.Nx = domain.Lx / domain.dx; // Number of grid points in x direction
    domain.Ny = domain.Ly / domain.dy; // Number of grid points
    domain.dt = 0.001;                 // Time step
    domain.Lx_linspace = Generate_Linspace(0, domain.Lx, domain.Nx);
    domain.Ly_linspace = Generate_Linspace(0, domain.Ly, domain.Ny);
    domain.domain_space = std::vector<std::vector<int>>(domain.Nx, std::vector<int>(domain.Ny, 0)); // Create a Nx by Ny grid full of zeros
    return domain;
};

std::vector<int> FiniteDifference::Generate_Linspace(int start, int end, int length)
{
    std::vector<int> linspace;                     // Declaring the vector for linearly spaced integers
    int delta = (start - end) / length;            // Define the incrementer
    linspace.push_back(start);                     // Add  the first element to the vector
    for (int element; element < length; element++) // loop to assign linearly spaced elements to a vector
    {
        int new_element = linspace[element] + delta;
        linspace.push_back(new_element);
    };

    return linspace;
};

FiniteDifference::Step_Results FiniteDifference::Elliptic_Solver(FiniteDifference::Domain domain, FiniteDifference::Step_Results step_results) {
    /* We initialise in main.cpp with the original domain which is altered in the initial conditions class object and further from the boundary conditions in the respective class.

    So what we have to do in this function is simply expect the domain to be configured initially by the IC and BC and we can simply proceed with the Poisson solve

    Steps
    */

};