#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Point.h"
#include<random.h>

#include<iostream>

using namespace sf;

int main()
{
    RenderWindow OknoAplikacji;
    Event zdarzenie;

//zmienne////////////////////////////////////////////////////////////////////////////////////////////////////////
        int licznik=0;
        int licznik2=0;
        int licznik3=0;

        int iloscZyc=3;
        int LiczbaPunktow=0;

        float spawnPrzeciwnik=4;
        Time CzasSpawnuPrzeciwnik;
        Clock czasDzialania;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  Tekstury i sprajty

        Texture PoleObrTex;
        Sprite PoleObrSp;

        Texture PoleTex;
        Sprite PoleSp;

        Texture PostacTex;

        Texture StworTex;

        Texture OwocTex;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Wczytanie Tekstur i Spritow



                PostacTex.loadFromFile("Tekstury\\postac.png");

                StworTex.loadFromFile("Tekstury\\stwor.png");

                PoleObrTex.loadFromFile("Tekstury\\poleObr.png");
                PoleObrSp.setTexture(PoleObrTex);

                PoleTex.loadFromFile("Tekstury\\pole.png");
                PoleSp.setTexture(PoleTex);

                OwocTex.loadFromFile("Tekstury\\owoc.png");



////////////////Okno gry////////////////////////////////////////////////////////////////////////////////////////

                    OknoAplikacji.create(VideoMode(1024,768,32),"Eat to Life - EOT");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


srand(time(NULL));


        vector<Enemy>::const_iterator iter;
        vector<Enemy> wrogTablica;

class Player gracz;
    gracz.sprite.setTexture(PostacTex);
    gracz.rect.setPosition(OknoAplikacji.getSize().x/2,OknoAplikacji.getSize().y/2);


class Enemy wrog;
    wrog.sprite.setTexture(PostacTex);




        vector<Point>::const_iterator iter2;
        vector<Point> TablicaPunktow;

Point Punkty;
    Punkty.sprite.setTexture(OwocTex);
    Punkty.rect.setPosition(rand ()% (OknoAplikacji.getSize().x-200) +100,rand ()% (OknoAplikacji.getSize().y-200) +100);

        TablicaPunktow.push_back(Punkty);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Petla glowna gry
                            while( OknoAplikacji.isOpen() )
                            {
//                  ////////////////////////////////////////////////////////////////
//Zdarzenia
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



CzasSpawnuPrzeciwnik=czasDzialania.getElapsedTime();
if(CzasSpawnuPrzeciwnik.asSeconds()>spawnPrzeciwnik)
{
        wrog.rect.setPosition(480,350);
        wrogTablica.push_back(wrog);

        czasDzialania.restart();
}


licznik2=0;
for(iter = wrogTablica.begin(); iter!= wrogTablica.end();iter++)
{
   if(wrogTablica[licznik2].rect.getGlobalBounds().intersects(gracz.rect.getGlobalBounds()))
   {
       iloscZyc=iloscZyc-1;
       gracz.rect.setPosition(OknoAplikacji.getSize().x/2,OknoAplikacji.getSize().y-100);

               if(iloscZyc==0)
               {
                 OknoAplikacji.close();
               }

   }
licznik2++;
}




licznik3=0;
for(iter2= TablicaPunktow.begin(); iter2!= TablicaPunktow.end();iter2++)
{
   if(TablicaPunktow[licznik3].rect.getGlobalBounds().intersects(gracz.rect.getGlobalBounds()))
    {

LiczbaPunktow=LiczbaPunktow+1;
    OknoAplikacji.close();
    }
licznik3++;
}

            gracz.update();
            gracz.Steruj();

                    OknoAplikacji.clear();
                    OknoAplikacji.draw(PoleSp);


//////////// Rysuj Przeciwnikow ////////////////////////////////////////////
licznik2=0;
for(iter = wrogTablica.begin(); iter!= wrogTablica.end();iter++)
{
    wrogTablica[licznik2].update();
    wrogTablica[licznik2].Steruj();
                    OknoAplikacji.draw(wrogTablica[licznik2].sprite);
licznik2++;
}

///////////////////Rysuj Punkty ///////////////////////////////////////////
licznik3=0;
for(iter2 = TablicaPunktow.begin(); iter2!= TablicaPunktow.end();iter2++)
{
    TablicaPunktow[licznik3].update();
                    OknoAplikacji.draw(TablicaPunktow[licznik3].sprite);
licznik3++;
}

//////////////////Rysuj Pole ////////////////////////////////////////////
                    OknoAplikacji.draw(gracz.sprite);
                    OknoAplikacji.draw(PoleObrSp);
                    OknoAplikacji.display();

            }
    return 0;
}
