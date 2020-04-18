# PA9_SpaceInvaders
[Wikipedia page of Space Invaders](https://en.wikipedia.org/wiki/Space_Invaders)
## Objects Needed (Visual: shape, actions, and movement):
	- Aliens (create a generic class, then use inheritance for bellow) -- Courtney
		○ Types
			§ Octopus
			§ Crap
			§ Squid
		○ Features
			§ Number of hits before died
			§ Move zig-zaggy across the screen, and downward slowly
			§ Fire Laser
				□ Once the aliens reach a certain y position they start trying to kill cannon man:(
	- Player (cannon guy) -- Jared
		○ Move left and right
		○ Fire Laser
	- Laser - Cannon ball/whatever the shooted thing is. -- Christian
		○ Move straight from firing point
	- Defense Bunkers -- Whoever gets to it first
		○ Stationary, doesn’t need much
	- HUD -- Whoever gets to it first
		○ Score counter
		○ Lives

## Collisions To Handle:
	- Laser hits alien
	- Laser hits player
	- Laser hits bunker
	- Alien reaches bottom of screen
