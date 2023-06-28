from fractions import Fraction


# frac.numerator 整数/ frac.denominator分数
# 创造一个支持分数运算的矩阵
def make_matrix(list_matrix):
    fra_matrix = []
    for i in range(len(list_matrix)):
        row = []
        for j in list_matrix[i]:
            if not isinstance(j, Fraction):
                row.append(Fraction(j))
            else:
                row.append(j)
        fra_matrix.append(row)
    return fra_matrix


# 展示矩阵
def show(matrix, information_str='no tips'):
    global cnt
    print(information_str)
    print('-' * len(matrix[0]) * 10)
    for row in matrix:
        for item in row:
            print('{:>10}'.format(str(item)), end='')
        print()
    print()
    cnt += 1


# 交换两行 (行数下标从1开始, 即 m * n的矩阵, 行数下标从1 ~ m)
def change_row(matrix, row1_num, row2_num):
    matrix[row1_num - 1],  matrix[row2_num - 1] = matrix[row2_num - 1], matrix[row1_num - 1]


# 化简某一行 (行数下标从1开始, 即 m * n的矩阵, 行数下标从1 ~ m)
def simplify(matrix, row_num):
    row_num -= 1
    pivot = matrix[row_num][row_num]
    for j in range(len(matrix[0])):
        matrix[row_num][j] /= pivot

    for i in range(len(matrix)):
        if i != row_num:
            times = matrix[i][row_num]
            for j in range(len(matrix[0])):
                matrix[i][j] -= matrix[row_num][j] * times



if __name__ == '__main__':
