# 🐍 Shop Snake
Shop Snake is a version of snake where half of the apples are replaced with
coins, which you can spend to shorten your snake.

This was the first project I made with
 [Raylib](https://github.com/raysan5/raylib), so it is very bare bones.

## 🎮 How to Play
Use WASD, HJKL, or Arrow Keys to control the snake. The green pixels are the
parts of the snake, the red pixels are apples, and the yellow pixels are coins.
The amount of coins you have is displayed in the top left corner. Once you have
3 coins, you can press Space to make yourself one tile shorter.

## 🏗️ Building
Shop Snake relies on Raylib. Build Raylib first, then put raylib.h in include/
and librarylib.a in lib/. A good project directory looks like this:
```
shopsnake/
|__ include/
|   |__ raylib.h
|__ lib/
|   |__ libraylib.a
|__ src/
|__ README.md
and some other stuff
```
