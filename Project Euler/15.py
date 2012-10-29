import operator

print reduce(operator.mul, range(21, 41)) / reduce(operator.mul, range(1, 21))
