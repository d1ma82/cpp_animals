#include<iostream>
#include<string>

struct Animal{
    std::string question = "";
    std::string answear = "";
    Animal *p_yes = nullptr;
    Animal *p_no = nullptr;

        ~Animal(){
            if (p_yes) delete p_yes;
            if (p_no) delete p_no;
        }
};

bool yes(){
    char ch;
    std::cin >> ch;

    return ch == 'y';
}

Animal* create(std::string current_answear){
    Animal *result = new Animal();
    std::cin.clear();
    std::cin.sync();
    std::cout << "OK! Who is it?" << std::endl;
    std::getline(std::cin, result->answear);
    //std::cin >> result->answear;
    std::cout << "What the difference between " << result->answear << " and " << current_answear << std::endl;
    std::getline(std::cin, result->question);
    result->question.append("?");
    return result;
}

int main(){
    Animal init {"it catch mice?", "cat", nullptr, nullptr};
    
    do {
        Animal *current = &init;
        std::cout << "Think an animal, and I will try to guess by asking leading questions." << std::endl;
        while (true) {
            std::cout << current->question << std::endl;
            if (yes()) {
                std::cout << "This is " << current->answear << ". Guess?" << std::endl;
                if (yes()) {
                    std::cout << "I am win!!!" << std::endl;
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
        std::cout << "Continue?" << std::endl;     
    } while (yes());
}