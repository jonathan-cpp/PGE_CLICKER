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

#include "ISystem.h"

//////////////////////////////////////////////////////////
// Forward Declarations
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Constants and Enums
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Class Declaration
//////////////////////////////////////////////////////////

class RenderSystem : public ISystem {
public:
    explicit RenderSystem(entt::registry& registry, olc::PixelGameEngine* pge);
    virtual ~RenderSystem() = default;

    // Public Functions
    void Update(float deltaTime) override;
    void Render() override;

protected:

    // Protected Functions

private:
    RenderSystem(const RenderSystem&) = delete;
    RenderSystem(RenderSystem &&) = delete;
    RenderSystem& operator=(const RenderSystem&) = delete;
    RenderSystem&& operator=(RenderSystem&&) = delete;

private:
    // Private Functions

private:
    // Member Variables

};