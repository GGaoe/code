from fractions import Fraction


# frac.numerator ����/ frac.denominator����
# ����һ��֧�ַ�������ľ���
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


# չʾ����
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


# �������� (�����±��1��ʼ, �� m * n�ľ���, �����±��1 ~ m)
def change_row(matrix, row1_num, row2_num):
    matrix[row1_num - 1],  matrix[row2_num - 1] = matrix[row2_num - 1], matrix[row1_num - 1]


# ����ĳһ�� (�����±��1��ʼ, �� m * n�ľ���, �����±��1 ~ m)
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
