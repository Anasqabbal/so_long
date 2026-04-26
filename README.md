# so_long

![Score](https://img.shields.io/badge/score-100%2F100-success)
![C](https://img.shields.io/badge/language-C-blue)
![Graphics](https://img.shields.io/badge/library-MLX-orange)

## 📌 Overview
**so_long** is a small 2D game project from 1337 (42 Network). The goal is to build a top-down game using the MiniLibX graphic library, where the player must collect all items on a map before reaching the exit.

This project introduces graphical programming, event handling, and window management. As a Software Engineer, building responsive, event-driven applications and understanding UI loops is a core competency.

## 💡 Core Concepts Explored
### 2D Graphics & Event Loops
**Definition:** 2D game programming involves managing a loop that listens for user input (events), updates the game state, and redraws the graphical interface (rendering sprites) frame-by-frame.
**Problem Solved:** It solves the challenge of interactive graphical interfaces by implementing an infinite event loop that captures user keyboard inputs to move characters and trigger game logic asynchronously.

## 🚀 Features
- **Map Parsing:** Reads `.ber` map files, validating map structure (rectangular, closed by walls, valid path checking using Flood Fill).
- **Graphics:** Renders sprites (textures) onto the window using MiniLibX.
- **Event Handling:** Captures keyboard events (W, A, S, D) to move the player and handles window close events gracefully.
- **Game Logic:** Tracks movement count, item collection, and winning conditions.

## 📥 How to Clone
To clone this project, use the following command:
```bash
git clone git@github.com:Anasqabbal/so_long.git
cd so_long
```

## 🛠️ Usage
Compile the game:
```bash
make
```
Run the game with a valid map using the generated `so_long` executable:
```bash
./so_long maps/map1.ber
```

## 🧠 What I Learned
- Utilizing external graphical libraries (MiniLibX) and managing their memory.
- Event-driven programming (handling key presses and rendering loops).
- Algorithmic problem solving, particularly implementing the Flood Fill algorithm to ensure map playability.

## 🌐 Connect with me
[![GitHub](https://img.shields.io/badge/GitHub-black?logo=github)](https://github.com/Anasqabbal)
[![LinkedIn](https://img.shields.io/badge/-IN-0A66C2?logo=linkedin&logoColor=0a66c2)](https://www.linkedin.com/in/anasqabbal/)

