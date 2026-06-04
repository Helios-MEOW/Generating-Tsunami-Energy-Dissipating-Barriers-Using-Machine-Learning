#pragma once // Restrict multiple inclusions of this header file

#include "core/Types.hpp" // Include header for type definitions

namespace tsunami::models
{
class ShallowWaterModel
{
    public:
    
    private:
    
        void Explicit_Transport();
        void Positivity_Preserving();
        void Semi_Implicit_Friction();
        void Coriolis_Rotation();
        void Viscosity_Update();
};
}