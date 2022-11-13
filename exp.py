import matplotlib.pyplot as plt
import pandas as pd

df = pd.DataFrame({
    'values' : [1,5.4,5,7,10,30]
} , index = ['A' , 'B' , 'C' ,'D' ,'E' , 'F'])

df.plot(kind = 'pie' , y = 'values' , legend = False)

plt.show()