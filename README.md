# Description

Boulder break is a 2-dimensional puzzle game coded in C as my introduction to low-level languages where the goal is to help an adventurer collect treasure and escape from a cave by pushing boulders into holes that may block the exit. 
- In the diagram shown below, the adventurer (trying to escape the cave) is represented by the red circle.
- The gray coloured circles are the boulders that the adventurer can push.
- The black circle is the hole which is currently blocking the yellow exit, and into which the boulders can be pushed.
- The small chest containing jewels is the treasure.
![alt text](https://github.com/p0nyo/boulder-break/blob/main/boulderbreak.jpg?raw=true)
## How to play

- To collect treasure, the adventurer simply needs to move onto its location.
- If the adventurer steps onto a hole, they will fall in and meet an untimely end. That will be the end of the game.
- To push a boulder, the adventurer must position themselves next to the boulder and can only push the boulder in the direction of their movement. When the adventurer pushes a boulder, the boulder will continue to roll in a straight line until it hits an obstacle (either part of the cave, a
treasure chest or another boulder).
- The position of the adventurer does not change when they push a boulder.
- After the boulder has moved, the adventurer can move.
- To escape the cave, the adventurer must move onto the yellow exit. If the exit is blocked by a hole, they must push a boulder into the hole which will fill it in, allowing them to access the yellow exit.


