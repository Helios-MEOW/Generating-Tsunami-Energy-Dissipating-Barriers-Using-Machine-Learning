# Generating Tsunami Energy-Dissipating Barriers Using Machine Learning

Research codebase for tsunami barrier simulation, data handling, visualisation,
GUI development, and machine-learning workflows.

## Start Here

- [Dependency strategy](docs/dependencies.md)
- [Repository layout](docs/repository_layout.md)
- [Windows MinGW build notes](docs/build_windows_mingw.md)
- [Linux/Docker build notes](docs/build_linux_docker.md)
- [Final development workflow](docs/workflow.md)

The C++ build is CMake-based and uses C++20. Third-party C++ packages are
declared in `vcpkg.json`; Qt can be provided either by the Qt installer or by
the optional vcpkg `gui` feature.
