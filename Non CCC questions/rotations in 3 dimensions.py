import math

def normalize(vector):
  magnitude = math.sqrt(sum(v ** 2 for v in vector))
  return [v / magnitude for v in vector]

def dot_product(v1, v2):
  return sum(x * y for x, y in zip(v1, v2))

def cross_product(v1, v2):
  return [
    v1[1] * v2[2] - v1[2] * v2[1],
    v1[2] * v2[0] - v1[0] * v2[2],
    v1[0] * v2[1] - v1[1] * v2[0]
  ]

def matrix_multiply(matrix, vector):
  return [
    sum(row[i] * vector[i] for i in range(len(vector))) for row in matrix
  ]

t = int(input())

for _ in range(t):
  x, y, z, rx, ry, rz, theta = map(float, input().split())
    
  # Normalize the rotation axis
  axis = normalize([rx, ry, rz])
    
  cos_theta = math.cos(theta)
  sin_theta = math.sin(theta)
    

  K = [
    [0, -axis[2], axis[1]],
    [axis[2], 0, -axis[0]],
    [-axis[1], axis[0], 0]
  ]
    
  R = [[0] * 3 for _ in range(3)] 
  for i in range(3):
    for j in range(3):
      dot_term = axis[i] * axis[j] * (1 - cos_theta)
      K_term = sin_theta * K[i][j]
      R[i][j] = (cos_theta if i == j else 0) + dot_term + K_term
    
  point = [x, y, z]
  rotated_point = matrix_multiply(R, point)
  
  print(f"{rotated_point[0]:.6f} {rotated_point[1]:.6f} {rotated_point[2]:.6f}")
