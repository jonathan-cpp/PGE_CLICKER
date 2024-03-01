#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(olc::PixelGameEngine* pge)
{
    auto renderSystem = AddSystem<RenderSystem>(GetRegistry(), pge);
    auto collectorSystem = AddSystem<CollectorSystem>(GetRegistry(), pge);
    
    collectorSystem->OnCoinPickupEvent += [](int value) {
        std::cout << value << std::endl;
    };

    auto entity = GetRegistry().create();

    auto& spriteComponent = GetRegistry().emplace<SpriteComponent>(entity);
    spriteComponent.sprite = std::make_unique<olc::Sprite>(GetResourceDir() + "player.png");

    auto& transform = GetRegistry().emplace<TransformComponent>(entity);
    transform.position = olc::vf2d(50.f, 50.f);

    auto& hitbox = GetRegistry().emplace<HitboxComponent>(entity);
    hitbox.position = transform.position;
    hitbox.size = spriteComponent.sprite->Size();

    auto& tagComponent = GetRegistry().emplace<TagComponent>(entity);
    tagComponent.type = TagType::Coin;
}