# Installation
### Install SDL2 SDL2-image SDL2-mixer SDL2-ttf
```
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev

```

# How to run
you can alternatively do
```
./sc1
```
after making sc1 executable using ```chmod +x sc1```
### Compile the project
```
make clean && make run_client && make run_server
```
### Run the server on one machine
```
./run_server.out
```
### Run the client on the two machines
```
./run_client.out
```
### Game Rules
For help, press F1.
To type in the chatbox, press ctrl + D.
To send your message in chatbox, press ctrl + S.
The objective is to traverse through a group of checkpoints. The player who reaches the last checkpoint first, wins. There’s a scoring system to challenge you.

# Documentation
### Incode Documentation
We've documented every function in the code itself using comments.

### Reference Documentation
We've hosted the reference documentation at [Documentation](https://mrityunjai01.github.io/maze-game-using-sdl/index.html). You can also view the docs using mkdocs, ```mkdocs serve```

# References
### Code Management
- https://stackoverflow.com/questions/10422034/when-to-use-extern-in-c
- https://www.youtube.com/watch?v=KMNmkmjDia8
- http://enet.bespin.org/Tutorial.html

### Source Code
- https://www.youtube.com/watch?v=KsG6dJlLBDw (a beginner's tutorial to SDL)
- https://www.cplusplus.com/ (everything c++)
- http://enet.bespin.org/Tutorial.html

### an efficient use of Makefile
- https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

### Making doxygen docs
- https://pages.cs.wisc.edu/~jignesh/cs564/notes/Doxygen.pdf
- https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen

### Making material docs
- https://github.com/matusnovak/doxybook
- https://squidfunk.github.io/mkdocs-material/

### Enet
- http://enet.bespin.org/

### Assets
#### Voices
https://voicemaker.in/

#### Sound Effects
dota2
- https://dota2.fandom.com/wiki/Sniper
- https://dota2.fandom.com/wiki/Viper

message
- https://www.fesliyanstudios.com/royalty-free-sound-effects-download/whoosh-and-swoosh-73
- https://www.fesliyanstudios.com/policy
#### Theme songs
- https://www.marxists.org/history/ussr/sounds/index.htm
- The rick roll song https://www.youtube.com/watch?v=dQw4w9WgXcQ

#### Fonts
- https://www.1001freefonts.com/d/5486/playfair-display.zip

#### Graphics
- Running Man Sprite https://w1.pngwing.com/pngs/70/107/png-transparent-walk-cycle-footwear-walking-animation-sprite-human-knee-shoe-finger.png
- IITD Map https://home.iitd.ac.in/images/iitd-campus-map.jpg
