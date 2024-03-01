#include "Client.h"

#define PIXEL_SIZE 2

int main(int argc, char* argv[])
{
    Client client;
    if(client.Construct(
        Constants::WINDOW_WIDTH / PIXEL_SIZE,
        Constants::WINDOW_HEIGHT / PIXEL_SIZE,
        PIXEL_SIZE,
        PIXEL_SIZE)) 
    {
        client.Start();
    }

    return 0;
}