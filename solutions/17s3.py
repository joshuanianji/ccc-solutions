import collections


n = int(input())

l = list(map(int, input().split()))

heights = [0] * 2001


for v in l:
  heights[v] += 1

bestlen = 0
bestnc = 0
for candheight in range(2, 4002):
  maxh = 0
  for canda in range(max(1, candheight - 2000), candheight // 2 + 1):
    if canda * 2 == candheight:
      maxh += heights[canda] // 2
    else:
      maxh += min(heights[canda], heights[candheight - canda])

  if maxh > bestlen:
    bestlen = maxh
    bestnc = 1
  elif maxh == bestlen:
    bestnc += 1

print(bestlen, bestnc)
