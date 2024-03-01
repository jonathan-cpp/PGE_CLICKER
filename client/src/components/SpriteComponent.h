#pragma once

//////////////////////////////////////////////////////////
// Standard Library Headers
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// External Library Headers
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Project Headers
//////////////////////////////////////////////////////////

#include "IComponent.h"

//////////////////////////////////////////////////////////
// Forward Declarations
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Constants and Enums
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Class Declaration
//////////////////////////////////////////////////////////

class SpriteComponent : public IComponent {
public:
    std::unique_ptr<olc::Sprite> sprite;
};