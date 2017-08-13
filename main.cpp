//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// spell_checker  ID: 1673177
// main.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "small_dictionary.h"

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// declarations
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

long Compute_DL_distance(std::string a, std::string b);
static void myfunction();
long GetSelection1();
long GetSelection2();
void OutputLine(const std::string & text);
int Pause();

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// main()
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int main(int argc, char** argv) 
{
    OutputLine("//*******Spell checker 1.0***** made by 1673177**************");
    OutputLine("//****************the program to check word******************");
      
    std::string str0;
    while (str0 != "q") // make continues by using while
    {
    myfunction();
    Pause();
    
    OutputLine("\nInput any character to continue ");
    OutputLine("\nOr input 'q' to exit: ");
    std::getline(std::cin,str0);
    }
    
    return 0;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// myfunction
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

static void myfunction() 
{
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //main function part
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    
    long size = GetSize();
    long i = 0;
    long j = 1;
    long n = 0;
    
    std::string st;
    
    std::cout << "Please, input a word: ";
    std::getline(std::cin,st);
    
    std::vector<std::string> options(5);
    
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // check the word in the dictionary
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     
    while (n != size)
    {
     std::string this_ch = GetCh(n);
     
     if (st == this_ch)
         {
         j = size +1;     //using define the number of j to jump to output line
         break; 
         }
     else
     ++n;
    } 
    
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // to get the word distance = 1 
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX   
    if (j < 5)
    {
    while (i != size)
    {
     std::string this_ch = GetCh(i);
     long distance = Compute_DL_distance(st, this_ch);
     if (distance == 1)
     {
         options[j - 1] = this_ch;
         ++j;
     }
     ++i;
    } 
    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // to get the word distance == 2 
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
          
    if (j < 5)
    {
        double k = 0;
        while ( k != size)
        {
            std::string this_ch = GetCh(k);
            long distance = Compute_DL_distance(st, this_ch);
            if (distance == 2 )
               if(j < 6)
               {    options[j-1] = this_ch;
                    ++j;
               }
            ++k;
        }
    }    
    
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    // to output at most 5 option words 
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 
 
    if (j < 5)
    {     
        if (j == 1)  
           std::cout << "Sorry, there is no suggestion word.\n" <<std::endl;        
        else
          {
            for (long m=0 ; m<j; m++)
            std::cout << "The NO." << m+1 <<" suggestion word is: " << options[m] <<std::endl;
          }
    }
    else
    {
        if (j > size)
        {OutputLine("Correct word has already been in dictionary");
        OutputLine("Please Enter 3 to move on next word");
        }
        else
        {
        for (long m=0 ; m<5; m++)
        std::cout << "The NO." << m+1 <<" suggestion word is: " << options[m] <<std::endl;
        }
    }
    
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //switch(choose1)
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    
    long choose1 = GetSelection1();
    long choose2;
    std::string str1;
    
    switch(choose1)
    {
        case 1: choose2 = GetSelection2();
                str1 = options[choose2 - 1];
                std::cout << "Your selection word is: " << str1 <<std::endl;
                break;
               
        case 2: Add_word(st);
                break;
               
        default:
                break;
    }
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	Compute_DL_distance
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//Using Dynamic programming to solve DL distance.
long Compute_DL_distance(std::string a, std::string b)
{
    unsigned long len1 = a.size();    
    unsigned long len2 = b.size(); 
    
    std::vector<long> col1(len2+1), col2(len2+1), col3(len2+1);
    
    for (unsigned long i = 0; i < len2 + 1; i++) col2[i] = i;
    for (unsigned long i = 0; i < len1; i++)
    {
        col1[0] = i + 1;
        for (unsigned long j = 0; j < len2; j++)
            {
            long c =  (a[i] == b[j] ? 0 : 1);
            col1[j + 1] = std::min({col2[1 + j] + 1, col1[j] + 1, col2[j] + c});
            }
            col3 = col2;
            col2 = col1;
            col1 = col3;
    }       
    return col2[len2];
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// GetSelection2()
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

long GetSelection2()
{
    std::cout << "\nPlease enter the number of word. \n";
    
    long cho;
    std::cout << "Please, do your selection: ";
    std::cin >> cho;
    return cho;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	OutputLine
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void OutputLine(const std::string & text)
{
    std::cout << text << std::endl;
}
  
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// Pause
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int Pause()
{
    std::cout << "";
    std::cin.get();
    
    return 0;
}
    
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	GetSelection
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

long GetSelection1()
{
    std::cout << "\nEnter 1 = Choose One of the suggested words as correction. \n";
    std::cout << "Enter 2 = Add the entered word to the dictionary. \n";
    std::cout << "Enter 3 = Re-enter the word. \n";
    
    long choose;
    std::cout << "Please, do your selection: ";
    std::cin >> choose;
    
    return choose;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// end of file
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 

