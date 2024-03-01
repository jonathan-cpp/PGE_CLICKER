#include "CollectorSystem.h"

CollectorSystem::CollectorSystem(entt::registry& registry, olc::PixelGameEngine* pge)
    : ISystem(registry, pge)
{
}

void CollectorSystem::Update(float deltaTime)
{
    GetRegistry().view<TagComponent, HitboxComponent>().each(
        [&](entt::entity entity, TagComponent& tag, HitboxComponent& hitbox)
        {
            if (GetPGE()->GetMouse(olc::Mouse::LEFT).bPressed)
            {
                olc::vi2d mousePos = GetPGE()->GetMousePos();
                // Check if the mouse position is within the hitbox
                if (mousePos.x >= hitbox.position.x &&
                    mousePos.x <= hitbox.position.x + hitbox.size.x &&
                    mousePos.y >= hitbox.position.y &&
                    mousePos.y <= hitbox.position.y + hitbox.size.y)
                {
                    // Handle the click event for the entity here
                    std::cout << "Click on entity with tag: " << (int)tag.type << std::endl;
                    
                    // Send an Event
                    OnCoinPickupEvent(1);

                    GetRegistry().destroy(entity);
                }
            }
        });
}