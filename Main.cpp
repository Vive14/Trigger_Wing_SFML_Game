#include "Game.h"


int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Trigger wing", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);

	Music music;
	music.setVolume(10);
	music.setLoop(true);
	if (!music.openFromFile("sound/Walkure.ogg"))
	{
		return -1;
	}
	music.play();

	srand(time(NULL));
	ScoreBoard s;
	Clock clock;
	float deltaTime = 0;



	Font font, font1;
	font.loadFromFile("Fonts/GAMERIA.ttf");
	font1.loadFromFile("Fonts/upheavtt.ttf");

	// Text button 
	Text buttonPlay("PLAY", font, 68);
	Text buttonScore("SCORE", font, 68);
	Text buttonTutorial("TUTORIAL", font, 68);
	Text buttonQuit("QUIT", font, 68);
	Text backText("<<<", font1, 60); 
	Text ButtonContinue("continue", font, 30.42);
	Text scoreGameOver;
	Text namePlayerGameOver;

	//set Name and Score Show in GameOver
	namePlayerGameOver.setFont(font);
	namePlayerGameOver.setCharacterSize(56);
	namePlayerGameOver.setPosition(252, 434);
	scoreGameOver.setFont(font);
	scoreGameOver.setCharacterSize(56);
	scoreGameOver.setPosition(253, 514);

	//set Button in Game Over
	ButtonContinue.setPosition(232, 613);

	//Button menuStart
	buttonPlay.setPosition(200, 409);
	buttonScore.setPosition(185, 508);
	buttonTutorial.setPosition(150, 621);
	buttonQuit.setPosition(215, 735);
	backText.setPosition(18, 5);

	//set MenuBackground
	RectangleShape background;
	background.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture mainTexture;
	mainTexture.loadFromFile("Textures/bgStart1.png");
	background.setTexture(&mainTexture);

	//set scoreBoard
	RectangleShape scoreBoard;
	scoreBoard.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture scoreBoardTexture;
	scoreBoardTexture.loadFromFile("Textures/Score_Board.png");
	scoreBoard.setTexture(&scoreBoardTexture);

	//set how to play
	RectangleShape btTutorial;
	btTutorial.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture tutorialTexture;
	tutorialTexture.loadFromFile("Textures/how_to_play.png");
	btTutorial.setTexture(&tutorialTexture);

	//set game over
	RectangleShape gameOver;
	gameOver.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	Texture gameOverTexture;
	gameOverTexture.loadFromFile("Textures/bgGame_over.png");
	gameOver.setTexture(&gameOverTexture);
	
	//button Start -> Enter your name
	Text buttonEnterName("START", font, 45);
	buttonEnterName.setPosition(238, 566);

	// set Enter Name
	Texture enterNameTexture;
	RectangleShape enterNamePop;
	enterNamePop.setSize(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)); 
	enterNameTexture.loadFromFile("Textures/EnterName1.png"); 
	enterNamePop.setTexture(&enterNameTexture);

	//Text in Enter name
	Font textBoxFont;
	textBoxFont.loadFromFile("Fonts/Rockstar-ExtraBold.otf");
	Textbox namePlayText(55, Color::White, false);
	namePlayText.setFont(textBoxFont);
	namePlayText.setPosition({ 120, 458 });
	namePlayText.setLimit(true, 9);
	

	while (window.isOpen())
	{
	MENU:
		deltaTime = clock.restart().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

		}
		if (buttonPlay.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			buttonPlay.setFillColor(Color(22, 234, 157, 255)); //สีตัวอักษร 22, 234, 157
			buttonPlay.setOutlineThickness(7); //ขนาดกรอบอักษร
			buttonPlay.setOutlineColor(Color(56, 93, 158, 255)); //สีกรอบ 216, 33, 149, 1
		}
		else if (buttonScore.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			buttonScore.setFillColor(Color(22, 234, 157, 255));
			buttonScore.setOutlineThickness(7);
			buttonScore.setOutlineColor(Color(56, 93, 158, 255));
		}
		else if (buttonTutorial.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			buttonTutorial.setFillColor(Color(22, 234, 157, 255));
			buttonTutorial.setOutlineThickness(7);
			buttonTutorial.setOutlineColor(Color(56, 93, 158, 255));
		}
		else if (buttonQuit.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			buttonQuit.setFillColor(Color(22, 234, 157, 255));
			buttonQuit.setOutlineThickness(7);
			buttonQuit.setOutlineColor(Color(56, 93, 158, 255));
		}
		else
		{
			buttonPlay.setFillColor(Color::White);
			buttonPlay.setOutlineThickness(0);

			buttonScore.setFillColor(Color::White);
			buttonScore.setOutlineThickness(0);

			buttonTutorial.setFillColor(Color::White);
			buttonTutorial.setOutlineThickness(0);

			buttonQuit.setFillColor(Color::White);
			buttonQuit.setOutlineThickness(0);
		}


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			//============================= Play ==================================//
			//=====================================================================//
			if (buttonPlay.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))  //Enter name Befor start
			{
				while (window.isOpen())
				{
					namePlayText.setSelected(true);
					Event enterName1;
					while (window.pollEvent(enterName1))
					{
						if (enterName1.type == Event::TextEntered)
						{
							namePlayText.typedOn(enterName1);
						}

						if (enterName1.type == Event::KeyPressed)
						{
							if (enterName1.key.code == Keyboard::Escape)
							{
								goto MENU;
							}
						}

						if (buttonEnterName.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
						{
							buttonEnterName.setFillColor(Color(255, 160, 55, 255)); 
						}
						else
						{
							buttonEnterName.setFillColor(Color::White);
						}

						//==================================== Enter Name =========================================//
						//=========================================================================================//
						if (buttonEnterName.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left) && namePlayText.getText() != "")
						{
							
							Game game(&window);

							while (window.isOpen())
							{
								Event ev;
								while (window.pollEvent(ev))
								{
								
									if (ev.type == Event::KeyPressed)
									{
										if (ev.key.code == Keyboard::Escape)
										{
											goto MENU;
										}
									}
								}
								game.setName(namePlayText.getText());
								game.Update(deltaTime);
								//============================= Game_over =============================//
								//=====================================================================//
								if (game.checkAlive() == 0)
								{
									namePlayerGameOver.setString(game.getName());
									scoreGameOver.setString(to_string(game.getScore()));
									s.addScore(game.getName(), game.getScore());
									s.uploadFile("score.txt");
									game.reset();

									while (window.isOpen())
									{
										
										if (ButtonContinue.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
										{
											ButtonContinue.setFillColor(Color(255, 160, 55, 255));
										}
										else
										{
											ButtonContinue.setFillColor(Color::White);
										}

										// Game Over Scene
										if (ButtonContinue.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
										{
											goto scoreboard;
										}

										window.clear();

										window.draw(gameOver);
										window.draw(scoreGameOver);
										window.draw(ButtonContinue);
										window.draw(namePlayerGameOver);

										window.display();

									}
								}

								window.clear();

								game.render();

								window.display();

							}

							window.clear();
							
							window.draw(enterNamePop);

							window.display();

						}

						//============================= back_<<< in Button Enter Name =============================//
						//=========================================================================================//
						if (backText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
						{
							backText.setFillColor(Color(228, 223, 163, 255)); 
							backText.setOutlineThickness(5);
							backText.setOutlineColor(Color(237, 20, 91, 255));
						}
						else
						{
							backText.setFillColor(Color::White);
							backText.setOutlineThickness(0);
						}

						if (backText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
						{
							goto MENU;
						}

					}

					window.clear();

					window.draw(enterNamePop);
					window.draw(buttonEnterName);
					window.draw(backText);
					namePlayText.drawTo(window);

					window.display();

				}
		
			}

			//============================= Score ==================================//
			//=====================================================================//
			else if (buttonScore.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{
				while (window.isOpen())
				{
				scoreboard:
					Event scoreEvent;
					while (window.pollEvent(scoreEvent))
					{
						if (scoreEvent.type == Event::KeyPressed)
						{
							if (scoreEvent.key.code == Keyboard::Escape)
							{
								goto MENU;
							}
						}
						//============================= back_<<< in Score =============================//
						//=====================================================================//
						if (backText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
						{
							backText.setFillColor(Color(228, 223, 163, 255));
							backText.setOutlineThickness(5);
							backText.setOutlineColor(Color(237, 20, 91, 255));
						}
						else
						{
							backText.setFillColor(Color::White);
							backText.setOutlineThickness(0);
						}

						if (backText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
						{
							goto MENU;
						}

					}

					s.update();

					window.clear();

					window.draw(scoreBoard);
					window.draw(backText);

					s.render(window);

					window.display();

				}
			}
			//============================= Tutorial =============================//
			//=====================================================================//
			else if (buttonTutorial.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{
				while (window.isOpen())
				{
					Event tutorialEvent;
					while (window.pollEvent(tutorialEvent))
					{
						if (tutorialEvent.type == Event::KeyPressed)
						{
							if (tutorialEvent.key.code == Keyboard::Escape)
							{
								goto MENU;
							}
						}
						//============================= back_<<< in Tutorial =============================//
						//=====================================================================//
						backText.setFillColor(Color::White);
						backText.setOutlineThickness(0);

						if (backText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
						{
							backText.setFillColor(Color(228, 223, 163, 255));
							backText.setOutlineThickness(5);
							backText.setOutlineColor(Color(237, 20, 91, 255));
						}

						if (backText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
						{
							goto MENU;
						}
					}
					window.clear();

					window.draw(btTutorial);
					window.draw(backText);

					window.display();
				}
			}
			//============================= Quit =============================//
			//=====================================================================//
			else if (buttonQuit.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
			{
				window.close();
			}
		}

		window.clear();

		window.draw(background);
		window.draw(buttonPlay);
		window.draw(buttonScore);
		window.draw(buttonTutorial);
		window.draw(buttonQuit);

		window.display();
	}

	return 0;
}