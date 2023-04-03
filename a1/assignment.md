# UCP Assignemnt 1 Notes


## Command line arguments

**Program name**: box

Arguments:
- <map_row> (INT)
  - How "tall" map is
  - MIN: 5 
  - Should not be too big
- <map_col> (INT)
  - How wide the map is
  - MIN 5
  - Should not be too big
- <player_row> (INT)
  - Which row the player should spawn at
  - Zero based index
- <player_col> (INT)
  - Which column the player should spawn at
  - Zero based index
- <goal_row> (INT)
  - Which row the goal should spawn at (not same as player)
  - Zero based index
- <goal_col> (INT)
  - Which column the goal should spawn at (not same as player)
  - Zero based index
  
If the map_row/col is less then 5, end program

If player col/row is negative number or bigger than map, end program

Use `argc` 
## Box

Generate position randomly, make sure it does not overlap with goal/player and not at border (first/last row or column

## PULL
Add conditional compilation to add a pull feature. I