#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
//#include "Animal.h"

using namespace std;
// ТЗ: Программа, для оргазицаии животных, по типу зоопарка(только виртуально), задача в том, чтобы иметь учет животных, и их характеристики


struct Animal
{
    string type;
    string name;
    string voice;
    string color;
    string gender;
    int number_of_steps = 0; 
};

int main()
{
    const char* Animals[3] = {"Cat","Dog","Horse"};
    //char animal_arr = new char[];
    int size = 5;
    
    Animal* box = new Animal[size];
    int menu, count = 0, type_animal, num = 0;
    string name, voice, color, string_type_animal, gender;
    do
    {
        cout << " --- Animal records --- " << endl;
        cout << "Main menu:\n" << "0.Exit\n1.Add animal at list\n2.Print list" << endl;
        cout << "Type number--->";
        cin >> menu;
        switch (menu)
        {
        case 1:
            system("cls");
            cout << "--Adding an animal--" << endl;

            cout << "What animal?\n0.Cat\n1.Dog\n2.Horse\n3.Other\nChoose your option - ";
            cin >> type_animal;
            
            if (type_animal == 3)
            {
                cout << "What is kind of animal? ";
                cin >> string_type_animal;
                cout << "What is " << string_type_animal << " name? ";
                cin >> name;
                cout << "What is " << string_type_animal << " color? ";
                cin >> color;
                cout << "Whats is the sound of this " << string_type_animal << "? ";
                cin >> voice;
                cout << "What gender of " << string_type_animal << "? (male & female)";
                cin >> gender;
            }
            else
            {
                string_type_animal = Animals[type_animal];
                cout << "What is " << string_type_animal << " name? ";
                cin >> name;
                cout << "What is " << string_type_animal << " color? ";
                cin >> color;
                cout << "What gender of " << string_type_animal << "? ";
                cin >> gender;
            }
            if (type_animal == 0)
            {
                voice = "Meow";
                num = 25;
            }
            if (type_animal == 1)
            {
                voice = "Woof";
                num = 16;
            }
            if (type_animal == 2)
            {
                voice = "EHGOGO";
                num = 40;
            }
            
            box[count].type = string_type_animal;
            box[count].name = name;
            box[count].color = color;
            box[count].voice = voice;
            box[count].gender = gender;
            box[count].number_of_steps = num;
            count++;
            system("cls");
            Sleep(1000);
            cout << "Complete, data recorded." << endl;
            Sleep(2000);
            system("cls");
            break;
        case 2:
            system("cls");
            for (int i = 0; i < size; i++)
            {
                if (box[i].type.empty())
                {
                    break;
                }
                else
                    
                    cout << "The " << i + 1 << " animal is " << box[i].type << endl;
                    
                    cout << "Name are: " << box[i].name << endl;
                    cout << "Color: " << box[i].color << endl;
                    cout << "It say: " << box[i].voice << endl;
                    cout << "An " << box[i].type << " can walk about " << box[i].number_of_steps << " km per day" << endl << endl;
            }
            cout << "Press any key to continue...";
            cin.ignore(256, '\n');
            cin.get();
            system("cls");
            break;

        default:
            cout << "Please enter a valid value" << endl;
            break;

        }
    } while (menu != 0);
    system("cls");
    cout << "The program has successfully completed its work!\nThanks for using:)" << endl;
}
