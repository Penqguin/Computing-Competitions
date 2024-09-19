amount = int(input())
for i in range(1, amount + 1):
  index, word = input().split(maxsplit=1)
  index = int(index)
  
  misspelled_word = word[:index - 1] + word[index:]

  print(i, misspelled_word)
