param(
    [switch] $Visualization
)

$ErrorActionPreference = "Stop"

$configurePreset = "qt-kit-vcpkg"
$buildPreset = "qt-kit-vcpkg-debug"

if ($Visualization) {
    $configurePreset = "qt-kit-vcpkg-visualization"
    $buildPreset = "qt-kit-vcpkg-visualization-debug"
}

cmake --preset $configurePreset
cmake --build --preset $buildPreset
