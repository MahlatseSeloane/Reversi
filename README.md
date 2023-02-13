<h1>Reversi</h1>
<p>For the project, using the IDE CodeBlocks, we were required to develop a computer program in C++ that facilitated the game of Reversi between two different algorithms. The program was to read a number of board sizes of n × n where 4 ≤ n ≤ 16 and is always even, from a file named input.txt, and facilitate the game for each board size between the two algorithms and record the games in an output file</p>

<p>Reversi, also known as Othello is a two-player board game played traditionally on an 8 x 8 board. Players take alternating turns, placing black or white pieces in empty blocks on the grid. The goal of the game is to occupy the most number of spots on the board.</p>

<h2>Code Requirements</h2>
<p>The requirements for the project were as follows:

- The code should not prompt the user for input nor produce any console output.
-	No global variables may be used as this would result in immediate failure.
- Use of at least one Class.
- Use of a Function.
-	Reading in and writing to files.
</p>                       

<h2>Input format</h2>
<p>The input file would contain a list of board sizes that would be used to test the two algorithms against each other. The input file had the following format</p>

<img src="https://imgur.com/fqfXIWT.png" height = "70%" width = "70%" />

<h2>Output format</h2>
<p>The program must produce an output file named results.txt. This file must contain the following:

- size of the board for the current game,
- each position filled, which algorithm filled it (in the order of placement) and the locations where pieces flipped in that turn,
- the number of blocks occupied by each algorithm and
- the winning algorithm.
The history for each board size listed in the input file must be appended to this file with one empty line inbetween different games.

Below is an exapmle of the output file for the games of the boardsizes in the input file:
</p>

<img src="https://imgur.com/CsrBjJW.png" height = "70%" width = "70%" />

<p>Note that coordinates on the board are labelled using the value of the row (r) and column (c) where the top left position is r0c0 and bottom right is r5c5 for a board of size 4 x 4.</p>
