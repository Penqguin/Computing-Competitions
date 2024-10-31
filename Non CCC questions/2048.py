def largest_tile(grid):
    max_tile = 0
    for row in grid:
        for tile in row:
            if tile > max_tile:
                max_tile = tile
    return max_tile

def merge_up(grid):
    new_grid = [[0]*4 for _ in range(4)]
    for col in range(4):
        tiles = [grid[row][col] for row in range(4) if grid[row][col] != 0]
        merged_tiles = []
        i = 0
        while i < len(tiles):
            if i < len(tiles) - 1 and tiles[i] == tiles[i+1]:
                merged_tiles.append(tiles[i]*2)
                i += 2
            else:
                merged_tiles.append(tiles[i])
                i += 1
        for row in range(len(merged_tiles)):
            new_grid[row][col] = merged_tiles[row]
    print(new_grid, "up")
    return new_grid

def merge_down(grid):
    new_grid = [[0]*4 for _ in range(4)]
    for col in range(4):
        tiles = [grid[row][col] for row in range(4) if grid[row][col] != 0]
        merged_tiles = []
        i = len(tiles) - 1
        while i >= 0:
            if i > 0 and tiles[i] == tiles[i-1]:
                merged_tiles.append(tiles[i]*2)
                i -= 2
            else:
                merged_tiles.append(tiles[i])
                i -= 1
        for row in range(len(merged_tiles)):
            new_grid[3-row][col] = merged_tiles[len(merged_tiles)-1-row]
    print(new_grid, "down")
    return new_grid

def merge_left(grid):
    new_grid = [[0]*4 for _ in range(4)]
    for row in range(4):
        tiles = [grid[row][col] for col in range(4) if grid[row][col] != 0]
        merged_tiles = []
        i = 0
        while i < len(tiles):
            if i < len(tiles) - 1 and tiles[i] == tiles[i+1]:
                merged_tiles.append(tiles[i]*2)
                i += 2
            else:
                merged_tiles.append(tiles[i])
                i += 1
        for col in range(len(merged_tiles)):
            new_grid[row][col] = merged_tiles[col]
    print(new_grid, 'left')
    return new_grid

def merge_right(grid):
    new_grid = [[0]*4 for _ in range(4)]
    for row in range(4):
        tiles = [grid[row][col] for col in range(4) if grid[row][col] != 0]
        merged_tiles = []
        i = len(tiles) - 1
        while i >= 0:
            if i > 0 and tiles[i] == tiles[i-1]:
                merged_tiles.append(tiles[i]*2)
                i -= 2
            else:
                merged_tiles.append(tiles[i])
                i -= 1
        for col in range(len(merged_tiles)):
            new_grid[row][3-col] = merged_tiles[len(merged_tiles)-1-col]
    print(new_grid, "right")
    return new_grid

def solve(grid):
    max_tile = largest_tile(grid)
    directions = [merge_up, merge_down, merge_left, merge_right]
    for _ in range(10):
        for direction in directions:
            new_grid = direction(grid)
            max_tile = max(max_tile, largest_tile(new_grid))
            grid = new_grid
    return max_tile
    
for i in range(1):
    grid = [list(map(int, input().split())) for _ in range(4)]
    print(solve(grid))