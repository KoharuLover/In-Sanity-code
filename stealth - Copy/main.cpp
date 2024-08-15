#include "player.h"

int main() {

	// 2 - hidden
	// 1 - enemy alerted
	// 0 - dieded
	// when entering room with an enemy, stealth value reduces to 1, need to hide to bring back up, else die

	bool enemy_in_room = true;
	player austin;

	// when player is entering a room
	if (enemy_in_room) {
		austin.setStealth(-1);
		if (austin.getStealth() == 1) {
			austin.hideAttempt();
		}
		
	}
}