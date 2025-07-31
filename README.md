# Expanding World

This is a simple game project to get acquainted with C and SDL3. This uses my own custom engine, written entirely in my own makeshift, handcrafted C, using as few dependencies as possible. Currently in heavy construction. Don't expect anything much anytime soon, but feel free to review the code yourself.

## Why C over C++ or literally any other language that's not 53 years old?

Simplicity, mainly. I find C++ to be really complex for me. I can understand bits and pieces, but when you have so many goddamn features, the code, in my opinion, becomes close to impossible to read and understand. I decided "well, C isn't thaaat hard, right?", and for the most part, I was right. It's very simple, only has a handful of features, but these features are really all I've found that I need to make some cool programs. I've come to understand it for the most part, I still am trying to grasp a couple things, but for the most part, it's not too difficult. As for why not other languages, say Odin, or Java, or C#, mainly because for whatever reason I decided "hm, not low level enough." I'm sure with that mentality I'm going to start making my own CPU out of rocks I find in my driveway, but for now, this is good enough for me. :)

## Building

I kept it simple, as this is my first ever Makefile, and my first time using a build system, and also my first project in C.

Anyway, here are the commands:

```bash
$ make       # builds to build/
$ make run   # runs the executable in build/
$ make clean # deletes everything in build
$ make quick # builds, then runs
$ make debug # runs the executable in build/ with valguard for debugging, requires valguard to use
```

## TODO

### Engine
- [x] Create an input header file
    - [x] `bool isKeyPressed(key)` -> returns true if yes
    - [x] Make sure that key presses don't have the issue where it hesitates for a second before continuing input
- [ ] Start on graphics
    - [ ] `typedef Struct Sprite` -> just a texture with position & size values for the most part
        - [ ] please for the love of god use SDL_image i am NOT converting all my images to bmps

### Game
- yeah ill fill this out when i get a good idea, not yet though