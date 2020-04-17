# PA9_SpaceInvaders
## Objects Needed (Visual: shape, actions, and movement):
	- Aliens (create a generic class, then use inheritance for bellow)
		○ Types
			§ Octopus
			§ Crap
			§ Squid
		○ Features
			§ Number of hits before died
			§ Move zig-zaggy across the screen, and downward slowly
			§ Fire Laser
				□ Once the aliens reach a certain y position they start trying to kill cannon man:(
	- Player (cannon guy)
		○ Move left and right
		○ Fire Laser
	- Laser - Cannon ball/whatever the shooted thing is.
		○ Move straight from firing point
	- Defense Bunkers
		○ Stationary, doesn’t need much
	- HUD
		○ Score counter
		○ Lives

## Collisions To Handle:
	- Laser hits alien
	- Laser hits player
	-Alien reaches bottom of screen
