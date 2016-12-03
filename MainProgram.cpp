#include <SFML/Graphics.hpp>



using namespace sf;

int main()
{


RenderWindow OknoAplikacji; //obiekt który przetrzymuje okno aplikacji
Event zdarzenie; // zdarzenia w programie

//okno aplikacji/////////////////////////////////////////////////////////////////////////////////////
        OknoAplikacji.create(VideoMode(1024,768,32),"Eat to Life - EOT"); // okno aplikacji
////////////////////////////////////////////////////////////////////////////////////////////////

//Petla glowna gry///////////////////////////////////////////////////////////////////////////////////////
                while( OknoAplikacji.isOpen() )
                {

                        while( OknoAplikacji.pollEvent( zdarzenie ) )
                        {
                            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                            {
                                OknoAplikacji.close();
                            }

                            if( zdarzenie.type == Event::Closed )
                            {
                                OknoAplikacji.close();
                            }
                        }

                            OknoAplikacji.clear();
                            OknoAplikacji.display();
                            }
/////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}
