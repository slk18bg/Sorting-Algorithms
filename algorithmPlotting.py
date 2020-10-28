import matplotlib.pyplot as plt
import csv

x = [] # size of vector
y = [] # time taken to sort in ns

# data is saved in algorithmData.txt files, where 'algorithm' can be replaced with
# insertion, merge, heap, quick, counting, radix, or bucket
# to open the data for that algorithm

with open('bucketData.txt', 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(int(row[1]))
        
plt.plot(x, y)
plt.xlabel('Size of Vector')
plt.ylabel('Time to Sort (ns)')
plt.title('Bucket Sort') # for each algorithm tested, the title name is changed
plt.show()
