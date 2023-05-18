#include <SFML/Graphics.hpp>
#include <stdio.h>



int KeypressHandler(int keycode, sf::Sprite sprite) {

}



int main()
{
    //window init
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    window.setActive(true);


    //load textures



    sf::Texture texture;
    if (!texture.loadFromFile("sprites/dungeon_sheet.png", sf::IntRect(305, 112, 16, 16)))
    {
        printf("error loading textures");
    }

    //sprite intalisze


    sf::Sprite sprite;
    sprite.setScale(sf::Vector2f(10.f, 10.f)); // absolute scale factor

    sprite.setTexture(texture);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:

                // KeypressHandler(event.key.code, sprite);

                switch (event.key.code)
                {
                case sf::Keyboard::W:
                sprite.move(sf::Vector2f(0, -5.f)); // offset relative to the current position
                    break;
                case sf::Keyboard::A:
                sprite.move(sf::Vector2f(-5.f, 0)); // offset relative to the current position
                    break;
                case sf::Keyboard::S:
                sprite.move(sf::Vector2f(0, 5.f)); // offset relative to the current position
                    break;
                case sf::Keyboard::D:
                sprite.move(sf::Vector2f(5.f, 0)); // offset relative to the current position
                    break;
                
                default:
                    break;
                }
                break;

            default:
                break;
            }

        //render handler

        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(sprite);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();



        }      
    }

    return 0;
}
