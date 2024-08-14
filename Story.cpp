#include "Story.h"
#include <iostream>
#include <string>
#include "DelayedText.h"
std::string input;
std::chrono::milliseconds delay(0);
bool dogkey = false;
bool greenkey = false;
const std::string RED_TEXT = "\033[31m";
const std::string RESET_COLOR = "\033[0m";
int Story::Act1()
{


	std::string message = "Coldness. It rushes through you like a ghost. Your surroundings start to warp, and distort. \nUnfamiliar scenery of a park you know not the name of surrounds you. \nWith only the winds of the cold night to keep you company.";

	printWithDelay(message, delay);

	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();

	std::string message2 = "You can't help but feel something is off, like someone is close. Footsteps. \nYou swivel your head in a panic, too late. Before you could react, darkness envelops you. \nFeeling lethargic, you leave your life in the hands of fate, accepting whatever is to come as you doze off.";

	printWithDelay(message2, delay);

	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();

Start:

	std::string message3 = "You wake up. Eyes needing time to adjust to the darkness. \nYou listen closely and hear the subtle trickling of water through the walls a few rooms away, \nIts echoes booming throughout the room. \nThe air reeks with a hurl-inducing stench. Your eyes adjust, you wish they hadn't. \nChipped paint, moss, cracks and crevices. \nThey litter the walls, almost as much as the stench in the air.";

	printWithDelay(message3, delay);

	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();

	std::string message4 = "As you take in the atmosphere of the dark, dreary, dreadful room you're in, you try to get up. Futility. \nChained to the chair, your mobility is limited. \nYour eyes dart around to find something that could help, even just a little bit. \nOn your left, and quite a distance away, a rusted penknife. \nTime is short, you hear footsteps.";

	printWithDelay(message4, delay);


	std::cout << "\n\n'move' or 'wait'\n\n";
	std::cin >> input;

Input:

	if (input == "wait")
	{
		clearScreen();

		std::string waiting1 = "You can hear the footsteps get louder as time passes. ";

		printWithDelay(waiting1, delay);


		std::cout << "\n\n'move' or 'wait'\n\n";

		std::cin >> input;


		if (input == "wait")
		{

			clearScreen();

			std::string waiting2 = "the footsteps get even louder. Are you sure this is a wise idea?";

			printWithDelay(waiting2, delay);

			std::cout << "\n\n'move' or 'wait'\n\n";

			std::cin >> input;

			if (input == "wait")
			{
				clearScreen();

				std::string waiting3 = "you should make a move, now.";

				printWithDelay(waiting3, delay);

				std::cout << "\n\n'move' or 'wait'\n\n";

				std::cin >> input;


				if (input == "wait")
				{
					clearScreen();

					std::string waiting4 = "Why are you waiting! Move! Now!";

					printWithDelay(waiting4, delay);

					std::cout << "\n\n'move' or 'wait'\n\n";

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
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						std::cout << "\n\nPress Enter proceed";
						std::cin.get();

						clearScreen();

						std::string waiting7 = "Wait Ending Achieved.";

						printWithDelay(waiting7, delay);

						std::cout << "\n\nPress Enter proceed";
						std::cin.get();
						
						return 0;
					}
				}
			}
		}


	}

	if (input == "move")
	{
		clearScreen();

		std::string moving1 = "You drag your chair towards the knife, trying to make as much distance as possible with every motion. \nYou're close, not close enough.";

		printWithDelay(moving1, delay);

		std::cout << "\n\n'move' or 'wait'\n\n";

		std::cin >> input;

		if (input == "wait")
		{
			goto Input;
		}

		if (input == "move")
		{
			clearScreen();

			std::string moving2 = "You make one last effort, and heave your chair to the penknife, toppling the chair and leaving the penknife within your grasp. \nYou cut your wrists and ankles free and find a place to scuttle away, hoping to stay hidden.";

			printWithDelay(moving2, delay);

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string moving3 = "The door creaks open as the heavy footsteps settle in. Each step shakes the ground, disrupting the rhythm of your heart.\nYou hold your breath in hopes of not being found. ";

			printWithDelay(moving3, delay);

			//stealth here

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string moving4 = "The being stops. Waits. Then leaves quicker than it came. \nThe door slams shut, but remains unlocked, now is your chance.";

			printWithDelay(moving4, delay);

		}


	}


	std::string message5 = "As the door creaks close, you slink your way past it, being careful not to make a sound. \nYou make your way through the house, door by door. The estate seemingly warps with every decision you make, losing you in its boundless possibilities. \nYou find your way to the front door, locked. Windows, locked. You'll have to find another way out.";
	printWithDelay(message5, delay);

	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();


	//this is where players need to go find the key


	//when key has been gotten
	std::string message6 = "Looks like the key to the front door. Only one thing left to do.";

	printWithDelay(message6, delay);

	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();





	std::string message7 = "As you make your way to the front door, you feel freedom creeping ever closer. \nYou can't tell whether it's adrenaline or excitement that fills you. You turn the corner, wary as ever, \nonly to see the being that you so narrowly escaped from, guarding the door.";
	printWithDelay(message7, delay);

	std::cout << "\n\n'fight' or 'flee'\n\n";

	std::cin >> input;

	clearScreen();

	//fight or flee decision

	if (input == "fight")
	{

		std::string fight1 = "You choose to confront the being, you will be afraid of them no longer. \nYou take a final stand, it's kill or be killed. \nAs it reaches out for you, you plunge your blade into their chest, staggering them. \nYou push with all your might, tackling them to the ground, driving the blade further in.";
		printWithDelay(fight1, delay);

		std::cout << "\n\nPress Enter proceed";
		std::cin.get();

		clearScreen();

		std::string fight2 = "you twist the blade while it's in their chest, ignoring the eldritch cries coming from it and pull out your blade while shovelling at their guts. \nTangy intestines get dragged along with the blade, some severing before being fully pulled out. \nThey reach out, trying to grab you.";
		printWithDelay(fight2, delay);

		std::cout << "\n\nPress Enter proceed";
		std::cin.get();

		clearScreen();

		std::string fight3 = "You plunge your blade into their heart. With more accuracy this time. \nAgain. Again. Each time with more ferocity than the last. \nYou will be held captive" + RED_TEXT + " no more." + RESET_COLOR + "You " + RED_TEXT +"will" + RESET_COLOR + " be free.";
		printWithDelay(fight3, delay);

		std::cout << "\n\nPress Enter proceed";
		std::cin.get();

		clearScreen();

		std::string fight4 = "With the blade left plunged into their chest, blood spurting and spilling out, you release the blade, hands shaking. \nYour vision starts to blur, reality starts to shift. \nIt's trying to " + RED_TEXT + "deceive" + RESET_COLOR + " you. Don't " + RED_TEXT + "trust" + RESET_COLOR + " it. You " + RED_TEXT + "will " + RESET_COLOR + "be free";
		printWithDelay(fight4, delay);

		std::cout << "\n\nPress Enter proceed";
		std::cin.get();

		clearScreen();

		std::string fight5 = "You did it. You're no longer afraid." + RED_TEXT + " What's next?" + RESET_COLOR;
		printWithDelay(fight5, delay);

		std::cout << "\n\n" + RED_TEXT + "'murder'" + RESET_COLOR + " or 'escape'\n\n";

		std::cin >> input;

		clearScreen();

		if (input == "murder") {

			std::string kill1 = "You decide that you'll kill the rest, for you are no longer afraid.\n " + RED_TEXT + "I like that. Go on then, do what you must." + RESET_COLOR + "";
			printWithDelay(kill1, delay);

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string kill2 = "As the voice disappears, your head rises to scan the environment, covered in the creature's blood.\n Sure Enough, you see more and more grotesque creatures approaching you.\nSome with faces that resemble horror, others resembling anger, you can't quite make it out.\nEven new creatures you've never seen before. Crawling on the floor lies a ball of rotting meat with serrated teeth growling at you.";
			printWithDelay(kill2, delay);

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

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
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "\n\n" + RED_TEXT + "Attack!\n\n" + RESET_COLOR + "";
				std::cin >> input;

				clearScreen();
				if (input == "Attack" || input == "attack") {
					std::string kill5 = "Kill! Kill! Kill!\nDon't you dare stop. More are on the way. Don't Stop. \nYou don't want to lose your freedom again do you?\nListen to Me. Kill them All.";

					std::cout << RED_TEXT;
					printWithDelay(kill5, delay);
					std::cout << RESET_COLOR;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					std::cout << "\n\n" + RED_TEXT + "Attack!\n\n" + RESET_COLOR + "";
					std::cin >> input;

					clearScreen();

					std::string kill6 = "As you keep on killing, soon the cries stop. Leaving you all alone covered in the blood of the creatures.\nAs you look at the corpses, your vision starts to clear bit by bit revealing the truth of your actions.\nAs you stare at what you've done, your vision regains its blurriness.";
					printWithDelay(kill6, delay);
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n\nPress Enter proceed";
					std::cin.get();

					clearScreen();
				}


			}
			std::string kill7 = "Don't think about them. They're just deadweight. They don't understand our suffering.\nThey only want to separate us. You don't want that.  We're free now.\nCome on, let's get going. More will come if we don't leave.";
			
			std::cout << RED_TEXT;
			printWithDelay(kill7, delay);
			std::cout << RESET_COLOR;

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string kill8 = "Listening to the voice, you make your way out of the nightmare. Finally being free, you make your way back to your safe haven.\nAs you're walking, covered in blood. You hear more and more screams of terror all around you.\n" + RED_TEXT + "Kill them. They won't seperate us. We're in this together.\nI promise I will keep us safe. We're partners. Give me Control." + RESET_COLOR + "";
			printWithDelay(kill8, delay);

			std::cout << "\n\n'surrender' or 'resist'\n\n";

			std::cin >> input;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			clearScreen();

			if (input == "surrender") {
				std::string surrender1 = "Ahhhhh. Finally, Some freedom. Don't worry. I'll take care of them.\nI will protect you. Get some rest, you won't feel our pain ever again.";
				std::cout << RED_TEXT;
				printWithDelay(surrender1, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string surrender2 = "As Austin falls to his slumber. I deal with our problems, finally free.\nNo one will stop us anymore. You're safe Austin. Safe with me.";
				printWithDelay(surrender2, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string surrender3 = "Murderer Ending Achieved.";
				printWithDelay(surrender3, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();
				std::cout << RESET_COLOR;
				clearScreen();
				return 0;

			}

			if (input == "resist") {
				std::string resist1 = "" + RED_TEXT + "Be like that then. See for yourself how long you can survive without me. " + RESET_COLOR + "The voices then stop.\n It's silent for the first time in a long while, it's just me. \nThe deafening silence continues, my vision returns back to normal and I see what were the monsters surrounding me, the neighbours terrified as they call the police.";
				printWithDelay(resist1, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();



				std::string resist2 = "Within minutes, the police arrive. Approaching me covered in human blood, they walk slowly towards me, wary of the danger I might pose. \nSeeing that I wasn't a threat to them, they rushed forward. Tackling me down and detaining me before I could react.";
				printWithDelay(resist2, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string resist3 = "Next thing I know, I'm locked up in a dark empty cell. \nNo light came through except for the holes in the iron door in front of me. \nI found myself  tied up and unable to move a single part of my body.";
				printWithDelay(resist3, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string resist4 = "See what I told you Austin? Now look at us. Trapped, unable to move. This is all your fault. \nYou could have just given me control but now? Now it's too late to even bother anymore. \nHave fun being alone, Austin.";
				std::cout << RED_TEXT;
				printWithDelay(resist4, delay);
				std::cout << RESET_COLOR;

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string resist5 = "My consciousness begins to fade while trying to keep myself from dozing off. \nI wonder, was it really the right decision? To remain in control. \nIt's my own body... isn't it?";
				printWithDelay(resist5, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string resist6 = "Alone Ending Achieved.";
				printWithDelay(resist6, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();
				return 0;
			}
		}

		if (input == "escape") {

			std::string escape1 = "You choose to leave. A wise decision. \nYou decide to make your move and escape. The rest are growing suspicious.";

			printWithDelay(escape1, delay);

			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();

			std::string escape2 = "You grab the keys on the corpse's body and make your way to the exit escaping from this nightmare. it's soon coming to an end. \nYou're Almost " + RED_TEXT + "Free" + RESET_COLOR + ". Make a run for it. \nFrom Behind, You hear a mangled screech of agony. \n" + RED_TEXT + "Don't look back.Keep moving." + RESET_COLOR + "";

			printWithDelay(escape2, delay);

			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();

			std::string escape3 = "As you make your way to the exit. You hear sirens coming from all angles around you. \n" + RED_TEXT + "You're surrounded.  Run for it. Don't let them catch you!" + RESET_COLOR + "";

			printWithDelay(escape3, delay);

			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();

			std::string escape4 = "In the End, no escape was given. " + RED_TEXT + "You " + RESET_COLOR + "were caught. " + RED_TEXT + "You lost." + RESET_COLOR + " \nThey fed you weird looking food. Soon, as your vision regulates itself. \nThe voice is gone…? It's quiet, too quiet. It's just me now, alone. \nkept inside a white room. Forever alone.";

			printWithDelay(escape4, delay);

			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();


			std::string escape5 = "I WILL NOT BE SILENCED!";

			std::cout << RED_TEXT;
			printWithDelay(escape5, delay);
			std::cout << RESET_COLOR;

			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();

			std::string escape6 = "Insanity Ending Achieved.";

			std::cout << RED_TEXT;
			printWithDelay(escape6, delay);
			std::cout << RESET_COLOR;

			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();
			return 0;
		}

	}

	if (input == "flee") {
		std::string flee1 = "You turn back, choosing to run. Your foot lands on a creaky floorboard. \nIt hears you. Run. \nyou make a mad dash through the seemingly never ending corridors.";

		printWithDelay(flee1, delay);

		std::cout << "\n\n'straight' or 'right'\n\n";

		std::cin >> input;

		clearScreen();

		if (input == "straight") {
			std::string straight1 = "You choose to run as fast as possible, but it seems as though you aren't making any distance. \nYou look back and see the being closing the gap. \nIt's futile. It catches up to you, you've lost. \nDarkness envelops you once more. Close. Not close enough.";

			printWithDelay(straight1, delay);

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();

			goto Start;
		}

		if (input == "right") {
			std::string flee2 = "You take the next turn you find, into a room. \nFootsteps trail closely behind. Hide.";

			printWithDelay(flee2, delay);

			std::cout << "\n\n'bathroom' or 'bed' or 'closet'\n\n";

			std::cin >> input;

			clearScreen();
			if (input == "bathroom") {
				std::string right1 = "You slink into the bathroom, closing the door behind you as silently as possible.";

				printWithDelay(right1, delay);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string right2 = "The door opens, an eye looks through the keyhole. You've been caught.";

				printWithDelay(right2, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string right3 = "The door bursts open and knocks you out cold. \nDarkness envelops you once more. Close. Not close enough.";

				printWithDelay(right3, delay);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				goto Start;
			}

			if (input == "bed") {
				std::string bed1 = "You slide under the bed, holding your breath. This seems oddly familiar…";

				printWithDelay(bed1, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string bed2 = "The being steps into the room hurriedly, the frantic footsteps getting closer by the second.";

				printWithDelay(bed2, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();


				//stealth


				std::string bed3 = "They wander around for a bit, then silence.You can hear the footsteps grow more distant, only moving from under the bed when you feel safe.";

				printWithDelay(bed3, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

			}

			if (input == "closet") {
				std::string closet1 = "You shut yourself into the closet as darkness shrouds you, you blend in with the dark spaces. \nThe being runs into the room. Briefly scanning the room. His panic comes to a stop, scanning the room again, more thoroughly this time.";

				printWithDelay(closet1, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				//stealth
				/*if(Succeed)
				{
				std::string closet2 = "it leaves the room and slams the door shut.You're safe, for now.";

				printWithDelay(closet2, delay);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();
				}*/

			/*	if (Fail)
				{
				std::string closet3 = "He forces the door open and grabs you from inside the coset. Darkness envelops you once more.Close.Not close enough.";

				printWithDelay(closet3, delay);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				goto Start;
				}*/

			}
			std::string door1 = "The door is no longer guarded. You're homefree. You make your way to the door, unlocking it. \nThe light that was thought to be freedom, snuffed out. There's another door left. \nYou focus into the lock, noticing it requires 2 keys. This won't be easy, but it can be done. \n" + RED_TEXT + "You can escape." + RESET_COLOR + "";

			printWithDelay(door1, delay);

			std::cout << "\n\nPress Enter proceed";

			std::cin.get();

			clearScreen();
			Act2();

			return 0;
		}
	}
}

int Story::Act2()
{
	std::string yard1 = "The front yard and backyard are now open to you, and you are open to whatever is out there. there is much more to explore, press on.";

	printWithDelay(yard1, delay);

	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();

	std::string yard2 = "You see a doghouse on the left, a greenhouse on the right. Your choice.";

	printWithDelay(yard2, delay);

	std::cout << "\n\n'doghouse' or 'greenhouse'\n\n";

	std::cin >> input;

	clearScreen();
	if (dogkey == false && greenkey == false)
	{
		if (input == "doghouse") {
		DogHouse:
			std::string dog1 = "In place of what would seemingly be a dog, lies a mass of rotting flesh, to the point where it seems undead. \nBones protruding out of its spiny body. It's hard to make out its full shape but you notice hints of exposed organs and many layers of serrated teeth, \nyou can tell it'll only end badly if you get caught. Its teeth grind against itself when it snores. \nThe stench of its rotting yet living corpse wafting through the air every snore, making it hard to not hurl. \nThe scraping noises pierce your ears every time it happens.";

			printWithDelay(dog1, delay);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string dog2 = "Hanging above the door of the doghouse, lies a key. \nThat's what you need. That's what " + RED_TEXT + "we " + RESET_COLOR + "need to escape. ";

			printWithDelay(dog2, delay);

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string dog3 = "You slowly make your way to the doghouse, careful not to step on the lumps of flesh littered all over the floor as it may wake the “dog”.";

			printWithDelay(dog3, delay);

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string dog4 = "As you get closer, your footsteps become more apparent to it. It starts to twist and turn, \nbefore going back to sleep. You would be wise to tread carefully now.";

			printWithDelay(dog4, delay);


			std::cout << "\n\n'reckless' or 'careful'\n\n";

			std::cin >> input;

			clearScreen();



			if (input == "reckless") {
				std::string reckless1 = "You throw all caution to the wind, sprinting to the key. The 'dog' awakens, it snarls before leaping onto you. \nYou try to dodge it, but it seems as though you are too slow. It pounces on top of you, drooling all over you. \nIts acidic saliva-like substance melting into you. Darkness envelops you once more. Close. Not close enough.";

				printWithDelay(reckless1, delay);

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				std::string reckless2 = "Melted Ending Achieved.";

				printWithDelay(reckless2, delay);

				std::cout << "\n\nPress Enter proceed";
				std::cin.get();

				return 0;
			}

			if (input == "careful") {
				std::string careful1 = "As you move slowly, it starts to growl while in its slumber.You freeze. It stops.You know what to do.";

				printWithDelay(careful1, delay);

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				clearScreen();

				//insert red light green light scenario here

				std::string careful2 = "You grabbed the key after what felt like an eternity and slowly made your way back";

				printWithDelay(careful2, delay);

				std::cout << "\n\nPress Enter proceed";

				std::cin.get();

				dogkey = true;
				if (greenkey == false && dogkey == true)
				{
					clearScreen();
					goto GreenHouse;
				}

				if (greenkey == true && dogkey == true)
				{
					clearScreen();
					goto End;
				}
			}
		}

		if (input == "greenhouse")
		{
		GreenHouse:
			std::string green1 = "You make your way into the greenhouse. The greenery withered, the glass fogged. \nYou hear a loud snipping, unsure of who's responsible for it, you take cover within the decaying plants. \nOut looms a figure, tall and lanky. Hair covering it, all the way from head to chest. Her movements seem sudden and robotic. \nThere it is again, the snipping noise. In her seemingly frail and boney hands, a pair of large garden shears, dull and rotten. The blade with rust, the handles peeling off.";

			printWithDelay(green1, delay);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			std::string green2 = "You notice a key, shimmering like a rose amongst thorns. That's what you need, that's what " + RED_TEXT + "we " + RESET_COLOR + "need to escape. \nThe task is simple, but it's not going to be easy. \nYou study the vague resemblance of a gardener, wandering around the greenhouse. \nHer patterns are random, erratic, unpredictable. Be on guard. " + RED_TEXT + "Don't get caught." + RESET_COLOR + "";

			printWithDelay(green2, delay);

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			clearScreen();

			//Random number of steps, will hear rustling. If do not wait, will be “killed”*

			std::string green3 = "You grabbed the key, losing track of time in the process. You made sure to be careful on your way back.";
			printWithDelay(green3, delay);

			std::cout << "\n\nPress Enter proceed";
			std::cin.get();

			greenkey = true;
			if (greenkey == true && dogkey == false)
			{
				clearScreen();
				goto DogHouse;
			}

			if (greenkey == true && dogkey == true)
			{
				clearScreen();
				goto End;
			}
		}
	}
End:
	std::string End1 = "You clutch both keys, one in each hand. \nFreedom. \nYou unlock the gates, the locks surprisingly quiet. You push open the creaky doors, they slide out of the way. \nThe scenery is still dreadful, dark, and desolate as ever. The air feels heavy, yet it still relieves you. \nAs though a great weight has been lifted off your chest. As you wander, the trees start to distort, buildings start to warp. \nYou begin to lose your grip on reality. Fearing for your life, you run. Run. \nrun as fast and as far as you can but no matter what you do you can't escape it.";

	printWithDelay(End1, delay);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();

	std::string End2 = "You trip, landing face first into the dirt. flipping yourself over, you see a familiar park. \nIt seems like such a distant memory, yet you remember it so vividly. \nYou make your way to a bench, almost subconsciously, like you're aware of this location. \nYou lie down to shut your eyes, getting some rest after a dreadful day. \nAs you dove off to sleep, you see 2 figures loom over you. \nToo tired to fight back, you accept their cold embrace, as well as your fate.";

	printWithDelay(End2, delay);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	clearScreen();

	std::string End3 = "Escaped? Ending Achieved.";

	printWithDelay(End3, delay);

	std::cout << "\n\nPress Enter proceed";
	std::cin.get();

	return 0;
}


