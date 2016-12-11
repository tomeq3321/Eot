#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Point.h"
#include "TheGame.h"
#include<random.h>
#include<vector>

#include<iostream>

using namespace sf;

int main()
{

    RenderWindow OknoAplikacji;
    Event zdarzenieMenu;


        OknoAplikacji.create(VideoMode(1024,768,32),"Eat to Life - EOT");

            Texture MenuTex;
            Texture MenuStartTex;
            Texture MenuAutorzyTex;
            Texture MenuOpcjeTex;
            Texture MenuWyjscieTex;

            Sprite MenuSpr;
            Sprite MenuStartSpr;
            Sprite MenuAutorzySpr;
            Sprite MenuOpcjeSpr;
            Sprite MenuWyjscieSpr;

            MenuTex.loadFromFile("Tekstury\\menuTlo.png");
            MenuSpr.setTexture(MenuTex);

            MenuStartTex.loadFromFile("Tekstury\\menuStart.png");
            MenuStartSpr.setTexture(MenuStartTex);
            MenuStartSpr.setPosition(100,368);

            MenuAutorzyTex.loadFromFile("Tekstury\\menuAutorzy.png");
            MenuAutorzySpr.setTexture(MenuAutorzyTex);
            MenuAutorzySpr.setPosition(100,418);

            MenuOpcjeTex.loadFromFile("Tekstury\\menuOpcje.png");
            MenuOpcjeSpr.setTexture(MenuOpcjeTex);
            MenuOpcjeSpr.setPosition(100,468);

            MenuWyjscieTex.loadFromFile("Tekstury\\menuWyjscie.png");
            MenuWyjscieSpr.setTexture(MenuWyjscieTex);
            MenuWyjscieSpr.setPosition(100,518);





            while( OknoAplikacji.isOpen() )
                {


                    while( OknoAplikacji.pollEvent( zdarzenieMenu ) )
                    {
                        if( zdarzenieMenu.type == sf::Event::MouseButtonPressed && zdarzenieMenu.mouseButton.button == sf::Mouse::Left  &&  MenuStartSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( OknoAplikacji ) ) ))
                        {

                                    OknoAplikacji.clear();
                            //zmienne////////////////////////////////////////////////////////////////////////////////////////////////////////
                                    Event zdarzenie;
                                    int licznik=0;
                                    int licznik2=0;
                                    int licznik3=0;




                                    float spawnPrzeciwnik=4;
                                    Time CzasSpawnuPrzeciwnik;
                                    Clock czasDzialania;

                                    srand(time(NULL));

                            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                              //  Tekstury i sprajty

                                    Texture PoleObrTex;
                                    Sprite PoleObrSp;

                                    Texture PoleTex;
                                    Sprite PoleSp;

                                    Texture PostacTex;

                                    Texture WrogTex;

                                    Texture OwocTex;

                                    Texture KoniecGtyTex;
                                    Sprite KoniecGtySpr;

                            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            //Wczytanie Tekstur i Spritow



                                            PostacTex.loadFromFile("Tekstury\\postac.png");

                                            WrogTex.loadFromFile("Tekstury\\wrog.png");

                                            PoleObrTex.loadFromFile("Tekstury\\poleObr.png");
                                            PoleObrSp.setTexture(PoleObrTex);

                                            PoleTex.loadFromFile("Tekstury\\pole.png");
                                            PoleSp.setTexture(PoleTex);

                                            OwocTex.loadFromFile("Tekstury\\owoc.png");

                                            KoniecGtyTex.loadFromFile("Tekstury\\koniecGry.png");
                                            KoniecGtySpr.setTexture(KoniecGtyTex);



                                    vector<Enemy>::const_iterator iter;
                                    vector<Enemy> wrogTablica;

                            class Player gracz;
                                gracz.sprite.setTexture(PostacTex);
                               // gracz.rect.setPosition(OknoAplikacji.getSize().x/2,OknoAplikacji.getSize().y/2);


                            class Enemy wrog;
                                wrog.sprite.setTexture(WrogTex);




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
                                   gracz.iloscZyc=gracz.iloscZyc-1;
                                   gracz.rect.setPosition(512,700);



                               }
                            licznik2++;
                            }




                            licznik3=0;
                            for(iter2= TablicaPunktow.begin(); iter2!= TablicaPunktow.end();iter2++)
                            {
                               if(TablicaPunktow[licznik3].rect.getGlobalBounds().intersects(gracz.rect.getGlobalBounds()))
                                {
                                    Punkty.LiczbaPunktow=Punkty.LiczbaPunktow+1;
                                    TablicaPunktow[licznik3].ZebranyPunkt=true;

                                }
                            licznik3++;
                            }

                            licznik3=0;
                            for(iter2= TablicaPunktow.begin(); iter2!= TablicaPunktow.end();iter2++)
                            {
                                if(TablicaPunktow[licznik3].ZebranyPunkt==true)
                                {
                                   // OknoAplikacji.close();
                                    TablicaPunktow.erase(TablicaPunktow.begin());

                                  Punkty.rect.setPosition(rand ()% (OknoAplikacji.getSize().x-200) +100,rand ()% (OknoAplikacji.getSize().y-200) +100);

                                  TablicaPunktow.push_back(Punkty);
                                  Punkty.ZebranyPunkt=false;
                                  break;
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
                                                 if(gracz.iloscZyc<=0)
                                                {
                                                    OknoAplikacji.draw(KoniecGtySpr);
                                                }
                                                OknoAplikacji.display();

                                        }


                        }

                        if( zdarzenieMenu.type == sf::Event::MouseButtonPressed && zdarzenieMenu.mouseButton.button == sf::Mouse::Left  &&  MenuWyjscieSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( OknoAplikacji ) ) ))
                        {
                        OknoAplikacji.close();
                        }
                    }
                    OknoAplikacji.draw(MenuSpr);
                    OknoAplikacji.draw(MenuStartSpr);
                    OknoAplikacji.draw(MenuOpcjeSpr);
                    OknoAplikacji.draw(MenuAutorzySpr);
                    OknoAplikacji.draw(MenuWyjscieSpr);
                    OknoAplikacji.display();
                }










    return 0;
}
