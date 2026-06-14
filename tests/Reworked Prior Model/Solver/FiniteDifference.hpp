#pragma once

class FiniteDifference
{

public:
    // Finite difference should allow the modifications of the grid properties and time stepping parameters

    struct Domain
    {
        int Lx;                                     // Number of grid points in x direction
        int Ly;                                     // Number of grid points in y direction
        double dx;                                  // Grid spacing in x direction
        double dy;                                  // Grid spacing in y direction
        int Nx;                                     // Number of grid points in x direction
        int Ny;                                     // Number of grid points in y direction
        double dt;                                  // Time step size
        std::vector<int> Lx_linspace;               // Linearly spaced x vector
        std::vector<int> Ly_linspace;               // Linearly spaced y vector
        std::vector<std::vector<int>> domain_space; // computational domain
    };

    struct Step_Results
    {
        std::vector<std::vector<double>> vorticity; // 2d vector essentially
        std::vector<std::vector<double>> stream_function;
        std::vector<std::vector<double>> u_velocity;
        std::vector<std::vector<double>> v_velocity;
        double time;
        int step_number;
    };

    std::vector<int> Generate_Linspace(int start, int end, int length);

private:
    Domain Mesh_Generation();
    Step_Results Elliptic_Solver(Domain, Step_Results);
    Step_Results Jacobian_Solver(Domain, Step_Results);
    void Time_Stepping(Domain, Step_Results);
};
