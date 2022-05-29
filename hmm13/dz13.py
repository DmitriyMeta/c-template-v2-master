import random
import time
def QuickSort(A, l, r):
    if l >= r:
        return 
    else:
        q = random.choice(A[l:r + 1])
        i = l
        j = r
        while i <= j:
            while A[i] < q:
                i += 1
            while A[j] > q:
                j -= 1
            if i <= j: 
                A[i], A[j] = A[j], A[i]
                i += 1
                j -= 1 
                QuickSort(A, l, j)
                QuickSort(A, i, r)
alist=[]
t = []
for i in range(100):
  for i in range(1000):
    alist.append(random.randint(1, 100))
  alist = [int(x) for x in alist]
  start_time = time.time()
  QuickSort(alist, 0, 99)
  t.append(time.time() - start_time)
K = 0
for i in range(100):
    K = K + t[i]
print(K)