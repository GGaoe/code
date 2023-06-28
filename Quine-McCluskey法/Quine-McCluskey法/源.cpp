#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

// �����������ֵĺ�������
int hammingDistance(int a, int b) {
    int count = 0;
    int diff = a ^ b;
    while (diff) {
        count++;
        diff &= diff - 1;
    }
    return count;
}

// ������ת��Ϊ�����Ʊ�ʾ
string toBinaryString(int n, int numBits) {
    string binary = bitset<32>(n).to_string().substr(32 - numBits);
    return binary;
}

// �����������Ķ����Ʋ���
string generateBinaryDifference(int a, int b, int numBits) {
    string binaryA = toBinaryString(a, numBits);
    string binaryB = toBinaryString(b, numBits);
    string diff;
    for (int i = 0; i < numBits; i++) {
        if (binaryA[i] != binaryB[i]) {
            diff += "-";
        }
        else {
            diff += binaryA[i];
        }
    }
    return diff;
}

// ��ʮ����������ת��Ϊ������������
vector<string> convertToBinarySet(vector<int>& decimalSet, int numBits) {
    vector<string> binarySet;
    for (int i = 0; i < decimalSet.size(); i++) {
        binarySet.push_back(toBinaryString(decimalSet[i], numBits));
    }
    return binarySet;
}

// �������еĶ����Ʋ���
vector<string> generateAllBinaryDifferences(vector<int>& decimalSet, int numBits) {
    vector<string> binarySet = convertToBinarySet(decimalSet, numBits);
    vector<string> binaryDifferences;
    for (int i = 0; i < binarySet.size(); i++) {
        for (int j = i + 1; j < binarySet.size(); j++) {
            string binaryDiff = generateBinaryDifference(decimalSet[i], decimalSet[j], numBits);
            binaryDifferences.push_back(binaryDiff);
        }
    }
    return binaryDifferences;
}

// ���������ʽת��Ϊʮ����������
vector<int> convertToDecimalSet(string expression) {
    vector<int> decimalSet;
    int numBits = expression.length();
    for (int i = 0; i < numBits; i++) {
        if (expression[i] == '1') {
            decimalSet.push_back(i);
        }
    }
    return decimalSet;
}

// �������Ʊ��ʽת��Ϊ�������ʽ
string convertToBooleanExpression(string binaryExpression) {
    string booleanExpression;
    int numBits = binaryExpression.length();
    for (int i = 0; i < numBits; i++) {
        if (binaryExpression[i] == '0') {
            booleanExpression += "~";
            booleanExpression += to_string(i);
        }
        else if (binaryExpression[i] == '1') {
            booleanExpression += to_string(i);
        }
    }
    return booleanExpression;
}