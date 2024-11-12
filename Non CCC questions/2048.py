from collections import deque

def move(grid):
  newGrid = [[0] * 4 for _ in range(4)]
  for i in range(4):
    pos = 0
    last = 0
    for j in range(4):
      if grid[i][j] != 0:
        if last == 0:
          last = grid[i][j]
        elif last == grid[i][j]:
          newGrid[i][pos] = 2 * last
          pos += 1
          last = 0
        else:
          newGrid[i][pos] = last
          pos += 1
          last = grid[i][j]
    if last != 0:
        newGrid[i][pos] = last
  return newGrid

def rotate(grid):
  return [[grid[j][i] for j in range(4)][::-1] for i in range(4)]

def find_largest_tile(grid):
  maxTile = max(max(row) for row in grid)
  queue = deque([grid])
  visited = set()
  visited.add(tuple(tuple(row) for row in grid))
  
  while queue:
    currentGrid = queue.popleft()
    currentMax = max(max(row) for row in currentGrid)
    maxTile = max(maxTile, currentMax)
    
    # Try all four possible moves
    for k in range(4):
      newGrid = rotate(currentGrid)
      if k == 1:
        newGrid = move(newGrid)
      elif k == 2:
        newGrid = rotate(move(rotate(newGrid)))
      elif k == 3:
        newGrid = rotate(rotate(move(rotate(newGrid))))
      
      compressed_newGrid = tuple(tuple(row) for row in newGrid)
      
      # Only explore if the grid changes and is not visited
      if newGrid != currentGrid and compressed_newGrid not in visited:
        visited.add(compressed_newGrid)
        queue.append(newGrid)
          
        if len(queue) > 100:
          queue.pop()

  return maxTile

for _ in range(5):
  grid = [list(map(int, input().split())) for _ in range(4)]
  print(find_largest_tile(grid))