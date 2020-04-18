# PA9_SpaceInvaders
[Wikipedia page of Space Invaders](https://en.wikipedia.org/wiki/Space_Invaders)
## Directions for Development
Until we begin combining our work, we will each need to create our own Main.cpp file to hold the main() function.
This will ease the initial debugging process and allow us to function fairly autonomously.

### Git Help
If you have trouble with git: youtube is okay, the command bellow is best, cheat sheets are great; google 'em.
```
git help
```

### Using This Repo
To use the repo you will need to it from here, then create a new BLANK project from visual studio located in
the directory you cloned the repo into. Add a Main.cpp file, and start your project from their. 

You may need to add our source files to your project. To do so, open your project, click "Project" in the upper left-hand
corner, then "Add Existing Item." Navigate to your source files for the repo, highlight all of them, and click "Add"

### Making Commits
Whenever you make a change that you could say in one sentence, commit it. Commit early, commit often.
For example, a commit should never contain 2 function definitions. Define one function, make sure it works,
then commit it. Define the second function, make sure it works, then commit it.

Try to be descriptive with your commit messages. "fixed typo" is fine, but try to be a bit more verbose for other
things. (This article)[https://chris.beams.io/posts/git-commit/] is a good reference, but it's a bit overkill for our purposes.

### Style Guide
If this isn't done, that's fine, I'll just end up changing it...
This is important, because it makes reading the code a lot easier if everyone's code looks vaguely similar.
Try to avoid typos.
Every function should have a description comment block above it like so:
```
/*
Name: foo
Description: this is a function that does absolutely nothing.
*/
void foo() {
// codes
}
```
Try not to make your comments or code lines so long that you have to scroll to read it. It's not fun for you, or for anyone else.

Use camel case for variables, and upper camel case for objects/classes.
```
ClassName

variableName
```
No hanging braces, because it's gross. ><
```
// this
int foo() {
// codes
}

// not this
int foo()
{
// codes
}

// this
if (foo) {
// codes
}

// not this 
if (foo) 
{
// codes
}
```
If an if statement or loop will only have one line in the body, ommit the braces:
```
if (corn)
	foobar();
	
while (spaghetti > pizza - 50)
	spaghetti--;
```
## Stuff To Do
### Objects Needed (Visual: shape, actions, and movement):
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

### Collisions To Handle:
	- Laser hits alien
	- Laser hits player
	- Laser hits bunker
	- Alien reaches bottom of screen
