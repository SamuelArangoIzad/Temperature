#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
int main(){
    string input;
    float sum = 0.0;
    int count = 0;
    float mayor = numeric_limits<float>::lowest();
    float menor = numeric_limits<float>::max();
    string exitKeyword = "done";
    vector<float>aboveAverage;
    vector<float>belowAverage;
    cout << "Enter Numbers Separated By Commas (Type " << exitKeyword << " To Finish): " << endl;
    getline(cin, input);
    //Changes The Log In And Word Pass To Min
    transform(input.begin(),input.end(),input.begin(),::tolower);
    transform(exitKeyword.begin(),exitKeyword.end(),exitKeyword.begin(),::tolower);
    //Use A StringStream For Split The Enter In Numbers
    stringstream ss(input);
    string token;
    while(getline(ss, token, ',')){
        //Transfrom The Login To Min
        transform(token.begin(),token.end(),token.begin(),::tolower);
        //Verify It Is Possible The User Wishes Exit
        if(token==exitKeyword)
        {
            break;
        }
        //Transform The LogIn In Numbers
        try{
            float number=stof(token);
            sum += number;
            count++;
            //Update The Numbers Max To Min
            mayor = max(mayor, number);
            menor = min(menor, number);
            //Choose The Temperatures By Up Or Down Of The Promedy
            if(number > (sum/count)){
                aboveAverage.push_back(number);
            }else{
                belowAverage.push_back(number);
            }
        }catch(invalid_argument &){
            cout << "Invalid Input. Enter The Numbers Separated By Commas Please Or " << exitKeyword << "To Finish. " << endl;
            return 1;
        }
    }
    //Outside The While Loop Thus Allowing Iteration Of The Final Data
        if(count > 0)
        {
            float average=sum/count;
            cout << "Average: " << average << endl;
            cout << "Maximum Temperature: " << mayor << endl;
            cout << "Minimum Temperature: " << menor << endl;
            cout << "Temperatures Above Average: ";
            for(const auto &temp : aboveAverage){
                cout << temp << " ";
            }
            cout << endl;
            cout << "Temperatures Nelow Average: ";
            for(const auto &temp : belowAverage){
                cout << temp << " ";
            }
            cout << endl;
        }else
        {
            cout << "No Valid Numbers Entered. " << endl;
        }
    return 0;
}