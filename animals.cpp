// “естирование русских букв
#include<iostream>
#include<string>
#include <sstream>

using namespace std;

struct Animal{
    string question = "";
    string answear = "";
    Animal *p_yes = nullptr;
    Animal *p_no = nullptr;

        ~Animal(){
            if (p_yes) delete p_yes;
            if (p_no) delete p_no;
        }
};

bool yes(){
    char ch;
    cin.clear();
    cin.sync();
    cin >> ch;

    return ch == 'y';
}
/**
    * создает экземпл€р
    *
    * @param string current_answear, ответ на уточн€ющий вопрос
*/
Animal* create(string current_answear){
    Animal *result = new Animal();
    stringstream strings;
    string str;
    cin.clear();
    cin.sync();
    cout << "OK! Who is it?" << std::endl;
    while (getline(std::cin, str)) { strings << str; };
    result->answear = strings.str();
    //std::cin >> result->answear;
    cout << "What the difference between " << result->answear << " and " << current_answear << std::endl;
    //std::getline(std::cin, result->question);
    strings.str("");
    strings.clear();
    cin.clear();
    cin.sync();
    while (getline(std::cin, str)){ strings << str; };
    result->question = strings.str();
    result->question.append("?");

    return result;
}

int main(){
    Animal init {"it catch mice?", "cat", nullptr, nullptr};
    
    do {
        Animal *current = &init;
        cout << "Think an animal, and I will try to guess by asking leading questions." << std::endl;
        while (true) {
            cout << current->question << std::endl;
            if (yes()) {
                cout << "This is " << current->answear << ". Guess?" << std::endl;
                if (yes()) {
                    cout << "I am win!!!" << std::endl;
                    break;
                }
                else 
                    if (current->p_yes == nullptr) {
                        current->p_yes = create(current->answear);
                        break;
                    }
                    else current = current->p_yes;
            }
            else 
                if (current->p_no == nullptr) {
                    current->p_no = create(current->answear);
                    break;
                }
                else current = current->p_no;    
        }
        cout << "Continue?" << std::endl;     
    } while (yes());
}