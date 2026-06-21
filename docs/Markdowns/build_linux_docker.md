# Linux And Docker Build

Docker is the reproducibility check for the non-GUI core. It proves that a clean
machine can configure the project, install vcpkg dependencies, and build without
depending on this Windows laptop.

## Build The Image

From the repository root:

```sh
docker build -t tsunami-barrier-studio:dev .
```

The Dockerfile:

- installs compiler, CMake, Ninja, Git, and archive tools
- clones vcpkg to `/opt/vcpkg`
- checks out the pinned vcpkg baseline
- configures `linux-vcpkg-headless`
- builds `linux-vcpkg-headless-build`
- runs `ctest`

## Native Linux Equivalent

If working directly on Linux instead of Docker:

```sh
export VCPKG_ROOT=/opt/vcpkg
export VCPKG_MAX_CONCURRENCY=2

cmake --preset linux-vcpkg-headless
cmake --build --preset linux-vcpkg-headless-build
ctest --test-dir build/linux-vcpkg-headless --output-on-failure
```

This preset disables:

```text
TSUNAMI_BUILD_GUI
TSUNAMI_BUILD_MATPLOT_SMOKE
```

That is intentional. GUI builds and interactive plotting should be checked
natively on developer machines, while Docker checks the portable numerical core.
