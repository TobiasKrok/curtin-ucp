# Assigment 2

## IO

- First two ints are the map row/column
- ALl numbers later in the file contains the row/col pos and the char
- All non-preset coordinates will be empty spaces on the map which are moveable areas
- Can assume 1 player, 1 box and 1 goal
- Wall will not overlap
- Wall will not block goal or box
- Zero index 

`fscanf`
`fgets`

Example:

20 30 <- Map size
1 1 P <- Where the player (P) will spawn
3 3 O <- Position of a wall (letter O)
4 4 B <- Box position
7 9 G <- Goal position 


## Color trail

Color trail will follow the box

