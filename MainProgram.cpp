#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Point.h"
#include<random.h>
#include<vector>
#include<iostream>

using namespace sf;

int main()
{
    // Obiekty klas z sfml//////////////////////////////////////////////////
    RenderWindow windowApplication;
    Event eventMenu;
    Event eventOptions;


    // Wykorzystanie obiektu klasu renderWindow////////////////////////////
    windowApplication.create(VideoMode(1024,768,32),"Eat to Live - ETL");


    // Tworzenie obiektów dla tekstów i spritów////////////////////////////
    Texture MenuTex;
    Texture MenuStartTex;
    Texture MenuAuthorsTex;
    Texture MenuOptionsTex;
    Texture MenuExitTex;
    Texture MenuOptionsBackgroundTex;
    Texture MenuAuthorsBackgroundTex;

    Sprite MenuSpr;
    Sprite MenuStartSpr;
    Sprite MenuAuthorsSpr;
    Sprite MenuOptionsSpr;
    Sprite MenuExitSpr;
    Sprite MenuOptionsBackgroundSpr;
    Sprite MenuAuthorsBackgroundSpr;


    // wczytywanie tekstór z plików ///////////////////////////////////////
    if(!MenuTex.loadFromFile("Tekstury\\menuTlo.png")) exit(-1);
    MenuSpr.setTexture(MenuTex);

    if(!MenuStartTex.loadFromFile("Tekstury\\menuStart.png")) exit(-1);
    MenuStartSpr.setTexture(MenuStartTex);
    MenuStartSpr.setPosition(100,368);

    if(!MenuAuthorsTex.loadFromFile("Tekstury\\menuAutorzy.png")) exit(-1);
    MenuAuthorsSpr.setTexture(MenuAuthorsTex);
    MenuAuthorsSpr.setPosition(100,418);

    if(!MenuOptionsTex.loadFromFile("Tekstury\\menuOpcje.png")) exit(-1);
    MenuOptionsSpr.setTexture(MenuOptionsTex);
    MenuOptionsSpr.setPosition(100,468);

    if(!MenuExitTex.loadFromFile("Tekstury\\menuWyjscie.png")) exit(-1);
    MenuExitSpr.setTexture(MenuExitTex);
    MenuExitSpr.setPosition(100,518);

    if(!MenuOptionsBackgroundTex.loadFromFile("Tekstury\\MenuOpcjeTlo.png")) exit(-1);
    MenuOptionsBackgroundSpr.setTexture(MenuOptionsBackgroundTex);

    if(!MenuAuthorsBackgroundTex.loadFromFile("Tekstury\\MenuAutorzyTlo.png")) exit(-1);
    MenuAuthorsBackgroundSpr.setTexture(MenuAuthorsBackgroundTex);


    // petla glowna menu gry ///////////////////////////////////////////////
    while( windowApplication.isOpen() )
    {
        // petla wychwytijaca zdarzenia
        while( windowApplication.pollEvent( eventMenu ) )
        {
            if( eventMenu.type == sf::Event::MouseButtonPressed && eventMenu.mouseButton.button == sf::Mouse::Left  &&  MenuStartSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( windowApplication ) ) ))
            {

                windowApplication.clear();


                // zmienne ////////////////////////////////////////////////////////////////////////////////////////////////////////
                Event eventGame;
                int enemiesCounter=0;
                int pointsCounter=0;
                int exitClockCounter=0;
                float enemiesSpawn=4;
                float scaleBarStarvation=1;
                float scaleBarStarvationChange =0.01;
                bool backMenu=false;

                Clock BarStarvationClock;
                Time BarStarvationTime;
                Clock exitClock;
                Time exitTime;
                Time EnemiesTimeSpawn;
                Clock EnemiesSpawnClock;


                srand(time(NULL));


                //  Tekstury i sprajty tworzenie obiektow ///////////////////////////////////////////////////////////////////

                Texture fieldBorderTex;
                Texture fieldTex;
                Texture characterTex;
                Texture enemiesTex;
                Texture FruitTex;
                Texture gameOverTex;
                Texture starvationBarTex;

                Sprite fieldBorderSpr;
                Sprite FieldSpr;
                Sprite GameOverSpr;
                Sprite starvationBarSpr;


                //Wczytanie Tekstur i Spritow z plików ////////////////////////////////////////////////////////////////////////
                if(!characterTex.loadFromFile("Tekstury\\postac.png")) exit(-1);

                if(!enemiesTex.loadFromFile("Tekstury\\wrog.png")) exit(-1);

                if(!fieldBorderTex.loadFromFile("Tekstury\\poleObr.png")) exit(-1);
                fieldBorderSpr.setTexture(fieldBorderTex);

                if(!fieldTex.loadFromFile("Tekstury\\pole.png")) exit(-1);
                FieldSpr.setTexture(fieldTex);

                if(!FruitTex.loadFromFile("Tekstury\\owoc.png")) exit(-1);

                if(!gameOverTex.loadFromFile("Tekstury\\koniecGry.png")) exit(-1);
                GameOverSpr.setTexture(gameOverTex);

                if(!starvationBarTex.loadFromFile("Tekstury\\pasekGlodu.png")) exit(-1);
                starvationBarSpr.setTexture(starvationBarTex);

                starvationBarSpr.setPosition(512,30);
                starvationBarSpr.setOrigin(412,7);
                starvationBarSpr.setScale(1,1);


                // Tworzenie wektow (tablice dynamiczne) ///////////////////////////////////////////////////////////////////////
                vector<Enemy>::const_iterator iter;
                vector<Enemy> enemiesObjectArray;

                vector<Point>::const_iterator iter2;
                vector<Point> fruitPointsArray;


                // Obiekty postaci wrogow punktow i zarzadzanie nimi ///////////////////////////////////////////////////////////
                class Player playerObject;
                playerObject.sprite.setTexture(characterTex);

                class Enemy enemiesObject;
                enemiesObject.sprite.setTexture(enemiesTex);

                Point fruitPoints;
                fruitPoints.sprite.setTexture(FruitTex);
                fruitPoints.rect.setPosition(rand ()% (windowApplication.getSize().x-200) +100,rand ()% (windowApplication.getSize().y-200) +100);
                fruitPointsArray.push_back(fruitPoints);


                //Petla glowna gry pocz¹tek ////////////////////////////////////////////////////////////////////////////////////
                while( windowApplication.isOpen() )
                {
                    //wychwytywanie Zdarzen w grze ////////////////////////////////////////////////////////////////////////////
                    while( windowApplication.pollEvent( eventGame ) )
                    {
                        if( eventGame.type == sf::Event::KeyPressed && eventGame.key.code == sf::Keyboard::Escape )
                        {
                            backMenu= true;
                        }
                        if( eventGame.type == Event::Closed )
                        {
                            windowApplication.close();
                        }
                    }

                    if(backMenu==true) break;

                    // pasek poziomu glodu zarzadzanie /////////////////////////////////////
                    BarStarvationTime=BarStarvationClock.getElapsedTime();
                    if(BarStarvationTime.asSeconds()>0.2)
                    {
                        scaleBarStarvation=scaleBarStarvation - scaleBarStarvationChange;
                        starvationBarSpr.setScale(scaleBarStarvation,1);
                        BarStarvationClock.restart();
                    }


                    // Tablica wrogow zarzadzanie //////////////////////////////////////////
                    EnemiesTimeSpawn=EnemiesSpawnClock.getElapsedTime();
                    if(EnemiesTimeSpawn.asSeconds()>enemiesSpawn)
                    {
                        enemiesObject.rect.setPosition(480,350);
                        enemiesObjectArray.push_back(enemiesObject);
                        EnemiesSpawnClock.restart();
                    }


                    // kolizja gracz przeciwnik ///////////////////////////////////////////
                    enemiesCounter=0;
                    for(iter = enemiesObjectArray.begin(); iter!= enemiesObjectArray.end();iter++)
                    {
                        if(enemiesObjectArray[enemiesCounter].rect.getGlobalBounds().intersects(playerObject.rect.getGlobalBounds()))
                        {
                            playerObject.livesCounter=playerObject.livesCounter-1;
                            playerObject.rect.setPosition(512,700);
                        }
                        enemiesCounter++;
                    }


                    // Tablica punktow kolizja gracz punkt ////////////////////////////////
                    pointsCounter=0;
                    for(iter2= fruitPointsArray.begin(); iter2!= fruitPointsArray.end();iter2++)
                    {
                        if(fruitPointsArray[pointsCounter].rect.getGlobalBounds().intersects(playerObject.rect.getGlobalBounds()))
                        {
                            fruitPoints.LiczbaPunktow=fruitPoints.LiczbaPunktow+1;
                            fruitPointsArray[pointsCounter].ZebranyPunkt=true;
                            if(scaleBarStarvation<=1) scaleBarStarvation=scaleBarStarvation+0.2;
                        }
                        pointsCounter++;
                    }


                    // Tablica punktow zarzadzanie ////////////////////////////////////////
                    pointsCounter=0;
                    for(iter2= fruitPointsArray.begin(); iter2!= fruitPointsArray.end();iter2++)
                    {
                        if(fruitPointsArray[pointsCounter].ZebranyPunkt==true)
                        {
                            fruitPointsArray.erase(fruitPointsArray.begin());
                            fruitPoints.rect.setPosition(rand ()% (windowApplication.getSize().x-200) +100,rand ()% (windowApplication.getSize().y-200) +100);
                            fruitPointsArray.push_back(fruitPoints);
                            fruitPoints.ZebranyPunkt=false;
                            break;
                        }
                        pointsCounter++;
                    }


                    playerObject.update();
                    playerObject.Control();

                    windowApplication.clear();
                    windowApplication.draw(FieldSpr);


                    //////////// Rysuj Przeciwnikow ////////////////////////////////////////////
                    enemiesCounter=0;
                    for(iter = enemiesObjectArray.begin(); iter!= enemiesObjectArray.end();iter++)
                    {
                        enemiesObjectArray[enemiesCounter].update();
                        enemiesObjectArray[enemiesCounter].Control();
                        windowApplication.draw(enemiesObjectArray[enemiesCounter].sprite);
                        enemiesCounter++;
                    }


                    ///////////////////Rysuj punkty ////////////////////////////////////////////
                    pointsCounter=0;
                    for(iter2 = fruitPointsArray.begin(); iter2!= fruitPointsArray.end();iter2++)
                    {
                        fruitPointsArray[pointsCounter].update();
                        windowApplication.draw(fruitPointsArray[pointsCounter].sprite);
                        pointsCounter++;
                    }


                    //////////////////Rysuj Pole ////////////////////////////////////////////
                    windowApplication.draw(playerObject.sprite);
                    windowApplication.draw(fieldBorderSpr);
                    windowApplication.draw(starvationBarSpr);


                    // warunek przezycia ///////////////////////////////////////////////////
                    if(playerObject.livesCounter<=0 || scaleBarStarvation<=0)
                    {
                        windowApplication.draw(GameOverSpr);
                        if(exitClockCounter==0)
                        {
                            exitClock.restart();
                            exitClockCounter++;
                        }
                        exitTime=exitClock.getElapsedTime();
                        if(exitTime.asSeconds()>5.0)
                        {
                            break;
                        }
                    }


                    windowApplication.display();
                }
            }
            if( eventMenu.type == sf::Event::MouseButtonPressed && eventMenu.mouseButton.button == sf::Mouse::Left  &&  MenuExitSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( windowApplication ) ) ))
            {
                windowApplication.close();
            }
            if( eventMenu.type == sf::Event::MouseButtonPressed && eventMenu.mouseButton.button == sf::Mouse::Left  &&  MenuOptionsSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( windowApplication ) ) ))
            {
                bool exitToMenu=false;

                while( windowApplication.isOpen() )
                {
                    while( windowApplication.pollEvent( eventOptions ) )
                    {
                        if( eventOptions.type == sf::Event::MouseButtonPressed && eventOptions.mouseButton.button == sf::Mouse::Left  &&  MenuExitSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( windowApplication ) ) ))
                        {
                            exitToMenu=true;
                        }
                    }

                windowApplication.clear();
                windowApplication.draw(MenuOptionsBackgroundSpr);
                windowApplication.draw(MenuExitSpr);
                windowApplication.display();

                if(exitToMenu==true) break;
                }
            }
            if( eventMenu.type == sf::Event::MouseButtonPressed && eventMenu.mouseButton.button == sf::Mouse::Left  &&  MenuAuthorsSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( windowApplication ) ) ))
            {
                bool exitToMenu=false;

                while( windowApplication.isOpen() )
                {
                    while( windowApplication.pollEvent( eventOptions ) )
                    {
                        if( eventOptions.type == sf::Event::MouseButtonPressed && eventOptions.mouseButton.button == sf::Mouse::Left  &&  MenuExitSpr.getGlobalBounds().contains( sf::Vector2f( sf::Mouse::getPosition( windowApplication ) ) ))
                        {
                            exitToMenu=true;
                        }
                    }

                windowApplication.clear();
                windowApplication.draw(MenuAuthorsBackgroundSpr);
                windowApplication.draw(MenuExitSpr);
                windowApplication.display();

                if(exitToMenu==true) break;
                }
            }
        }

    // Wyswietlenie elementow w oknie aplikacji///////////////////////////////
    windowApplication.setFramerateLimit(60);
    windowApplication.draw(MenuSpr);
    windowApplication.draw(MenuStartSpr);
    windowApplication.draw(MenuOptionsSpr);
    windowApplication.draw(MenuAuthorsSpr);
    windowApplication.draw(MenuExitSpr);
    windowApplication.display();
    }


    return 0;
}
