# Abysmal Engine

This is a simple game project to get acquainted with C and SDL3. This uses my own custom engine, written entirely in my own makeshift, handcrafted C, using as few dependencies as possible, for better or for worse. This engine is meant to compliment SDL3, so if you decide to use it, beware that you'll also need to use SDL3 for some of the smaller things.

## Game
A remastering of my first game, [Balance](https://abyssaltheking.itch.io/balance), that will be called Balance: Rebalanced. 

Balance: Rebalanced is a top-down shooter where you must protect the Orb of Balance from rebels, or the entire world will be thrown in chaos. Use your powers to protect the Orb of Balance for as long as you can. If the Orb of Balance breaks, ***run and cower, you cannot escape***.

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
- [ ] Implement basic audio
    - [ ] [miniaudio](https://miniaud.io) backend
    - [ ] Allows for simple changes (pitch, volume, reverb?)
- [ ] Basic physics
    - [ ] Forces will be added with just simple change to a velocity x & y variable
    - [ ] AABB collisions 
- [ ] `typedef struct WorldObject` -> compilation of a physics object & a sprite, possibly more things i might add, should simplify things though

### Game
do have an idea now, just need time to think of what to implement