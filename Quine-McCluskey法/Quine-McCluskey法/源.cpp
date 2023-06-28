#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

// 计算两个数字的汉明距离
int hammingDistance(int a, int b) {
    int count = 0;
    int diff = a ^ b;
    while (diff) {
        count++;
        diff &= diff - 1;
    }
    return count;
}

// 将数字转换为二进制表示
string toBinaryString(int n, int numBits) {
    string binary = bitset<32>(n).to_string().substr(32 - numBits);
    return binary;
}

// 生成两个数的二进制差异
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

// 将十进制数集合转换为二进制数集合
vector<string> convertToBinarySet(vector<int>& decimalSet, int numBits) {
    vector<string> binarySet;
    for (int i = 0; i < decimalSet.size(); i++) {
        binarySet.push_back(toBinaryString(decimalSet[i], numBits));
    }
    return binarySet;
}

// 生成所有的二进制差异
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

// 将布尔表达式转换为十进制数集合
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

// 将二进制表达式转换为布尔表达式
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