# Fantasy Fighting Game

## Overview

Fantasy Fighting Game is a C++ project where a human player battles against the computer (the Beast). The game is designed to be rigged, making it easier for the human player to win. The project demonstrates the use of inheritance and composition to provide a deeper understanding of object-oriented programming (OOP) principles.

### Features

- Multiple player types (Human and Beast)
- Various items such as potions, weapons, and armors available at the store
- Arena for battles between the human and the beast
- Tracks hits, misses, damage done, HP remaining, and coins remaining
- Save and load game functionality to return to the game at a later time
- Proper memory management to avoid memory leaks

## Code Structure

- `DataAccess.cpp` and `DataAccess.h`: Handles data access for saving and loading game states.
- `Arena.cpp` and `Arena.h`: Manages the battle arena where the human and beast fight.
- `Beast.cpp` and `Beast.h`: Defines the Beast class representing the computer player.
- `Human.cpp` and `Human.h`: Defines the Human class representing the human player.
- `Player.cpp` and `Player.h`: Base class for players, inherited by Human and Beast.
- `ClubArmor.cpp` and `ClubArmor.h`, `SwordArmor.cpp` and `SwordArmor.h`, `GunArmor.cpp` and `GunArmor.h`: Defines different types of armor available in the game.
- `Sword.cpp` and `Sword.h`, `Club.cpp` and `Club.h`, `Gun.cpp` and `Gun.h`: Defines different types of weapons available in the game.
- `HealthPotion.cpp` and `HealthPotion.h`, `DamagePotion.cpp` and `DamagePotion.h`: Defines different types of potions available in the game.
- `Potion.cpp` and `Potion.h`: Base class for potions, inherited by HealthPotion and DamagePotion.
- `Armor.cpp` and `Armor.h`: Base class for armors, inherited by specific armor types.
- `Weapon.cpp` and `Weapon.h`: Base class for weapons, inherited by specific weapon types.
- `Store.cpp` and `Store.h`: Manages the store where players can buy items.
- `Main.cpp`: The entry point of the application where the game starts and runs.

## Compilation and Execution

### Prerequisites

- A C++ compiler (like `g++` using Apple Clang)

### Steps to Compile and Run

1. Open a terminal.

2. Navigate to the project directory:

    ```sh
    cd "/Users/Admin/Desktop/Fantasy_Fighting_Game/sources"
    ```

3. Compile the source files:

    ```sh
    g++ *.cpp -o my_program
    ```

4. Run the compiled program:

    ```sh
    ./my_program
    ```

## How to Play

- Start the game by running the compiled executable.
- Navigate through the menus to purchase items such as weapons, armors, and potions from the store.
- Enter the arena to battle against the Beast.
- The game tracks hits, misses, damage, and health points.
- You can save the game at any point and load it later to continue.

## Memory Management

- The project ensures proper memory management to avoid memory leaks.
- Pointers and addresses are managed appropriately, with destructors cleaning up dynamically allocated memory.

## Save and Load Functionality

- The game state can be saved to a file.
- Load a previously saved game to continue from where you left off.

## Example Run
https://youtu.be/Bh_nOo4jjD4



