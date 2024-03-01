#pragma once

//////////////////////////////////////////////////////////
// Standard Library Headers
//////////////////////////////////////////////////////////

#include <memory>
#include <vector>

//////////////////////////////////////////////////////////
// External Library Headers
//////////////////////////////////////////////////////////

#include <entt.hpp>

//////////////////////////////////////////////////////////
// Project Headers
//////////////////////////////////////////////////////////

#include "Systems.h"

//////////////////////////////////////////////////////////
// Forward Declarations
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Constants and Enums
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Class Declaration
//////////////////////////////////////////////////////////

class IScene {
public:
    explicit IScene() = default;
    virtual ~IScene() = default;

    void Update(float deltaTime) 
    {
        for(const auto& system : m_systems) {
            system->Update(deltaTime);
        }

        PostUpdate(deltaTime);
    }

    void FixedUpdate(float deltaTime) 
    {
        for(const auto& system : m_systems) {
            system->FixedUpdate(deltaTime);
        }
    }

    void Render() 
    {
        for(const auto& system : m_systems) {
            system->Render();
        }

        PostRender();
    }

    // Should really make Layers instead...
    virtual void PostUpdate(float deltaTime) { /* GUI ? */ }
    virtual void PostRender() { /* GUI ? */ }

    template<typename T, typename... Args>
    T* AddSystem(Args&&... args);

protected:
    entt::registry& GetRegistry() { return m_registry; }

private:
    IScene(const IScene&) = delete;
    IScene(IScene &&) = delete;
    IScene& operator=(const IScene&) = delete;
    IScene&& operator=(IScene&&) = delete;

private:
    // Private Functions

private:
    entt::registry m_registry;
    std::vector<std::unique_ptr<ISystem>> m_systems;
};

template <typename T, typename... Args>
inline T* IScene::AddSystem(Args&&... args) 
{
    T* ptr = new T(std::forward<Args>(args)...);
    m_systems.emplace_back(ptr);
    return ptr;
}