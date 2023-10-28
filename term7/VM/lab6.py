def create_basic_polynomial(x_values, i):
    def basic_polynomial(x):
        divider = 1
        result = 1
        for j in range(len(x_values)):
            if j != i:
                result *= (x-x_values[j])
                divider *= (x_values[i]-x_values[j])
        return result/divider
    return basic_polynomial


def create_Lagrange_polynomial(x_values, y_values):
    basic_polynomials = []
    for i in range(len(x_values)):
        basic_polynomials.append(create_basic_polynomial(x_values, i))

    def lagrange_polynomial(x):
        result = 0
        for i in range(len(y_values)):
            result += y_values[i]*basic_polynomials[i](x)
        return result
    return lagrange_polynomial


x_values = [1, 1.1, 1.3, 1.5, 1.7, 1.9]
y_values = [1, 1.019, 1.054]

lag_pol = create_Lagrange_polynomial(x_values, y_values)

for x in x_values:
    print("x = {:.4f}\t y = {:4f}".format(x,lag_pol(x)))