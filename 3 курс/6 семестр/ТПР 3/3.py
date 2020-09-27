import numpy as np
import matplotlib.pyplot as plt
import pprint
from pylab import *
from scipy.linalg import *
from operator import itemgetter

class SquareFunction:

    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def get_value(self, x):
        return self.a * (x**2) + self.b * x + self.c


pp = pprint.PrettyPrinter(indent=4)
file = input('Input filename: ')
input_file = open(file + '.input', 'r')
criterias_count = int(input_file.readline())
criterias = []
for c in range(criterias_count):
    criteria= {}
    criteria['name'] = input_file.readline().strip()
    criteria['values'] = list(map(lambda x: float(x), input_file.readline().split(';')))
    if input_file.readline().strip() == 'inverted':
        criteria['values'] = list(map(lambda x: 1 / x, criteria['values']))
        criteria['inverted'] = True
    else:
        criteria['inverted'] = False

    # calculate criteria profitability function
    subplot = plt.subplot(3, 1, c + 1)
    x = np.array(criteria['values'])
    y = np.array([i for i in range(len(x))])
    m = vstack((x**2, x, ones(len(x)))).T
    a, b, k = lstsq(m, y)[0]
    x_s = linspace(x[0], x[-1])
    subplot.title.set_text("%s: %10.4f*x^2+%10.4f*x+%10.4f" % (criteria['name'], a, b, k))
    subplot.plot(x_s, a*(x_s**2) + b*x_s + k, '--')
    subplot.plot(x, y, '.', marker='o', markersize = 4)
    criteria['function'] = SquareFunction(a, b, k)

    criterias.append(criteria)

plt.show()

alternatives_count = int(input_file.readline())
alternatives = []
header = list(map(lambda x: x.strip(), input_file.readline().split(';')))

for i in range(alternatives_count):
    line = list(map(lambda x: x.strip(), input_file.readline().split(';')))
    alternative = {}
    alternative['name'] = line[0]
    profitability = 0
    for c in range(criterias_count):
        val = float(line[c + 1])
        if criterias[c]['inverted']:
            val = 1 / val
        alternative[header[c + 1]] = val
        profitability += criterias[c]['function'].get_value(val)
    alternative['profitability'] = profitability
    alternatives.append(alternative)

pp.pprint(criterias)
pp.pprint(alternatives)

pp.pprint(max(alternatives, key=itemgetter('profitability')))
