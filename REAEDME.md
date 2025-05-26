# Unofficial Rush 01 Attempt

**My level during this attempt was Lvl 4.9 out of 9 in the Core Program (in the cub3d milestone). So memory handling and pointer referencing was used more here to handle grids ranging from 4x4 up to 9x9.**

**Disclamer: Even if you can pass in clues for more than 4x4 grids, the solution only reliably solves up to 6x6 grids, the constraint propagation is not good enough to solve 7x7-9x9 grids**

## Error Handling

- **Grid Size:** The program will technically run for grids larger than 10x10, but this is not recommended due to performance concerns.
- **Clue Values:** Clues greater than 9 are not handled, as the main focus was on implementing the core solution logic.

## Constraint Propagation (Pruning)

- If a clue is `1`, the highest wall is placed immediately in the corresponding cell.

## Backtracking Algorithm

The backtracking approach is straightforward but required careful visualization, which I found helpful to do on paper or digitally(I prefer this). Here’s how the algorithm works:

1. **Possibility Loop:** For each cell, try all possible values in descending order, skipping those already pruned.
2. **Duplication Check:** For each attempt, check for duplicates in the current row and column.
3. **Validation:**
   - Once a row is filled, check if its visibility matches the clues.
   - Do the same for columns.
   - Row validation is performed before column validation, as the grid is filled left-to-right, top-to-bottom.
4. **Backtracking:**
   - If a duplication or validation check fails, move to the next possible value.
   - If both checks pass, proceed to the next cell.
5. **Base Cases:**
   - **Solution Found:** All cells are filled successfully.
   - **Backtrack:** All possibilities for a cell are exhausted without success.

## Potential Improvements to tackle > 6x6 grid
1. If clue is the largest, fill in the entire row or column in ascending order from 1 to N
2. For bigger grids, find a way to run the validity row and column checking prematurely, probably after its reached more than half of the row or column size, the checking can start to run.
