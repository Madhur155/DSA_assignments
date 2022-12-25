// Write a C++ program to perform infix to postfix conversion using stack.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int prec(char c){               //function to see precedance order of an operator 
    if(c=='^')
    return 3;
    else if(c == '/' || c == '*')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void infix_to_postfix(string s){              //main function for conversion infix to postfix
    string res;                               //resultant string
    stack<int> st;                            //declaring stack 
    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            res+=s[i];                       // if any number or digit is inserted insert it into the resultant string
        }
        
        else if(s[i]=='('){
            st.push(s[i]);                  //if '(' is there push it into the stack
        }

        else if(s[i]==')'){                 //if')' comes remove the elements from the stack till '(' doesn't come 
            while(st.top() != '('){
                res+=st.top();
                st.pop();
            }
            st.pop();                      //finally pop'(' from stack
        }

        else{                     //when any operator comes we check it's precedence any insert it accordingly
            while(!st.empty() && prec(s[i]) <= prec(st.top())){             
                res+=st.top();
                st.pop();
            }            
            st.push(s[i]);
        }
        }

        // Pop all the remaining elements from the stack
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
    cout<<res<<endl;
}

int main()
{
    string s;
    cout<<"Enter infix expression ";
    cin>>s;
    cout<<"postfix expression is :  " ;
    infix_to_postfix(s);
return 0;
}