#include "Story.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <limits>
#include <vector>
#include "DelayedText.h"
#include "WaiZhengRNG.h"
#include "WaiZhengClock.h"
#include "Player.h"
#include "WayneCure.h"
#include "WaynePos.h"
#include "WayneEnemy.h"
#include "WayneGO.h"
#include "WayneKey.h"
#include "WayneWeapon.h"
#include "EzenRLGL.h"
#include "HuiEnCheck.h"
#include "HuiEnIT.h"
#include "HuiEnRS.h"
#include <windows.h>
#include <conio.h>
std::string input;
std::chrono::milliseconds delay(0);
bool dogkey = false;
bool greenkey = false;
const std::string RED_TEXT = "\033[31m";
const std::string RESET_COLOR = "\033[0m";
bool timeExpired = false;
bool held = false;
float timeheld = 0.0;
CPlayer* AustinPtr;
WayneEnemy* CreaturePtr;
std::chrono::steady_clock::time_point pressStart; 
void ClosetStealth();
void BedStealth();
void StartStealth();
const int growltrigger = 4;
const int min = 1;
const int max = 10;
std::string playermove;
int playerposition = 0;
bool waking = false;
bool awakedeath = false;
bool LRClear = false;
bool BedClear = false;
bool KitClear = false;
void ignoreInputUntilNewline() {
	HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
	DWORD dwRead;
	char ch;

	while (true) {
		ReadConsole(hConsole, &ch, 1, &dwRead, NULL);
		if (ch == '\n') {
			break;
		}
	}
}
int TimeRanOut()
{
	clearScreen();
	std::string TRO1 = "You took too long to make a choice, the voices are now gone.\nDarkness envelops you once more.Close.Not close enough.\nIndecisive Ending Achieved.";
	printWithDelay(TRO1, delay);

	system("pause");
	ignoreInputUntilNewline();
	std::exit(0);

	return 0;
}

void TimeMonitor(WaiZhengClock* clockPtr)
{
	while (!timeExpired) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Check every 100 ms
		if (clockPtr->getElapsed() > 10000) {
			clockPtr->Reset();
			clockPtr->Stop();
			break;
		}
	}
	if (clockPtr->getElapsed() > 10000) {


		timeExpired = true; // Signal that time has expired
	}
}

