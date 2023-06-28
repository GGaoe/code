#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
//Return the cards

int countt;//¿¨ÅÆÊýÁ¿
char card[101];
char* GetCards()
{
    char* cards = NULL;
    cards = &card[0];
    countt = 0;
    char put;
    for (; (put = getchar()) != '\n';) {
        *(cards+countt) = put; countt++;
    }
    return cards;
}
//ToDo
//Attention!! cards[i] is forbidden!!
int a[20];
int* num = &a[0];
int count1 = 0;
void SortCards(char* cards)
{
    for (int i = 0; i < countt; i++) {
        switch (*(cards + i)) {
        case'2': {*(num + 2) += 1; break; }
        case'3': {*(num + 3) += 1; break; }
        case'4': {*(num + 4) += 1; break; }
        case'5': {*(num + 5) += 1; break; }
        case'6': {*(num + 6) += 1; break; }
        case'7': {*(num + 7) += 1; break; }
        case'8': {*(num + 8) += 1; break; }
        case'9': {*(num + 9) += 1; break; }
        case'T': {*(num + 10) += 1; break; }
        case'J': {*(num + 11) += 1; break; }
        case'Q': {*(num + 12) += 1; break; }
        case'K': {*(num + 13) += 1; break; }
        case'A': {*(num + 1) += 1; break; }
        }
    }
   
    for (int i = 1; i <= *(num + 2); i++) {
        *(cards + count1) = '2'; count1++;
    }
    for (int i = 1; i <= *(num + 1); i++) {
        
        *(cards + count1) = 'A'; count1++;
    }
    for (int i = 1; i <= *(num + 13 ); i++) {
        
        *(cards + count1) = 'K'; count1++;
    }
    for (int i = 1; i <= *(num + 12 ); i++) {
        
        *(cards + count1) = 'Q'; count1++;
    }
    for (int i = 1; i <= *(num + 11); i++) {
        
        *(cards + count1) = 'J'; count1++;
    }
    for (int i = 1; i <= *(num + 10); i++) {
        
        *(cards + count1) = 'T'; count1++;
    }
    for (int j = 9; j >= 3; j--) {
        for (int i = 1; i <= *(num + j); i++) {
            
            *(cards + count1) = j+'0'; count1++;
        }
    }
}
//Output the sorted cards
//ToDo
void Output(char* cards)
{
    cout << cards;
}
int main()
{
    char* cards = GetCards();
    SortCards(cards);
    Output(cards);
    return 0;

}
