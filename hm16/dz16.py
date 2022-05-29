import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mlt

t=[]
for i in range (1000):
  x = np.linspace(0.0,3,i+2)
  y = 100*x
  dx = x[1] - x[0]
  t.append(np.sum(y*dx)-450)
print(t)
plt.plot(t)
plt.show()
