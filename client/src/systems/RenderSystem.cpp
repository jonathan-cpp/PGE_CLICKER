#include "RenderSystem.h"

RenderSystem::RenderSystem(entt::registry& registry, olc::PixelGameEngine* pge)
    : ISystem(registry, pge)
{
}

void RenderSystem::Update(float deltaTime)
{
/*
    GetRegistry().sort<SpriteComponent>(
        [](const auto& lhs, const auto& rhs) {
            const sf::FloatRect leftBounds = lhs.sprite.getGlobalBounds();
            const sf::FloatRect rightBounds = rhs.sprite.getGlobalBounds();         
            return leftBounds.top + leftBounds.height < rightBounds.top + rightBounds.height;
        });
    */
}

void RenderSystem::Render()
{
    GetRegistry().view<TransformComponent, SpriteComponent>().each(
        [&](TransformComponent& transform, SpriteComponent& spriteComponent)
        {
            GetPGE()->DrawSprite(transform.position, spriteComponent.sprite.get());
        });
}