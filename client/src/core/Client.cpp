#include "Client.h"

#include "MainMenuScene.h"

Client::Client()
{
    sAppName = Constants::WINDOW_TITLE;
}

bool Client::OnUserCreate()
{
    m_sceneManager.RegisterScene<MainMenuScene>("MainMenuScene", this);
    m_sceneManager.PushScene("MainMenuScene");

    return true;
}

bool Client::OnUserUpdate(float fElapsedTime)
{
    m_sceneManager.FixedUpdateScene(fElapsedTime);
    m_sceneManager.UpdateScene(fElapsedTime);
    
    Clear(olc::BLACK);
    m_sceneManager.RenderScene();
    
    return true;
}

bool Client::OnUserDestroy()
{
    return true;
}