void printImageWithDelay(const char* image, int milliseconds) {
	std::cout << image << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
int Story::StartAct()
{
	const char* park = R"(

                %%%;       *                      *
   |  %%%;     %%%~%%%;               .                     .     *
 # |__/__%%%____/_/~%;%                           .
     ___%%;______%%;%          .            *            *
" " /~ %-//  \ \__%#%%_-%%;`
   |  ~%-/_%` \ \_/%%#%%`                                            .
#  | %%%#%     \__/%%#%%;%`,
  "| ;%%%;`                              *                  .
   |                            *                  (
| #|            *        .                                          .
  ||         .                        . .        .
   |                .                ` ' `               *
#  |                             .'''. ' .'''.                   *
  "|  *           .                .. ' ' ..      .
'  |                         *    '  '.'.'  '              .
   |                              .'''.'.'''.
 " |       .----------.          ' .''.'.''. '
   |       |__________|            . . : . .
   |_{}_{}/|__________|\{}_{}_{} _'___':'___'_ {}_{}_{}_{}_{}_{}_{}_{}
' #| || ||/____________\|| || ||(_____________)|| || || || || || || ||
'''\''''''||          ||''''''''''''(     )'''''''''''''''''''''''''''
'''''     |            |            _)   (_             .^-^.  ~''~
                         ~''~      (_______)~~'''~~     '._.'
    ~~''~~                     ~''~                     .' '.
                                                        '.,.'
                                                           `'`'

)";

	std::cout << park << std::endl;
	std::string message = "Coldness. It rushes through you like a ghost. Your surroundings start to warp, and distort. \nUnfamiliar scenery of a park you know not the name of surrounds you. \nWith only the winds of the cold night to keep you company.";

	printWithDelay(message, delay);

system("pause");


	clearScreen();

	std::string message2 = "You can't help but feel something is off, like someone is close. Footsteps. \nYou swivel your head in a panic, too late. Before you could react, darkness envelops you. \nFeeling lethargic, you leave your life in the hands of fate, accepting whatever is to come as you doze off.";

	printWithDelay(message2, delay);

	system("pause");


	clearScreen();
	
	Act1();
	return 0;
}
int Story::Act1()
{
	bool result = true;
	bool KeyisFound = false;
	bool firstkeyFound = false;
	std::string message3 = "You wake up. Eyes needing time to adjust to the darkness. \nYou listen closely and hear the subtle trickling of water through the walls a few rooms away, \nIts echoes booming throughout the room. \nThe air reeks with a hurl-inducing stench. Your eyes adjust, you wish they hadn't. \nChipped paint, moss, cracks and crevices. \nThey litter the walls, almost as much as the stench in the air.";

	printWithDelay(message3, delay);

	system("pause");


	clearScreen();
	const char* StartRoom = R"(
	                                            
                                                                                
                                                                                
                           ########################                             
                           #                      #                             
                           #                      #                             
                           #                      #        .@@@@@@@@@@@@@.      
###############            #                      #       #               #     
          #-@-             #                      #      +-                #    
      .@ ####              #                      #     #@@@@@@@@@@@@@@@@@@@@   
   ## #    ##              #                      #     #         #         #   
%* %*      ##              #                      #     #         #         #   
 #         ##              #                      #     #         #         #   
           ##              #                      #     #         #         #   
###############            #                 # #  #     #         #         #   
           #.##            #                #   # #     #         #         #   
          #.@              #                 # #  #     #         #         #   
        ==###              #                      #     #         #         #   
      #.#  ##              #                      #     #      ## # ##      #   
    #.#    ##              #                      #     #      ## # ##      #   
  ++-+     ##              #                      #     #      ## # ##      #   
# .#       ##              #                      #     #         #         #   
 #         ##              #                      #     #         #         #   
##############=============@######################%=====#         #         #===
           ## #                                         #         #         #   
           ## #                                         #         #         #   
          :*#                                           #:::::::::#:::::::::%   
         ##                                                                     
      # %.                                                                      
    .*.#                                                                        
   # #                                                                          
 * #                                                                            
)";

	std::cout << StartRoom << std::endl;
	std::string message4 = "As you take in the atmosphere of the dark, dreary, dreadful room you're in, you try to get up. Futility. \nChained to the chair, your mobility is limited. \nYour eyes dart around to find something that could help, even just a little bit. \nOn your left, and quite a distance away, a rusted penknife. \nTime is short, you hear footsteps.";

	printWithDelay(message4, delay);

	WaiZhengClock* ClockPtr = new WaiZhengClock();
	ClockPtr->Start();

	// Start the time monitoring thread
	std::thread monitorThread(TimeMonitor, ClockPtr);

	if (!timeExpired)
	{
		while (true) {
			
			std::cout << "\n\n'move' or 'wait'\n\n";
			std::cin >> input;

			if (input == "move" || input == "wait") {
				break; // Exit the loop if input is correct
			}

			clearScreen();
			std::cout << "\n\nTry spelling 'move' or 'wait' correctly.\n\n";
		}
	}


Input:
	
	ClockPtr->Stop();
	while (!timeExpired)
	{
		if (input == "wait")
		{
			WaitEnd();
		}
		else if (input == "move")
		{
			clearScreen();

			std::string moving1 = "You drag your chair towards the knife, trying to make as much distance as possible with every motion. \nYou're close, not close enough.";

			printWithDelay(moving1, delay);

			std::cout << "\n\n'move' or 'wait'\n\n";

			std::cin >> input;

			while (input != "move" && input != "wait") {
				clearScreen();
				std::cout << "\n\nPlease spell 'move' or 'wait' correctly:\n\n";
				std::cin >> input;
			}
			if (input == "move")
			{
				clearScreen();

				std::string moving2 = "You make one last effort, and heave your chair to the penknife, toppling the chair and leaving the penknife within your grasp. \nYou cut your wrists and ankles free and find a place to scuttle away, hoping to stay hidden.";

				printWithDelay(moving2, delay);

				

				system("pause");


				clearScreen();

				std::string moving3 = "The door creaks open as the heavy footsteps settle in. Each step shakes the ground, disrupting the rhythm of your heart.\nYou hold your breath in hopes of not being found. ";

				printWithDelay(moving3, delay);
				system("pause");
				//stealth here
				clearScreen();

				const char* hideStart = R"(

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  -------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@------------------------------@@@@@@@ /       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|   X    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|   X    @@@@@@--------------------@@@
@@------------------------------@@@@@@@@@ \       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ __\_____@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/        @@@@--------------------@@@@@@
@@@------------------------------@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@--------------------@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@------------------------------@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@-------------------@@@@@@
@@@------------------------------@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


)";

				std::cout << hideStart << std::endl;

				std::cout << "\n\nHold H to Hide!";
				StartStealth();
				
			

			}

		}
		std::string message5 = "As the door creaks close, you slink your way past it, being careful not to make a sound. \nYou make your way through the house, door by door. The estate seemingly warps with every decision you make, losing you in its boundless possibilities. \nYou find your way to the front door, locked. Windows, locked. You'll have to find another way out.";
		printWithDelay(message5, delay);

		system("pause");

		clearScreen();

		std::string Choice = "Hmm, Where to go First?";
		printWithDelay(Choice, delay);

		std::cout << "\n\n'Bedroom' or 'Lounge' or 'Kitchen'\n\n";
		std::cin >> input;



		if (input == "Lounge" || input == "lounge")
		{
			Lounge(result, KeyisFound, firstkeyFound);
		}
		if (input == "Bedroom" || input == "bedroom")
		{
			Bedroom(result, KeyisFound, firstkeyFound);
		}
		if (input == "Kitchen" || input == "kitchen")
		{
			Kitchen(result, KeyisFound, firstkeyFound);
		}


	}
	
	if(timeExpired)
	{
		TimeRanOut();

	}
		return 0;
	}

int Story::ContAct1()
	{
	while (!timeExpired)
	{
		clearScreen();
		std::string message6 = "Looks like the key to the front door. Only one thing left to do.";

		printWithDelay(message6, delay);

		system("pause");
		clearScreen();

		std::string message7 = "As you make your way to the front door, you feel freedom creeping ever closer. \nYou can't tell whether it's adrenaline or excitement that fills you. You turn the corner, wary as ever, \nonly to see the being that you so narrowly escaped from, guarding the door.";
		printWithDelay(message7, delay);

		system("pause");
		WaiZhengClock* ClockPtr = new WaiZhengClock();
		ClockPtr->Start();
		std::thread monitorThread(TimeMonitor, ClockPtr);
		if (!timeExpired)
		{
			while (true) {
				clearScreen();
				std::cout << "\n\n'fight' or 'flee'\n\n";
				std::cin >> input;
				
				if (input == "fight" || input == "flee") {
					break; // Exit the loop if input is correct
				}

				clearScreen();
				std::cout << "\n\nTry spelling 'fight' or 'flee' correctly.\n\n";
				
			}

		}

		clearScreen();

		ClockPtr->Stop();
		//fight or flee decision

		//Wayne Code
		if (!timeExpired)
		{
			if (input == "fight")
			{
				const char* stab = R"(

                                           ___       
                                         -/   \--___________
                                 _------_-\    \_|__________\      
                                /        \ \    |                            
                               |         |  |   |                             
                               |         |  |   |                            
                               \       __/  |   |                            
                                \   __|____/    /
                                |              /               
                                |    _________/                             
                                |     |                                    
                                |     |                                      
                                |     |
                                |     |
                                |     |
                                 \__   \         
   __                               \   \                                     
  |  \             ___        _______\   \________       _________
  |   \___________ |  ---___ /        \   \       \_____/     XX  \                                          
  |                |        ----------     \                      |           
  |________________|__|\____________________|_____________________/



)";

				std::cout << stab << std::endl;
				std::string fight1 = "You choose to confront the being, you will be afraid of them no longer. \nYou take a final stand, it's kill or be killed. \nAs it reaches out for you, you plunge your blade into their chest, staggering them. \nYou push with all your might, tackling them to the ground, driving the blade further in.";
				printWithDelay(fight1, delay);
				ignoreInputUntilNewline();
				system("pause");

				clearScreen();

				const char* STABBB = R"(

  
                                             _________
                                      .------/         \
                                   _./                 |
                                  /      |   |_        |
                                 /     ./|   | \_______/
                                /     /  |   |__---                            
                                |     |  \         \
                                 \__   \  ------___|  
   __                               \   \       |  |                            
  |  \             ___        _______\   \______|_ |     _________
  |   \____________|  ---___ /        \   \       \|____/     XX  \                                          
  |                |        ----------     \                      |           
  |________________|__|\____________________|_____________________/



)";

				std::cout << STABBB << std::endl;
				std::string fight2 = "you twist the blade while it's in their chest, ignoring the eldritch cries coming from it and pull out your blade while shovelling at their guts. \nTangy intestines get dragged along with the blade, some severing before being fully pulled out. \nThey reach out, trying to grab you.";
				printWithDelay(fight2, delay);
				system("pause");


				clearScreen();

				printImageWithDelay(stab, 1000);
				// Wait for 2 seconds before clearing the screen or showing the next image
				std::this_thread::sleep_for(std::chrono::seconds(1));

				clearScreen();

				printImageWithDelay(STABBB, 1000);

				std::string fight3 = "You plunge your blade into their heart. With more accuracy this time. \nAgain. Again. Each time with more ferocity than the last. \nYou will be held captive" + RED_TEXT + " no more." + RESET_COLOR + "You " + RED_TEXT + "will" + RESET_COLOR + " be free.";
				printWithDelay(fight3, delay);

				system("pause");


				clearScreen();

				printImageWithDelay(stab, 1000);

				// Wait for 2 seconds before clearing the screen or showing the next image
				std::this_thread::sleep_for(std::chrono::seconds(1));


				clearScreen();

				printImageWithDelay(STABBB, 1000);

				std::string fight4 = "With the blade left plunged into their chest, blood spurting and spilling out, you release the blade, hands shaking. \nYour vision starts to blur, reality starts to shift. \nIt's trying to " + RED_TEXT + "deceive" + RESET_COLOR + " you. Don't " + RED_TEXT + "trust" + RESET_COLOR + " it. You " + RED_TEXT + "will " + RESET_COLOR + "be free";
				printWithDelay(fight4, delay);

				system("pause");


				clearScreen();

				ClockPtr->Start();

				std::string fight5 = "You did it. You're no longer afraid." + RED_TEXT + " What's next?" + RESET_COLOR;
				printWithDelay(fight5, delay);

				while (true) {
					clearScreen();
					std::cout << "\n\n" + RED_TEXT + "'murder'" + RESET_COLOR + " or 'escape'\n\n";
					std::cin >> input;

					clearScreen();

					if (input == "murder" || input == "escape") {
						break; // Exit the loop if input is correct
					}

					clearScreen();
					std::cout << "\n\nTry spelling 'murder' or 'escape' correctly.\n\n";
				}

				ClockPtr->Stop();
				ClockPtr->Reset();
				if (input == "murder") {
					clearScreen();
					std::string kill1 = "You decide that you'll kill the rest, for you are no longer afraid.\n " + RED_TEXT + "I like that. Go on then, do what you must." + RESET_COLOR + "";
					printWithDelay(kill1, delay);

					system("pause");


					clearScreen();

					std::string kill2 = "As the voice disappears, your head rises to scan the environment, covered in the creature's blood.\n Sure Enough, you see more and more grotesque creatures approaching you.\nSome with faces that resemble horror, others resembling anger, you can't quite make it out.\nEven new creatures you've never seen before. Crawling on the floor lies a ball of rotting meat with serrated teeth growling at you.";
					printWithDelay(kill2, delay);

					system("pause");


					clearScreen();

					std::string kill3 = "You flinch back, but " + RED_TEXT + "remember.\nThey are mortal, they can be killed. Don't be afraid.\nAttack!" + RESET_COLOR + "";
					printWithDelay(kill3, delay);
					std::cout << "\n\n" + RED_TEXT + "Attack!\n\n" + RESET_COLOR + "";
					std::cin >> input;

					clearScreen();
					if (input == "Attack" || input == "attack")
					{
						std::string kill4 = "Having no choice but to follow the voice, you attack and attack and attack. Hearing the cries and what sounds like eldritch gibberish.\nYou can't help but feel that they're asking, pleading you for something.\n" + RED_TEXT + "You shouldn't stop now, you've come so far!" + RESET_COLOR + "";
						printWithDelay(kill4, delay);
						ignoreInputUntilNewline();
						AttackArt();
						std::cout << "\n\n" + RED_TEXT + "Attack!\n\n" + RESET_COLOR + "";
						std::cin >> input;

						clearScreen();
						if (input == "Attack" || input == "attack") {
							std::string kill5 = "Kill! Kill! Kill!\nDon't you dare stop. More are on the way. Don't Stop. \nYou don't want to lose your freedom again do you?\nListen to Me. Kill them All.";

							std::cout << RED_TEXT;
							printWithDelay(kill5, delay);
							std::cout << RESET_COLOR;
							ignoreInputUntilNewline();
							AttackArt();
							std::cout << "\n\n" + RED_TEXT + "Attack!\n\n" + RESET_COLOR + "";
							std::cin >> input;

							clearScreen();

							std::string kill6 = "As you keep on killing, soon the cries stop. Leaving you all alone covered in the blood of the creatures.\nAs you look at the corpses, your vision starts to clear bit by bit revealing the truth of your actions.\nAs you stare at what you've done, your vision regains its blurriness.";
							printWithDelay(kill6, delay);
							ignoreInputUntilNewline();
							system("pause");


							clearScreen();
						}


					}
					std::string kill7 = "Don't think about them. They're just deadweight. They don't understand our suffering.\nThey only want to separate us. You don't want that.  We're free now.\nCome on, let's get going. More will come if we don't leave.";

					std::cout << RED_TEXT;
					printWithDelay(kill7, delay);
					std::cout << RESET_COLOR;

					system("pause");


					clearScreen();

					std::string kill8 = "Listening to the voice, you make your way out of the nightmare. Finally being free, you make your way back to your safe haven.\nAs you're walking, covered in blood. You hear more and more screams of terror all around you.\n" + RED_TEXT + "Kill them. They won't seperate us. We're in this together.\nI promise I will keep us safe. We're partners. Give me Control." + RESET_COLOR + "";
					printWithDelay(kill8, delay);

					ClockPtr->Start();

					std::cout << "\n\n'surrender' or 'resist'\n\n";

					std::cin >> input;

					ignoreInputUntilNewline();

					clearScreen();

					ClockPtr->Stop();
					ClockPtr->Reset();
					if (input == "surrender") {
						SurrenderEnd();
					}

					if (input == "resist") {
						resistEnd();
					}
				}
				else if (input == "escape") {

					EscapeEnd();
				}
			}
			else if (input == "flee") {

				std::string flee1 = "You turn back, choosing to run. Your foot lands on a creaky floorboard. \nIt hears you. Run. \nyou make a mad dash through the seemingly never ending corridors.";

				printWithDelay(flee1, delay);

				ClockPtr->Start();

				std::cout << "\n\n'straight' or 'right'\n\n";

				std::cin >> input;

				clearScreen();

				ClockPtr->Stop();
				ClockPtr->Reset();
				if (input == "straight") {
					std::string straight1 = "You choose to run as fast as possible, but it seems as though you aren't making any distance. \nYou look back and see the being closing the gap. \nIt's futile. It catches up to you, you've lost. \nDarkness envelops you once more. Close. Not close enough.";

					printWithDelay(straight1, delay);

					ignoreInputUntilNewline();
					system("pause");



					clearScreen();

					Act1();
				}
				else if (input == "right") {
					std::string flee2 = "You take the next turn you find, into a room. \nFootsteps trail closely behind. Hide.";

					printWithDelay(flee2, delay);

					ClockPtr->Start();

					std::cout << "\n\n'bathroom' or 'bed' or 'closet'\n\n";

					std::cin >> input;

					clearScreen();

					ClockPtr->Stop();
					if (input == "bathroom") {
						std::string right1 = "You slink into the bathroom, closing the door behind you as silently as possible.";

						printWithDelay(right1, delay);
						ignoreInputUntilNewline();
						system("pause");



						clearScreen();

						const char* hidetoilet = R"(

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-----------@@@@@@@@@@@%%%%%%%%%%%%%%%%%%%@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/     X     \@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/     / \     \@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|    /   \    |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|   /  |  \   |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\   \  |  /   /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\   \   /   /@%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\   \ /   /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@%%%%%%%%%%%%%%%%%%%@@@@@@@@|   X   |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|       |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|       |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|       |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|_______|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



)";

						std::cout << hidetoilet << std::endl;

						std::string right2 = "The door opens, an eye looks through the keyhole. You've been caught.";

						printWithDelay(right2, delay);

						system("pause");



						clearScreen();

						std::string right3 = "The door bursts open and knocks you out cold. \nDarkness envelops you once more. Close. Not close enough.";

						printWithDelay(right3, delay);
						ignoreInputUntilNewline();
						system("pause");



						clearScreen();

						Act1();
					}

					if (input == "bed") {
						std::string bed1 = "You slide under the bed, holding your breath. This seems oddly familiar…";

						printWithDelay(bed1, delay);

						system("pause");



						clearScreen();

						std::string bed2 = "The being steps into the room hurriedly, the frantic footsteps getting closer by the second.";

						printWithDelay(bed2, delay);

						system("pause");



						clearScreen();

						std::cout << "\n\nHold H to Hide!";

						const char* hidebed = R"(

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@---------@@@@@@@@@@@
@@@@@@@-------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@--------@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@----------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@------@@@@@@@@@@@@@@@@@@@@@@-----@@@@@@@@@@@
@@@@@@@@@@@@ @@@@@@@@@@|    @@@@@@@@@@@@@@@@|@ @    @@@@@@@@@@@@@@@     @@@@@@@
@                      |      |      |      |                                 @
@                      |      |      |      |                                 @
@                      |      |      |      |                                 @
@                      |      |      |      |                                 @
@                     /       |      |      \                                 @
@                ____/        |      |       \                                @
@               /             |      |        |                               @
@    @@@@@@@@@@@@@___________@@@@@@  |________|     @@@@@@@           @@@@@@@ @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


)";
						std::cout << hidebed << std::endl;
						//stealth
						BedStealth();


					}

					if (input == "closet") {
						std::string closet1 = "You shut yourself into the closet as darkness shrouds you, you blend in with the dark spaces. \nThe being runs into the room. Briefly scanning the room. His panic comes to a stop, scanning the room again, more thoroughly this time.";

						printWithDelay(closet1, delay);

						system("pause");



						clearScreen();
						const char* hidecloset = R"(

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  -------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@------------------------------@@@@@@@ /       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|   X    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|   X    @@@@@@--------------------@@@
@@------------------------------@@@@@@@@@ \       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ __\_____@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/        @@@@--------------------@@@@@@
@@@------------------------------@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@--------------------@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@------------------------------@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@-------------------@@@@@@
@@@------------------------------@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


)";

						std::cout << hidecloset << std::endl;

						std::cout << "\n\nHold H to Hide!";

						//stealth
						ClosetStealth();

					}

					std::string door1 = "The door is no longer guarded. You're homefree. You make your way to the door, unlocking it. \nThe light that was thought to be freedom, snuffed out. There's another door left. \nYou focus into the lock, noticing it requires 2 keys. This won't be easy, but it can be done. \n" + RED_TEXT + "You can escape." + RESET_COLOR + "";

					printWithDelay(door1, delay);
					const char* gate = R"(
                                 {} {}
                         !  !  ! II II !  !  !
                      !  I__I__I_II II_I__I__I  !
                      I_/|__|__|_|| ||_|__|__|\_I
                   ! /|_/|  |  | || || |  |  |\_|\ !       
       .--.        I//|  |  |  | || || |  |  |  |\\I        .--.
      /-   \    ! /|/ |  |  |  | || || |  |  |  | \|\ !    /=   \
      \=__ /    I//|  |  |  |  | || || |  |  |  |  |\\I    \-__ /
       }  {  ! /|/ |  |  |  |  | || || |  |  |  |  | \|\ !  }  {
      {____} I//|  |  |  |  |  | || || |  |  |  |  |  |\\I {____}
_!__!__|= |=/|/ |  |  |  |  |  | || || |  |  |  |  |  | \|\=|  |__!__!_
_I__I__|  ||/|__|__|__|__|__|__|_|| ||_|__|__|__|__|__|__|\||- |__I__I_
-|--|--|- ||-|--|--|--|--|--|--|-|| ||-|--|--|--|--|--|--|-||= |--|--|-
 |  |  |  || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||  |  |  |
 |  |  |= || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||= |  |  |
 |  |  |- || |  |  |  |  |  |  | O| |O |  |  |  |  |  |  | ||= |  |  |
 |  |  |- || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||- |  |  | 
_|__|__|  ||_|__|__|__|__|__|__|_|| ||_|__|__|__|__|__|__|_||  |__|__|_
-|--|--|= ||-|--|--|--|--|--|--|-|| ||-|--|--|--|--|--|--|-||= |--|--|-
-|--|--|| |  |  |  |  |  |  |  | || || |  |  |  |  |  |  |  |- |--|--|- 
~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~~~~~~~~~~)";

					std::cout << gate << std::endl;
					system("pause");



					clearScreen();
					Act2();

					return 0;
				}
			}
		}
	}
		if (timeExpired)
		{
			TimeRanOut();
		}
	}


int Story::Act2()
{
	std::set<int> randomNumbers;
	EzenRLGL* RLGLPtr = new EzenRLGL;
	RLGLPtr->updateRandomNumbers(randomNumbers, min, max, growltrigger);
	std::string yard1 = "The front yard and backyard are now open to you, and you are open to whatever is out there. there is much more to explore, press on.";

	printWithDelay(yard1, delay);

	system("pause");


	clearScreen();

	const char* doge = R"(

                            __________________   
                         __/                  \__
        ________________/                        \________________
       /                                                          \
      /                                                            \
     /__________________________________________     _______________\
    |                                           \                   |
    |      \                      ____           \                  |
    |       \ \                   |__|                              |
    |        \ \ \                 ||                               |
    |         \ \ \               =||                               |
    |          \ \ \                                             /  |
    |             \ \                                         / /   |
    |                \                                     / / /    |
    |                                                     / / /     |
    |                 __________________________         / / /      |
    |        \ \     /                          \         / /       |
    |         \ \ \ /                            \         /        |
    |          \ \ /                              \                 |
    |           \ /                                \                |
    |            |               x       O          |       |       |
    |            |                                  |     | |       |
    |            |             O           x        |     | | |     |
    |            |                                  |     | | |     |
    |            |                                  |       |       |
    |____________|__________________________________|_______________|



)";

	std::cout << doge << std::endl;

	const char* plants = R"(

_____________________________________________________________________
|____________________________________________________________________|
|__||        ||___||        |_|___|___|__|        ||___||        ||__|
||__|        |__|__|        |___|___|___||        |__|__|        |__||
|__||        ||___||        |_|___|___|__|        ||___||        ||__|
||__|        |__|__|        |    || |    |        |__|__|        |__||
|__||        ||___||        |    || |    |        ||___||        ||__|
||__|        |__|__|        |    || |    |        |__|__|   __   |__||
|__||        ||___||        |    || |    |        ||___||  |__|  ||__|
||__|        |__|__|        |    || |    |        |__|__|   ||   |__||
|__||        ||___||        |   O|| |O   |        ||___||  =||   ||__|
||__|        |__|__|        |    || |    |        |__|__|        |__||
|__||        ||___||        |    || |    |        ||___||        ||__|
||__|        |__|__|      __|____||_|____|        |__|__|        |__||
|LLL|        |LLLLL|    _|______________||        |LLLLL|        |LLL|
|LLL|        |LLLLL|  _|______________|  |        |LLLLL|        |LLL|
|LLL|________|LLLLL| |______________|____|________|LLLLL|________|LLL|


)";

	std::cout << plants << std::endl;

	std::string yard2 = "You see a doghouse on the left, a greenhouse on the right. Your choice.";

	printWithDelay(yard2, delay);
	std::cout << "\n\n'doghouse' or 'greenhouse'\n\n";

	std::cin >> input;

	clearScreen();
	if (dogkey == false && greenkey == false)
	{
		if (input == "doghouse") {
			DogRLGL();
		}

		else if (input == "greenhouse")
		{
			GardRLGL();
		}
	}


	return 0;
}

void Story::SetPlayer()
{
	AustinPtr->setSanity(200);
	AustinPtr->setAttack(10);
	
}

void Story::SetCreature()
{
	CreaturePtr->setENHP(10);
}

void Story::EncounterHUD()
{
	std::cout << "| " "Austin "                    "| Enemy: Creature\n";
	std::cout << "| Health: " << AustinPtr->getSanity() << "            | Health: " << CreaturePtr->getENHP() << std::endl;
	std::cout << "| Damage: " << AustinPtr->getAttack() << std::endl;
	std::cout << "---------------------------------------------------------------\n";
}

void Story::Act1Battle()
{
	std::string command;
	EncounterHUD();

	while (CreaturePtr->getENHP() > 0)
	{
		std::cout << "Type: \n";
		std::cout << "'attack' to attack the enemy.\n";

		while (command != "attack")
		{
			std::cout << ">";
			std::getline(std::cin, command);
		}
		if (command == "attack")
		{
			
		}
	}
}

void Story::WaitEnd()
{
	while (true)
	{
		clearScreen();

		std::string waiting1 = "You can hear the footsteps get louder as time passes. ";

		printWithDelay(waiting1, delay);

		std::cout << "\n\n'wait'\n\n";

		std::cin >> input;

		if (input == "move") {
			clearScreen();
			std::string TryToMove = "You chose to Wait, You're stuck now waiting";
			printWithDelay(TryToMove, delay);
			system("pause");
			continue;
		}
		if (input == "wait")
		{
			clearScreen();

			std::string waiting2 = "the footsteps get even louder. Are you sure this is a wise idea?";

			printWithDelay(waiting2, delay);

			std::cout << "\n\n'wait'\n\n";

			std::cin >> input;

			if (input == "wait")
			{
				clearScreen();

				std::string waiting3 = "you should make a move, now.";

				printWithDelay(waiting3, delay);

				std::cout << "\n\n'wait'\n\n";

				std::cin >> input;


				if (input == "wait")
				{
					clearScreen();

					std::string waiting4 = "Why are you waiting! Move! Now!";

					printWithDelay(waiting4, delay);

					std::cout << "\n\n'wait'\n\n";

					std::cin >> input;


					if (input == "wait")
					{
						clearScreen();

						std::string waiting5 = "NO! THIS ISN'T HOW IT'S SUPPOSED TO BE. I WON'T DISAPPEAR. I WON'T-";

						std::cout << RED_TEXT;
						printWithDelay(waiting5, delay);
						std::cout << RESET_COLOR;


						clearScreen();

						std::string waiting6 = "As the captor forces an unknown substance into your mouth, you close your eyes expecting the worst. \nYou open your eyes, the darkness clears, your vision sharpens and the form of your parents starts to form. \nThe silence has never felt so welcoming. You're safe. You're home.";

						printWithDelay(waiting6, delay);
						ignoreInputUntilNewline();

						system("pause");


						clearScreen();

						std::string waiting7 = "Wait Ending Achieved.";

						printWithDelay(waiting7, delay);

						system("pause");
						exit(0);
					}
				}
			}
	}
	
	}
}

void Story::resistEnd()
{
	std::string resist1 = "" + RED_TEXT + "Be like that then. See for yourself how long you can survive without me. " + RESET_COLOR + "The voices then stop.\nIt's silent for the first time in a long while, it's just me. \nThe deafening silence continues, my vision returns back to normal and I see what were the monsters surrounding me, the neighbours terrified as they call the police.";
	printWithDelay(resist1, delay);

	system("pause");



	clearScreen();



	std::string resist2 = "Within minutes, the police arrive. Approaching me covered in human blood, they walk slowly towards me, wary of the danger I might pose. \nSeeing that I wasn't a threat to them, they rushed forward. Tackling me down and detaining me before I could react.";
	printWithDelay(resist2, delay);

	system("pause");



	clearScreen();

	std::string resist3 = "Next thing I know, I'm locked up in a dark empty cell. \nNo light came through except for the holes in the iron door in front of me. \nI found myself  tied up and unable to move a single part of my body.";
	printWithDelay(resist3, delay);

	system("pause");



	clearScreen();

	std::string resist4 = "See what I told you Austin? Now look at us. Trapped, unable to move. This is all your fault. \nYou could have just given me control but now? Now it's too late to even bother anymore. \nHave fun being alone, Austin.";
	std::cout << RED_TEXT;
	printWithDelay(resist4, delay);
	std::cout << RESET_COLOR;

	system("pause");



	clearScreen();

	std::string resist5 = "My consciousness begins to fade while trying to keep myself from dozing off. \nI wonder, was it really the right decision? To remain in control. \nIt's my own body... isn't it?";
	printWithDelay(resist5, delay);

	system("pause");



	clearScreen();
	const char* pain = R"(

________________________________________________________________________________
|@@@@\                               *****                                /@@@@|
|@@@@@\                               ***                                /@@@@@|
|@@@@@|\                                                                /|@@@@@|
|@@@@@|@@\                                                            /@@|@@@@@|
|@@@@@|@@@\                                                          /@@@|@@@@@|
|@@@@@|@@@@\________________________________________________________/@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@|@@@@@@@@@@@@@@@@@@ ____ @@@@@@@@@@@@@@@@@@|@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@|@@@@@@@@@@@@@@@@@ /    \ @@@@@@@@@@@@@@@@@|@@@@@|@@@@@|@@@@@|
|-----+-----+-----+------------------|    |------------------+-----+-----+-----|
|@@@@@|@@@@@|@@@@@|@@@@@@@@@@@@@@@ ___\__/___ @@@@@@@@@@@@@@@|@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@|@@@@@@@@@@@@@@ /          \ @@@@@@@@@@@@@@|@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@|@@@@@@@@@@@@@.-| |      | |-.@@@@@@@@@@@@@|@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@|_____________|_| |      | |_|_____________|@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@@@@@@@@@@@@@@@|_|_\      /_|_|@@@@@@@@@@@@@@@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|@@@@@@@@@@@@@@@@@@/|___|______|___|\@@@@@@@@@@@@@@@@@@|@@@@@|@@@@@|
|@@@@@|@@@@@|__________________/___/   /\   \___\__________________|@@@@@|@@@@@|
|@@@@@|@@@@/@@@@@@@@@@@@@@@@@@@||@|   |@@|   |@||@@@@@@@@@@@@@@@@@@@\@@@@|@@@@@|
|@@@@@|@@@/@@@@@@@@@@@@@@@@@@@@|@@|   |@@|   |@@|@@@@@@@@@@@@@@@@@@@@\@@@|@@@@@|
|@@@@@|___________________________|___|__|___|___________________________|@@@@@|
|@@@@/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\@@@@|
|@@@/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\@@@|
|__/________________________________________________________________________\__|


)";

	std::cout << pain << std::endl;
	std::string resist6 = "Alone Ending Achieved.";
	printWithDelay(resist6, delay);

	system("pause");



	clearScreen();
	exit(0);
}

void Story::SurrenderEnd()
{
	std::string surrender1 = "Ahhhhh. Finally, Some freedom. Don't worry. I'll take care of them.\nI will protect you. Get some rest, you won't feel our pain ever again.";
	std::cout << RED_TEXT;
	printWithDelay(surrender1, delay);

	system("pause");



	clearScreen();

	std::string surrender2 = "As Austin falls to his slumber. I deal with our problems, finally free.\nNo one will stop us anymore. You're safe Austin. Safe with me.";
	printWithDelay(surrender2, delay);

	system("pause");



	clearScreen();
	std::cout << RESET_COLOR;
	const char* murder = R"(

 (              ````                         )                )              
;`             ;;                             ;              ,;    
 ;;  -""-.   ;;                 -;'  -.      (             ;;      
   ""     ``                      `.   `.     ;;;,,''--,,;;                  
                                    ;    `                      
           `;                  -          ;         -.        ;`
             `-  `.         .'`  .-'             .--`  ;     ;  
              ;    `-.   ;    `-'             .;`     ;       `.
              .        ``                                       
               `            .--------.             .'           
             ...        .--'``````````'--.        ;.            
            `      . .-' .``          ``. '-. .      `.         
          ;-.;  .  .' .`                  `. '.  .    ;         
              .' .' .`                      `. '. '.    .       
_____/'.-.._______________________________________________________
                             /     \                 
                            (       \             
                             )       )             `   `           
`                .          /        /                .      
             ..             \        \                         
                        .    )        )                  ..           
;                           /______  /                  ..
        `  .  '            (/      \(                          .;  
   \               ;       )|      | \   ,.. ,.    ,/          `
    \/            `       __\______/__\     `'     `          .. 
  '-     \;            - /            \)                   `. `
.--.`.; ,-.. ,.-, ;' `.-/           _  \   .--.""-._        .; 
    `............---""  \   |      | \  \              /         `-
 ~                       \  |      |  \  \  _____       .      
                 ~        \_|      |  -\__\(____/
                ~           |  /\  |        
                                                     \"       .--"""
)";
	std::cout << murder << std::endl;
	std::cout << RED_TEXT;
	std::string surrender3 = "Murderer Ending Achieved.";
	printWithDelay(surrender3, delay);

	system("pause");


	std::cout << RESET_COLOR;
	clearScreen();
	exit(0);

}

void Story::meltedEnd()
{
	std::string reckless1 = "You throw all caution to the wind, sprinting to the key. The 'dog' awakens, it snarls before leaping onto you. \nYou try to dodge it, but it seems as though you are too slow. It pounces on top of you, drooling all over you. \nIts acidic saliva-like substance melting into you. Darkness envelops you once more. Close. Not close enough.";

	printWithDelay(reckless1, delay);

	ignoreInputUntilNewline();

	system("pause");



	clearScreen();

	std::string reckless2 = "Melted Ending Achieved.";

	printWithDelay(reckless2, delay);

	system("pause");


	exit(0);
}

void Story::EscapeEnd()
{
	std::string escape1 = "You choose to leave. A wise decision. \nYou decide to make your move and escape. The rest are growing suspicious.";

	printWithDelay(escape1, delay);

	system("pause");



	clearScreen();

	std::string escape2 = "You grab the keys on the corpse's body and make your way to the exit escaping from this nightmare. it's soon coming to an end. \nYou're Almost " + RED_TEXT + "Free" + RESET_COLOR + ". Make a run for it. \nFrom Behind, You hear a mangled screech of agony. \n" + RED_TEXT + "Don't look back.Keep moving." + RESET_COLOR + "";

	printWithDelay(escape2, delay);

	system("pause");



	clearScreen();

	std::string escape3 = "As you make your way to the exit. You hear sirens coming from all angles around you. \n" + RED_TEXT + "You're surrounded.  Run for it. Don't let them catch you!" + RESET_COLOR + "";

	printWithDelay(escape3, delay);

	system("pause");



	clearScreen();

	std::string escape4 = "In the End, no escape was given. " + RED_TEXT + "You " + RESET_COLOR + "were caught. " + RED_TEXT + "You lost." + RESET_COLOR + " \nThey fed you weird looking food. Soon, as your vision regulates itself. \nThe voice is gone…? It's quiet, too quiet. It's just me now, alone. \nkept inside a white room. Forever alone.";

	printWithDelay(escape4, delay);

	system("pause");



	clearScreen();


	std::string escape5 = "I WILL NOT BE SILENCED!";

	std::cout << RED_TEXT;
	printWithDelay(escape5, delay);
	std::cout << RESET_COLOR;

	system("pause");



	clearScreen();
	const char* suffering = R"(

__________________________________________________________________________________
|       ||       ||       ||       ||       ||        ||       ||       ||       |
|       ||       ||       ||       ||_______||        ||       ||       ||       |
|       ||       ||       ||       ||       ||        ||       ||       ||       |
|       ||       ||       ||      /||       ||\       ||       ||       ||       |
|       ||       ||       ||      |||       |||       ||       ||       ||       |
|       ||       ||       ||      |||       |||       ||       ||       ||       |
|       ||       ||       ||      \||       ||/       ||       ||       ||       |
|       ||       ||       ||       ||       ||        ||       ||       ||       |
|       ||       ||       || ______||\_____/||_______ ||       ||       ||       |
|       ||       ||       ||/      ||       ||       \||       ||       ||       |
|       ||       ||       ||       ||       ||        ||       ||       ||       |
|       ||       ||      /||  /|   ||       ||    |\  ||       ||       ||       |
|       ||       ||      ||| | \   ||       ||   /  | ||\      ||       ||       |
|       ||       ||      |___|  |  ||       ||   |  |___|      ||       ||       |
|       ||       ||      |   |  |  ||       ||   |  |   |      ||       ||       |
|       ||       ||      \___|  |  ||       ||   |  |___/      ||       ||       |
|       ||       ||       ||    |  ||       ||   |    ||       ||       ||       |
|       ||       ||       ||    |  ||       ||   |    ||       ||       ||       |
|       ||       ||       ||    |  ||       ||   |    ||       ||       ||       |
|       ||       ||       ||    |  ||   /\  ||   |    ||       ||       ||       |
|       ||       ||       ||    |  ||  |  | ||   |    ||       ||       ||       |
|       ||       ||       ||    |  ||  |  | ||   |    ||       ||       ||       |
|       ||       ||       ||    |  ||  |  | ||   |    ||       ||       ||       |
|_______||_______||_______||___ |__||__|__|_||___|____||_______||_______||_______|



)";

	std::cout << suffering << std::endl;
	std::string escape6 = "Insanity Ending Achieved.";

	std::cout << RED_TEXT;
	printWithDelay(escape6, delay);
	std::cout << RESET_COLOR;

	system("pause");



	clearScreen();
	exit(0);
}
void animate(const std::vector<std::string>& frames, int delayMs) {
	int numLoops = 1;

	for (int loop = 0; loop < numLoops; ++loop) {
		for (const auto& frame : frames) {
			clearScreen();
			std::cout << frame << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
		}
	}
}
void Story::AttackArt()
{
	std::vector<std::string> frames = {
		R"(                        __-----__
                       /         \
                      /   |       \
                     (   -+-       )
                      \   |       /                  
                       \         /
                        )       (________
                _______/________/        \
               /   /____________|         \
              /                   \         \
             /    _______          \__       \
            /    |       \          / \       \
           /    /        /         /    \       \
           | ,./        /          (      \       \
          ,./          ;            |       \       \
       ,./          ,./             |         \        \
    ,./          ,./                |           \        \
 ,./          ,./  |                |             \        \
/          ,./     |                |               \        \
              )",

		R"(
                                         ;- \\
                        __-----__     ,--   \  \ 
                       /         \   _|      \   \
                      /   |       \  ;        \    \
                     (   -+-       );          \    \
                      \   |       /;            \    \
                       \         ;               \    \
                        )       ;                 \ ___\_____
                _______/_______-______             \|        \
               /             _:       \             |        |
              /                        \            \        |
             /    _______               \            \       |
            /    |       \          /    \           |       |
           /    /        /         /     |           /       /
           | ,./        /          (     |          /       /
          ,./          ;            |    |          |       |
       ,./          ,./             |    /          /       /
    ,./          ,./                |   /          |        |
 ,./          ,./  |                | /            /        /
/          ,./     |                |/            /        /
)",

R"(
                                                 //
                                               /  /
                        __-----__            /   / 
                       /         \         /    /
                      /   |       \       /    /
                     (   -+-       )     /    /
                      \   |       /     /    /        
                       \         / ____/__  /
                        )         /       \/
                _______/         /         \
               /                |           \
              /                  \          /
             /    _______         \        /
            /    |       \         \       \
           /    /        /         / \       \
           | ,./        /          (   \       \
          ,./          ;            |    \       \
       ,./          ,./             |      \        \
    ,./          ,./                |        \        \
 ,./          ,./  |                |          \        \
/          ,./     |                |            \        \

              )",

		R"(                                            
              \\        __-----__            
              \  \     /         \         
              \   \   /   |       \       
               \   \ (   -+-       )     
                \   \ \   |       /             
                 \   \ \         /  
                 _\   \ )       (_____      
                /  \   \_______       \
               /    \  \       \       \
              /      \_ \        \      \
             /    _____\_\___      \     \
            /    |       \   \       \    \ 
           /    /        /     \       \  |
           | ,./        /        \       \|
          ,./          ;           \       \
       ,./          ,./             |\        \
    ,./          ,./                |  \        \
 ,./          ,./  |                |    \        \
/          ,./     |                |       \        \
)"
	};
	animate(frames, 500);
	
}

void Story::Lounge(bool result, bool KeyisFound, bool firstkeyFound) {
	std::string input;
	static HuiEnCheck checking;
	checking.currentlocation(1);
	HuiEnIT itemCount;
	firstkeyFound = itemCount.keystate();
Lounge:
	clearScreen();
	const char* LR = R"(
                                                                                
                                                                                
                                                                                
                      @@@#                                                      
                 *@@@    #                                                      
           @@@::         #                                                      
     #@@@                #                                                      
    #                    #                                                      
    #                    #                                                      
    #                    #                                #@@                   
    #                    #                      #@@@@#       @@@                
    #                    #            @@@@@@==   +@@@@@===     #               @
    #                    #      #@@     *@@@@@#                #           #@@  
    #                    #      #*@  @#                        #*         #*@@  
    #                    #      #   @% *@=                      #       =%#    *
    #                 @# #      #     #@  @#             @@@@#  *@  @@@   #     
    #                # # #      #        @# *@  @@@@#              @      #     
    #                #@* #      #          -@--@#            -#@@@@#@#    #     
    #                    #      #             @  #@    @@@@@@        #     @#   
    #                    #      #               #@  @**@          @@@#       *@ 
    #                    #      #                  @* %@*@+@@@%%               =
    #                    #      #                    #*  @*#@                   
    #                    #   #@@@#                      @# #@ @*                
    #                  :=@@@      @@:                     @# #  @=              
    #              *@@               @#                    # #    #@            
    #        *@@#                      *@                  # #       **         
    #  :-@@@                             +@-               # #        +#        
   @@@                                      *@             # #      @@ #        
                                               @#          # # #@#     #        
                                                 @#.       # @*        #        
                                                    @#     # #       @@         
                                                      *@   # #  #@*             
                                                        *@.#.@@*                
                                                                                
                                                                                

                                                                         
)";

	std::cout << LR << std::endl;
	std::string Lounge = "You head into the living room, cobwebs blocking your path to it. \nYou swipe it all while trying to shy away from any spiders that may be lurking. \nThe layout is neat yet unclean. You can't help but feel like you've seen a similar layout somewhere else before. \nBut there's no time to ponder, you have work to do.";
	printWithDelay(Lounge, delay);
	system("pause");
	//Check for Key. If find Key, move onto message6. If not go to other rooms. Can also find 'cure'
	std::cout << "\n\nCheck?\n\n" << std::endl;
	std::cin >> input;
	if (input == "Check" || input == "check")
	{
		bool result = checking.result();
		bool KeyisFound = checking.findkey();

		if (result && !KeyisFound) {
		Cure:
			LRClear = true;
			clearScreen();
			std::string Lounge3 = "Finding nothing of value in the room, you leave, slightly dejected. \nBut you push on, keeping in mind your ultimate goal";
			printWithDelay(Lounge3, delay);
			system("pause");
			if (BedClear == false && KitClear == false)
			{
				while (true) {
					clearScreen();
					std::cout << "Where to Next? \n\n'Bedroom' or 'Kitchen'\n\n";
					std::cin >> input;

					if (input == "Bedroom" || input == "bedroom") {
						// Call the function that handles the Bedroom logic
						Story::Bedroom(result, KeyisFound, firstkeyFound);
						break;
					}
					else if (input == "Kitchen" || input == "kitchen") {
						// Call the function that handles the Kitchen logic
						Story::Kitchen(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Bedroom' or 'Kitchen'.\n";
					}
				}
			}
			else if (BedClear == false && KitClear == true)
			{
				while (true) {
					clearScreen();
					std::cout << "Only one place Left \n\n'Bedroom'\n\n";
					std::cin >> input;

					if (input == "Bedroom" || input == "bedroom") {
						// Call the function that handles the Bedroom logic
						Story::Bedroom(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Bedroom'\n";
					}
				}
			}
			else if (BedClear == true && KitClear == false)
			{
				while (true) {
					clearScreen();
					std::cout << "Only one place Left \n\n'Kitchen'\n\n";
					std::cin >> input;

					if (input == "Kitchen" || input == "kitchen") {
						// Call the function that handles the Kitchen logic
						Story::Kitchen(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Kitchen'.\n";
					}
				}
			}
		}
		else {
			clearScreen();
			if (KeyisFound && !firstkeyFound) {
				std::string Lounge1 = "Between the cushions of the couch, you dig your hand in desperately hoping for something to be there that won't hurt you. \nYou feel something metallic, you grab at it and pull your hand out. \nYou find a key in your now dust-covered hands. Time to go.";
				printWithDelay(Lounge1, delay);
				// Assuming itemCount is an object that has keystate() and key() methods
				itemCount.keystate();
				itemCount.key();
				LRClear = true;
				system("pause");
				// Continue to the next part of the story or game
				ContAct1();
			}
			else {
				std::string Lounge2 = "You didn't manage to find the key you needed, and found a bottle of some special liquid instead. \nIt looks and smells great, you chug it down in an instant. \nIt has a bitter aftertaste, but you feel the tension on your mind ease.";
				printWithDelay(Lounge2, delay);
				system("pause");
				// Return to the decision point after the cure
				goto Cure;
			}
		}
	}
}

void Story::Bedroom(bool result, bool KeyisFound, bool firstkeyFound)
{
	std::string input;
	static HuiEnCheck checking;
	checking.currentlocation(2);
	HuiEnIT itemCount;
	firstkeyFound = itemCount.keystate();

Bed:
	clearScreen();
	const char* Bedroom = R"(
                                                                                
       @++                                                                         
 #  #     #   #  #     #                                                         
  #     #     #  #     #                                                         
#.   .*       #  #     #                                                         
 #  #         #  #     #                                                         
 ##           #  #     #                                                         
 ##           #  #     #                                                         
 ##           #  #     #                                                         
 ##          #   #     #                                                         
 ##        +-  +-#     #                                                         
 ##     . * . * #      #                                                         
 ##     #   # #        #                                                         
 ##   #   # +-         #                                                         
 ## #   # .#           #                                                         
 #..  #. #             #                                                         
 #  =- #             #  -***********%                                            
 #.# #             #                 #===#===#===#=                              
 # #             .#                   #            ===#===#==                    
 ==              @##=               #                        #######             
#    ##          #   ##=#=#===.===.#  #-#=#-.                     .##            
   #. #          #        #       #   #      #%***                # #            
  #   #          #@@      #       #   #      #    %%%***===     =+  #            
.#    #          #  #===#@#===#== #   #      #         #   +++#@    #            
.     #          #               @#   #      #=        #       #    #            
      #          ###=             # -+@- @@+-#==+      #===    #    @++@++@++    
      #  @@.   .#    ##=#=#===.===##  ##    @# ##      #   +++##   #         #@@ 
     #      # #.                 .    ##    ## #%      #       #  #              
   -+        #- +@@@===@@@#==-.             ##         #       # #               
  #.          #      #.        #.@@@#                      #@@###                
#           #      #           #     @@@#@@@#@@@#@#@@@.                          
#         .*     :*          .*                        @@@#@@:::                 
#       .@      #           #                                  .#                
##   .@@      #           *                                 .   #                
 ##@*        #           *.                                #   #*                
 #          #           #                                 #   ##                 
#.        *.           #                                    .# #                 

                                                                         
)";
	std::cout << Bedroom << std::endl;
	std::string Bed = "Ensuring the path is clear before you head into the master bedroom, you make your way without making a sound. \nThe room, despite looking like it's been abandoned, rushes a wave of nostalgia through you. \nBut there's no time to ponder, you have work to do.";
	printWithDelay(Bed, delay);
	system("pause");
	//Check for Key. If find Key, move onto message6. If not go to other rooms. Can also find 'cure'
	std::cout << "\n\nCheck?\n\n" << std::endl;
	std::cin >> input;
	if (input == "Check" || input == "check")
	{
		bool result = checking.result();
		bool KeyisFound = checking.findkey();
		if (result && !KeyisFound) {
		Cure:
			BedClear = true;
			clearScreen();
			std::string Bed3 = "Finding nothing of value in the room, you leave, slightly dejected. \nBut you push on, keeping in mind your ultimate goal";
			printWithDelay(Bed3, delay);
			system("pause");
			if (LRClear == false && KitClear == false)
			{
				while (true) {
					clearScreen();
					std::cout << "Where to Next? \n\n'Lounge' or 'Kitchen'\n\n";
					std::cin >> input;

					if (input == "Lounge" || input == "lounge") {
						// Call the function that handles the Bedroom logic
						Story::Lounge(result, KeyisFound, firstkeyFound);
						break;
					}
					else if (input == "Kitchen" || input == "kitchen") {
						// Call the function that handles the Kitchen logic
						Story::Kitchen(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Lounge' or 'Kitchen'.\n";
					}
				}
			}
			else if (LRClear == false && KitClear == true)
			{
				while (true) {
					clearScreen();
					std::cout << "Only one place Left \n\n'Lounge'\n\n";
					std::cin >> input;

					if (input == "Lounge" || input == "lounge") {
						// Call the function that handles the Bedroom logic
						Story::Lounge(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Lounge'\n";
					}
				}
			}
			else if (LRClear == true && KitClear == false)
			{
				while (true) {
					clearScreen();
					std::cout << "Only one place Left \n\n'Kitchen'\n\n";
					std::cin >> input;

					if (input == "Kitchen" || input == "kitchen") {
						// Call the function that handles the Kitchen logic
						Story::Kitchen(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Kitchen'.\n";
					}
				}
			}
		}
		else {
			clearScreen();
			if (KeyisFound && !firstkeyFound) {
				std::string Bed1 = "You glance around the room to see an unkempt bed, as well as a key on the counter. \nYou thought it would be more well hidden. You quickly grab it, \nshove it into your pocket and steel yourself for what else was to come. \nTime to go.";
				printWithDelay(Bed1, delay);
				// Assuming itemCount is an object that has keystate() and key() methods
				itemCount.keystate();
				itemCount.key();
				BedClear = true;
				system("pause");
				// Continue to the next part of the story or game
				ContAct1();
			}
			else {
				std::string Bed2 = "You didn't manage to find the key you needed, and found a bottle of some special liquid instead. \nIt looks and smells great, you chug it down in an instant. \nIt has a bitter aftertaste, but you feel the tension on your mind ease.";
				printWithDelay(Bed2, delay);
				system("pause");
				// Return to the decision point after the cure
				goto Cure;
			}
		}
	}
}

void Story::Kitchen(bool result, bool KeyisFound, bool firstkeyFound)
{
	std::string input;
	static HuiEnCheck checking;
	checking.currentlocation(3);
	HuiEnIT itemCount;
	firstkeyFound = itemCount.keystate();

Cook:
	clearScreen();
	const char* Kitchen = R"(
                               #                                                
                               #                                                
                               #                                                
                  @#           #                                                
               @@ ##           #                                                
           *@@:   ##           #                                                
         #@#      ##           #                                                
      @@#         ##           #                                                
   @@% @          ##           #                                                
#@@    @          ##           #                                                
.      @          ##           #                                                
       @          ##           #                                                
       @          ##           #                                                
       @         .@#           #                                                
       @       %@*             #                                                
       @    #@@                #                                                
       @ #@#.                  #                                                
      =@@=                    @@@##                                             
    @@                      @@    .. @@@@  .                         @==@       
 @@                      @@     #@# #@@@.  . #@@@@                  #   ##      
%                     @@%    -@@         #@@@%%@@-  %%@@@*=         # -= #      
                    @@.     @@@@#.             @@           #@@@@    ### #      
                    @ . #@@@#.     @@@@#.   -@@                       @@##      
                    @         +@@@@+++.  @@@#                  -@@@@@@@@@  +@@@@
                    @   @@# .          @@@@+++.            .@@#  ##        @@@# 
                    @   @     #@@@             @@@@+.     @@@@*  @@@@@      @@# 
                    @   @     ##  ##+@@@=:           @@@@%=:    @@@@@@=+@@@+    
                 .# @   @      @@###   @    @@#              *@@@#              
               ##   @   @         ## @@@     ##       @@@@#          #@@@#      
             .*     @   @         ##         ##       @     #@@@-:         *@@@@
           #.         #@@@#       ##         ##       @     ##  ##  #@@#        
         #                  . #@@@@#         ##       @       #@@#   @     ##   
      .#                            *@@@@..  ##       @         ## @@@     ##   
    #                                        @@@@     @         ##         ##   
 #.                                                  @@@@       ##         ## #@                               
)";
	std::cout << Kitchen << std::endl;
	std::string Cook = "Avoiding cracks on the floor, you make your way to the kitchen. \nThe sink overflowed with dirty dishes and gunk. The cabinet door hinges rusted, \ndecaying, and almost completely detached. Only hanging on by a single semi-functioning hinge. \nFor some reason, seeing it destroyed fills you with a sense of sadness that you can't figure out. \nBut there's no time to ponder, you have work to do.";
	printWithDelay(Cook, delay);
	system("pause");
	//Check for Key. If find Key, move onto message6. If not go to other rooms. Can also find 'cure'
	std::cout << "\n\nCheck?\n\n" << std::endl;
	std::cin >> input;
	if (input == "Check" || input == "check")
	{
		bool result = checking.result();
		bool KeyisFound = checking.findkey();
		if (result && !KeyisFound) {
		Cure:
			KitClear = true;
			clearScreen();
			std::string Cook3 = "Finding nothing of value in the room, you leave, slightly dejected. \nBut you push on, keeping in mind your ultimate goal";
			printWithDelay(Cook3, delay);
			system("pause");
			if (LRClear == false && BedClear == false)
			{
				while (true) {
					clearScreen();
					std::cout << "Where to Next? \n\n'Lounge' or 'Bedroom'\n\n";
					std::cin >> input;

					if (input == "Lounge" || input == "lounge") {
						// Call the function that handles the Bedroom logic
						Story::Lounge(result, KeyisFound, firstkeyFound);
						break;
					}
					else if (input == "Bedroom" || input == "bedroom") {
						// Call the function that handles the Kitchen logic
						Story::Bedroom(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Lounge' or 'Bedroom'.\n";
					}
				}
			}
			else if (LRClear == false && BedClear == true)
			{
				while (true) {
					clearScreen();
					std::cout << "Only one place Left \n\n'Lounge'\n\n";
					std::cin >> input;

					if (input == "Lounge" || input == "lounge") {
						// Call the function that handles the Bedroom logic
						Story::Lounge(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Lounge'\n";
					}
				}
			}
			else if (LRClear == true && BedClear == false)
			{
				while (true) {
					clearScreen();
					std::cout << "Only one place Left \n\n'Bedroom'\n\n";
					std::cin >> input;

					if (input == "Bedroom" || input == "bedroom") {
						// Call the function that handles the Kitchen logic
						Story::Bedroom(result, KeyisFound, firstkeyFound);
						break;
					}
					else {
						std::cout << "Invalid input. Please enter 'Bedroom'.\n";
					}
				}
			}
		}
		else {
			clearScreen();
			if (KeyisFound && !firstkeyFound) {
				std::string Cook1 = "As you open a cabinet, you see something shiny wedged between the pipes. \nYou take a closer look to find that it was a key. \nYou quickly grab it and dust it off before shoving it into your pocket. \nTime to go.";
				printWithDelay(Cook1, delay);
				// Assuming itemCount is an object that has keystate() and key() methods
				itemCount.keystate();
				itemCount.key();
				KitClear = true;
				system("pause");
				// Continue to the next part of the story or game
				ContAct1();
			}
			else {
				std::string Cook2 = "You didn't manage to find the key you needed, and found a bottle of some special liquid instead. \nIt looks and smells great, you chug it down in an instant. \nIt has a bitter aftertaste, but you feel the tension on your mind ease.";
				printWithDelay(Cook2, delay);
				system("pause");
				// Return to the decision point after the cure
				goto Cure;
			}
		}
	}
}

void Story::DogRLGL()
{
DogHouse:
	std::set<int> randomNumbers;
	EzenRLGL* RLGLPtr = new EzenRLGL;
	RLGLPtr->updateRandomNumbers(randomNumbers, min, max, growltrigger);
	std::string dog1 = "In place of what would seemingly be a dog, lies a mass of rotting flesh, to the point where it seems undead. \nBones protruding out of its spiny body. It's hard to make out its full shape but you notice hints of exposed organs and many layers of serrated teeth, \nyou can tell it'll only end badly if you get caught. Its teeth grind against itself when it snores. \nThe stench of its rotting yet living corpse wafting through the air every snore, making it hard to not hurl. \nThe scraping noises pierce your ears every time it happens.";

	printWithDelay(dog1, delay);
	ignoreInputUntilNewline();
	system("pause");


	clearScreen();

	std::string dog2 = "Hanging above the door of the doghouse, lies a key. \nThat's what you need. That's what " + RED_TEXT + "we " + RESET_COLOR + "need to escape. ";

	printWithDelay(dog2, delay);

	system("pause");


	clearScreen();

	std::string dog3 = "You slowly make your way to the doghouse, careful not to step on the lumps of flesh littered all over the floor as it may wake the “dog”.";

	printWithDelay(dog3, delay);

	system("pause");


	clearScreen();

	std::string dog4 = "As you get closer, your footsteps become more apparent to it. It starts to twist and turn, \nbefore going back to sleep. You would be wise to tread carefully now.";

	printWithDelay(dog4, delay);


	std::cout << "\n\n'reckless' or 'careful'\n\n";

	std::cin >> input;

	clearScreen();



	if (input == "reckless") {
		meltedEnd();
	}

	if (input == "careful") {
		std::string careful1 = "As you move slowly, it starts to growl while in its slumber.You freeze. It stops.You know what to do.";

		printWithDelay(careful1, delay);

		ignoreInputUntilNewline();

		system("pause");



		clearScreen();

		playerposition = 0;

		//insert red light green light scenario here
		while (true) {

			

			if (randomNumbers.find(playerposition) != randomNumbers.end()) {
				std::string tiptoe = "\nthe dog begins to show an expression of what seems like a growl. \nYou see a frown form as it begins to twitch and convulse \n";
				printWithDelay(tiptoe, delay);



				waking = true;
			}

			std::cout << "\n'move' or 'stay'\n\n";

			std::cin >> playermove;

			clearScreen();

			if (playermove == "move") {
				if (waking)
				{

					awakedeath = true;

				}
				if (awakedeath) {
					std::string tiptoe2 = "The 'dog' awakens, it snarls before leaping onto you. You try to dodge it, but it seems as though you are too slow. \nIt pounces on top of you, drooling all over you. Its acidic saliva-like substance melting into you. \nDarkness envelops you once more. Close. Not close enough.\n";
					printWithDelay(tiptoe2, delay);


					exit(0);
				}
				playerposition++;

			}

			waking = false;

			if (waking = true && playermove == "stay") {
				waking = false;

				std::string tiptoe3 = "\nits expression softens again. its breathing slows.\nit looks rather at peace somehow, even with its grotesque features.\n";
				printWithDelay(tiptoe3, delay);

				RLGLPtr->updateRandomNumbers(randomNumbers, min, max, growltrigger);

			}

			if (playerposition > max) {
				break;

			}
		}

		std::string careful2 = "You grabbed the key after what felt like an eternity and slowly made your way back";

		printWithDelay(careful2, delay);

		system("pause");

		clearScreen();

		dogkey = true;
		if (greenkey == false && dogkey == true)
		{
			std::string gates1 = "you make your way back to the gate from the doghouse. " + RED_TEXT + "One left" + RESET_COLOR;

			printWithDelay(gates1, delay);
			const char* gate = R"(
                                 {} {}
                         !  !  ! II II !  !  !
                      !  I__I__I_II II_I__I__I  !
                      I_/|__|__|_|| ||_|__|__|\_I
                   ! /|_/|  |  | || || |  |  |\_|\ !       
       .--.        I//|  |  |  | || || |  |  |  |\\I        .--.
      /-   \    ! /|/ |  |  |  | || || |  |  |  | \|\ !    /=   \
      \=__ /    I//|  |  |  |  | || || |  |  |  |  |\\I    \-__ /
       }  {  ! /|/ |  |  |  |  | || || |  |  |  |  | \|\ !  }  {
      {____} I//|  |  |  |  |  | || || |  |  |  |  |  |\\I {____}
_!__!__|= |=/|/ |  |  |  |  |  | || || |  |  |  |  |  | \|\=|  |__!__!_
_I__I__|  ||/|__|__|__|__|__|__|_|| ||_|__|__|__|__|__|__|\||- |__I__I_
-|--|--|- ||-|--|--|--|--|--|--|-|| ||-|--|--|--|--|--|--|-||= |--|--|-
 |  |  |  || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||  |  |  |
 |  |  |= || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||= |  |  |
 |  |  |- || |  |  |  |  |  |  | O| |O |  |  |  |  |  |  | ||= |  |  |
 |  |  |- || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||- |  |  | 
_|__|__|  ||_|__|__|__|__|__|__|_|| ||_|__|__|__|__|__|__|_||  |__|__|_
-|--|--|= ||-|--|--|--|--|--|--|-|| ||-|--|--|--|--|--|--|-||= |--|--|-
-|--|--|| |  |  |  |  |  |  |  | || || |  |  |  |  |  |  |  |- |--|--|- 
~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~~~~~~~~~~)";

			std::cout << gate << std::endl;
			system("pause");



			clearScreen();
			GardRLGL();
		}

		if (greenkey == true && dogkey == true)
		{
			clearScreen();
			NormalEnd();
		}
	}

}

void Story::GardRLGL()
{
	std::set<int> randomNumbers;
	EzenRLGL* RLGLPtr = new EzenRLGL;
	RLGLPtr->updateRandomNumbers(randomNumbers, min, max, growltrigger);
GreenHouse:
	std::string green1 = "You make your way into the greenhouse. The greenery withered, the glass fogged. \nYou hear a loud snipping, unsure of who's responsible for it, you take cover within the decaying plants. \nOut looms a figure, tall and lanky. Hair covering it, all the way from head to chest. Her movements seem sudden and robotic. \nThere it is again, the snipping noise. In her seemingly frail and boney hands, a pair of large garden shears, dull and rotten. The blade with rust, the handles peeling off.";

	printWithDelay(green1, delay);
	ignoreInputUntilNewline();
	system("pause");


	clearScreen();

	std::string green2 = "You notice a key, shimmering like a rose amongst thorns. That's what you need, that's what " + RED_TEXT + "we " + RESET_COLOR + "need to escape. \nThe task is simple, but it's not going to be easy. \nYou study the vague resemblance of a gardener, wandering around the greenhouse. \nHer patterns are random, erratic, unpredictable. Be on guard. " + RED_TEXT + "Don't get caught." + RESET_COLOR + "";

	printWithDelay(green2, delay);

	system("pause");


	clearScreen();

	std::string green5 = "\nas you made your way towards the key, the crisp sound of decaying autumn leaves crunch." + RED_TEXT + "\nYou got its attention." + RESET_COLOR + "it lifts its head slowly before snapping its neck around to check the sound of the leaves.\nyou hid yourself just in time." + RED_TEXT + "don't let it happen again\n" + RESET_COLOR;

	printWithDelay(green5, delay);

	system("pause");


	clearScreen();

	playerposition = 0;

	//Random number of steps, will hear rustling. If do not wait, will be “killed”*
	while (true) {

	
		if (randomNumbers.find(playerposition) != randomNumbers.end()) {
			std::string sneaky = "you hear the rustling of leaves get louder.";
			printWithDelay(sneaky, delay);



			waking = true;
		}

		std::cout << "\n'move' or 'hide'\n\n";

		std::cin >> playermove;

		clearScreen();

		if (playermove == "move") {
			if (waking)
			{

				awakedeath = true;

			}
			if (awakedeath) {
				std::string sneaky2 = "The gardener turns the corner, you see a crooked smile crack on its face.\nit seemingly disappears before appearing in front of you, it grabs you.\nDarkness envelops you once more. Close. Not close enough.\n";
				printWithDelay(sneaky2, delay);


				exit(0);
			}
			playerposition++;

		}

		waking = false;

		if (waking = true && playermove == "hide") {
			waking = false;

			std::string sneaky3 = "\nit looks around frantically for a moment before slowly moving back to its post.\n";
			printWithDelay(sneaky3, delay);

			RLGLPtr->updateRandomNumbers(randomNumbers, min, max, growltrigger);

		}

		if (playerposition > max) {
			break;

		}
	}


	std::string green3 = "You grabbed the key, losing track of time in the process. You made sure to be careful on your way back.";
	printWithDelay(green3, delay);

	system("pause");

	clearScreen();

	greenkey = true;
	if (greenkey == true && dogkey == false)
	{
		std::string gates2 = "you make your way back to the gate from the greenhouse. " + RED_TEXT + "One left" + RESET_COLOR;

		printWithDelay(gates2, delay);
		const char* gate = R"(
                                 {} {}
                         !  !  ! II II !  !  !
                      !  I__I__I_II II_I__I__I  !
                      I_/|__|__|_|| ||_|__|__|\_I
                   ! /|_/|  |  | || || |  |  |\_|\ !       
       .--.        I//|  |  |  | || || |  |  |  |\\I        .--.
      /-   \    ! /|/ |  |  |  | || || |  |  |  | \|\ !    /=   \
      \=__ /    I//|  |  |  |  | || || |  |  |  |  |\\I    \-__ /
       }  {  ! /|/ |  |  |  |  | || || |  |  |  |  | \|\ !  }  {
      {____} I//|  |  |  |  |  | || || |  |  |  |  |  |\\I {____}
_!__!__|= |=/|/ |  |  |  |  |  | || || |  |  |  |  |  | \|\=|  |__!__!_
_I__I__|  ||/|__|__|__|__|__|__|_|| ||_|__|__|__|__|__|__|\||- |__I__I_
-|--|--|- ||-|--|--|--|--|--|--|-|| ||-|--|--|--|--|--|--|-||= |--|--|-
 |  |  |  || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||  |  |  |
 |  |  |= || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||= |  |  |
 |  |  |- || |  |  |  |  |  |  | O| |O |  |  |  |  |  |  | ||= |  |  |
 |  |  |- || |  |  |  |  |  |  | || || |  |  |  |  |  |  | ||- |  |  | 
_|__|__|  ||_|__|__|__|__|__|__|_|| ||_|__|__|__|__|__|__|_||  |__|__|_
-|--|--|= ||-|--|--|--|--|--|--|-|| ||-|--|--|--|--|--|--|-||= |--|--|-
-|--|--|| |  |  |  |  |  |  |  | || || |  |  |  |  |  |  |  |- |--|--|- 
~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~~~~~~~~~~)";

		std::cout << gate << std::endl;
		system("pause");


		clearScreen();
		DogRLGL();
	}

	if (greenkey == true && dogkey == true)
	{
		clearScreen();
		NormalEnd();
	}
}

void Story::NormalEnd()
{
End:
	std::string End1 = "You clutch both keys, one in each hand. \nFreedom. \nYou unlock the gates, the locks surprisingly quiet. You push open the creaky doors, they slide out of the way. \nThe scenery is still dreadful, dark, and desolate as ever. The air feels heavy, yet it still relieves you. \nAs though a great weight has been lifted off your chest. As you wander, the trees start to distort, buildings start to warp. \nYou begin to lose your grip on reality. Fearing for your life, you run. Run. \nrun as fast and as far as you can but no matter what you do you can't escape it.";

	printWithDelay(End1, delay);
	ignoreInputUntilNewline();
	system("pause");


	clearScreen();

	std::string End2 = "You trip, landing face first into the dirt. flipping yourself over, you see a familiar park. \nIt seems like such a distant memory, yet you remember it so vividly. \nYou make your way to a bench, almost subconsciously, like you're aware of this location. \nYou lie down to shut your eyes, getting some rest after a dreadful day. \nAs you dove off to sleep, you see 2 figures loom over you. \nToo tired to fight back, you accept their cold embrace, as well as your fate.";

	printWithDelay(End2, delay);
	ignoreInputUntilNewline();
	system("pause");


	clearScreen();

	std::string End3 = "Escaped? Ending Achieved.";

	printWithDelay(End3, delay);

	system("pause");
	exit(0);
}



void waitForEnterKey() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD ir;
	DWORD dwRead;

	while (true) {
		// Read input from the console
		ReadConsoleInput(hInput, &ir, 1, &dwRead);
		if (ir.EventType == KEY_EVENT)
		{
			KEY_EVENT_RECORD& keyEvent = ir.Event.KeyEvent;
			if (keyEvent.bKeyDown && keyEvent.wVirtualKeyCode == VK_RETURN)
			{
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Reduce CPU usage
	}
}
void StartStealth()
{
	using namespace std::chrono;

	bool spacePressed = false;

	while (true) {
		// Check if the spacebar is pressed
		if (GetAsyncKeyState(0x48) & 0x8000) {
			if (!spacePressed) {
				// Spacebar was just pressed
				spacePressed = true;
				held = true;
				pressStart = steady_clock::now();
			}

			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - pressStart).count();
			

			if (elapsed >= 2) {
				spacePressed = false;
				held = false; // reset after successful avoidance
				// Successfully avoided enemy
				std::string moving4 = "\nThe being stops. Waits. Then leaves quicker than it came. \nThe door slams shut, but remains unlocked, now is your chance.";
				printWithDelay(moving4, delay);
				std::cout << "Press Enter to Continue";
				waitForEnterKey();
				clearScreen();
				std::this_thread::sleep_for(std::chrono::seconds(3));
				held = false; // reset after successful avoidance
				spacePressed = false;
				break; // Exit the loop after handling the event
			}
		}
		else {
			// Spacebar is not pressed
			if (spacePressed) {
				// Spacebar was released
				spacePressed = false;
				held = false;
				// Handle case where spacebar was released too early
				std::string moving5 = "\nIt hears your breathing through the closet. \It grabs your hand out of the closet. \nDarkness envelops you once more. Close. Not close enough.";
				printWithDelay(moving5, delay);
				std::cout << "Press Enter to Continue";
				waitForEnterKey();
				clearScreen();
				Story goAct1;
				goAct1.Act1();
				break; // Exit the loop after handling the event
			}
		}

		std::this_thread::sleep_for(milliseconds(100));
	}
}
void ClosetStealth() {
	using namespace std::chrono;

	bool spacePressed = false;

	while (true) {
		// Check if the spacebar is pressed
		if (GetAsyncKeyState(0x48) & 0x8000) {
			if (!spacePressed) {
				// Spacebar was just pressed
				spacePressed = true;
				held = true;
				pressStart = steady_clock::now();
			}

			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - pressStart).count();
			

			if (elapsed >= 2) {
				spacePressed = false;
				held = false; // reset after successful avoidance
				// Successfully avoided enemy
				std::string closet2 = "\nIt leaves the room and slams the door shut. You're safe, for now.";
				printWithDelay(closet2, delay);
				std::cout << "Press Enter to Continue";
				waitForEnterKey();
				clearScreen();
				std::this_thread::sleep_for(std::chrono::seconds(3));
				held = false; // reset after successful avoidance
				spacePressed = false;
				break; // Exit the loop after handling the event
			}
		}
		else {
			// Spacebar is not pressed
			if (spacePressed) {
				// Spacebar was released
				spacePressed = false;
				held = false;
				// Handle case where spacebar was released too early
				std::string closet3 = "\nHe forces the door open and grabs you from inside the closet. Darkness envelops you once more. Close. Not close enough.";
				printWithDelay(closet3, delay);
				std::cout << "Press Enter to Continue";
				waitForEnterKey();
				clearScreen();
				Story goAct1;
				goAct1.Act1();
				break; // Exit the loop after handling the event
			}
		}

		std::this_thread::sleep_for(milliseconds(100));
	}
}

void BedStealth()
{
	using namespace std::chrono;

	bool spacePressed = false;

	while (true) {
		// Check if the spacebar is pressed
		if (GetAsyncKeyState(0x48) & 0x8000) {
			if (!spacePressed) {
				// Spacebar was just pressed
				spacePressed = true;
				held = true;
				pressStart = steady_clock::now();
			}

			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - pressStart).count();
			

			if (elapsed >= 2) {
				spacePressed = false;
				held = false; // reset after successful avoidance
				// Successfully avoided enemy
				std::string bed3 = "\nThey wander around for a bit, then silence.You can hear the footsteps grow more distant, only moving from under the bed when you feel safe.";

				printWithDelay(bed3, delay);
				std::cout << "Press Enter to Continue";
				waitForEnterKey();
				clearScreen();
				std::this_thread::sleep_for(std::chrono::seconds(3));
				spacePressed = false;
				held = false; // reset after successful avoidance
				break; // Exit the loop after handling the event
			}
		}
		else {
			if (spacePressed) {
				// Spacebar was released
				spacePressed = false;
				held = false;
				// Handle case where spacebar was released too early
				std::string bed4 = "\nHe hears your hitched breathing underneath the bed. Crouching Down, He grabs you by the throat. \nDarkness envelops you once more. Close. Not close enough.";
				printWithDelay(bed4, delay);
				std::cout << "Press Enter to Continue";
				waitForEnterKey();
				clearScreen();
				Story goAct1;
				goAct1.Act1();
				break; // Exit the loop after handling the event
			}
		}

		std::this_thread::sleep_for(milliseconds(100));
	}
}
