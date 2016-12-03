#include <SFML/Graphics.hpp>



using namespace sf;

int main()
{


RenderWindow OknoAplikacji;
Event zdarzenie;

OknoAplikacji.create(VideoMode(1024,768,32),"Eat to Life - EOT");

                                    while( OknoAplikacji.isOpen() )
                            {

                                while( OknoAplikacji.pollEvent( zdarzenie ) )
                                {

                                }
                            }

    return 0;
}
