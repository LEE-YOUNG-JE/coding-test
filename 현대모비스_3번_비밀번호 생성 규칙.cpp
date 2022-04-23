#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string inp_str) {
    vector<int> answer;
    //cout << "1 = " << inp_str[6] - 0 << endl;
    //cout << "* = " << '*' - 0 << endl;

    //cout << "inp_str = " << inp_str << endl;
    int length = 0;
    bool length_check = true;
    int count_what_char[5] = {0}; //종류 개수 저장
    int m_sum = 0; //종류개수 카운트
    bool answer_result[6] = {false}; //이미 추가했는지 판단
    int four_count = 0; //4개 연속 판단
    int five_count = 0; //5개 판단
    for(int i = 0; i < inp_str.size(); i++){ //1
        length += 1;
        if(length > 15){

            answer.push_back(1);
            answer_result[1] = true;
            //length_check = false;
            break;
        }
    }//1
    if(length < 8 && answer_result[1] == false){
        answer.push_back(1);
        answer_result[1] = true;
        //length_check = false;
    }

    for(int i = 0; i < inp_str.size(); i++){//2
        int num = inp_str[i] - 0;
        int check_char = 0;
        if(num >= 65 && num <= 90) {
            count_what_char[1] = 1;
            continue;
        }
        if(num >= 97 && num <= 122){
            count_what_char[2] = 1;
            continue;
        }
        if(num >= 48 && num <= 57) {
            count_what_char[3] = 1;
            continue;
        }
        if(num == 126 || num == 33){
            count_what_char[4] = 1;
            continue;
         } //~ !
        if(num == 64 || num == 35){
            count_what_char[4] = 1;
            continue;
        } //@ #
        if(num == 36 || num == 37){
            count_what_char[4] = 1;
            continue;
        } //$ %
        if(num == 94 || num == 38){
           count_what_char[4] = 1;
           continue;
        }  //^ &
        if(num == 42){
            count_what_char[4] = 1;
            continue;
        } //*
        if(answer_result[2] == false){
            answer.push_back(2);
            answer_result[2] = true;
        } 
        //break;
    }//2

    for(int i = 1; i <= 4; i++){//3
        m_sum += count_what_char[i]; 
    }//3
    if(m_sum < 3){
        answer_result[3] = true;
        answer.push_back(3);
    } 



    for(int i = 1; i < inp_str.size(); i++){//4
        if(inp_str[i] == inp_str[i-1]) four_count += 1;
        else four_count = 0;

        if(four_count >= 3 && answer_result[4] == false){
            answer.push_back(4);
            answer_result[4] = true;
        }
    }//4

    sort(inp_str.begin(), inp_str.end());
    for(int i = 0; i < inp_str.size(); i++){//5
        if(inp_str[i] == inp_str[i-1]) five_count += 1;
        else five_count = 0;

        if(five_count >= 4 && answer_result[5] == false){
            answer.push_back(5);
            answer_result[5] = true;
        }
    }//5

    if((answer_result[1] == false) && (answer_result[2] == false) 
    && (answer_result[3] == false) && (answer_result[4] == false)
    && (answer_result[5] == false))
    answer.push_back(0);

    return answer;
}