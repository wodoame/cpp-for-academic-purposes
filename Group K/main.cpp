#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <windows.h>
using std::cout;
using std::cin; 
using std::getline; 
using std::ws; 
using std::endl; 
using std::string;
using std::fstream; 
using std::ios;
using std::vector;
using std::stoi; 
using std::to_string;


class Profile{
    private:
        string name; 
        int assigned_line, checkpoint, choice;
    public: 
        void set_name(string name_){
            name = name_; 
        }

        string get_name(){
            return name;
        }

        void set_line(int line_number){
            assigned_line = line_number; 
        }

        int get_line(){
            return assigned_line; 
        }

        void set_checkpoint(int next_checkpoint){
           checkpoint = next_checkpoint; 
        }

        void set_choice(int previous_choice){
            choice = previous_choice;
        }
};


class Manager{
    private: 
        int profile_count;
    public: 
     
    

     // validates user input
     int check_input(string message, string error_message, int start, int end){
        int option; 
        bool data_is_valid;
        do{
            cout << message; 
            cin >> option; 
            if(cin.fail()){
                cin.clear();
                fflush(stdin);
            }
            data_is_valid = (option >= start && option <= end); // checks if option is with the bounds
            if(!data_is_valid){
            cout << error_message; 
        }
        }while(!data_is_valid);

        return option; 
     }
            

     // adds data to a file
     void append_to_file(string filename, string data){
        fstream file;
        file.open(filename, ios::app);
        if(file.is_open()){
            file << data;
        }
        file.close();
     }
     
     // show the profiles in the game, also counts profiles
     void show_profiles(string filename, bool assign_numbers){
        fstream file; 
        int line_number = 1;
        file.open(filename, ios::in);
        if(file.is_open()){
            string line; 
            while(getline(file, line)){
                if(assign_numbers){
                    cout << line_number << " - " << line << "\n";
                    line_number++; 
                }
                else{
                    cout << line << "\n";
                }
            }
        }

        profile_count = line_number - 1;
        file.close();
     }
     
     void readlines(string filename, int start, int end){
        fstream file; 
        file.open(filename, ios::in);
        int line_number = 1; 
        if(file.is_open()){
            string line; 
            system("cls");
            while(getline(file, line)){
                if(line_number >= start && line_number <= end){
                  type(line); 
                }
                if(line_number > end)break; 
                line_number++; 
            }
        }
        file.close(); 
     }
     // gets data from a particular line of a file
     string readline(string filename, int line_number){
         fstream file;
         int i = 1; 
         string line; 
         file.open(filename, ios::in);
         if(file.is_open()){
            while(getline(file, line)){
                if(line_number == i){
                    break;
                }
                else{
                    i++;
                }
            }
         }
         file.close(); 
         return line;
     }  


     // returns number of profiles
     int getCount(){
        return profile_count;
     }

     void remove(string filename, int assigned_line){
      fstream file; 
      vector<string> gamedatas; 
      file.open(filename, ios::in);
      if(file.is_open()){
        string line;
        while(getline(file, line)){
            gamedatas.push_back(line);
        }
      } 
      file.close();
      file.open(filename, ios::out);
      file << ""; 
      gamedatas.at(assigned_line - 1) = "\0"; // strings can be set equal to each other
      file.close();
      file.open(filename, ios::app);
      for(string element:gamedatas){
        if(element.length() == 0)continue;
        file << element.append("\n");
      }
     }

     void set_gameData(string filename, int assigned_line,  int data){
      fstream file; 
      vector<string> gamedatas;
      file.open(filename, ios::in);
      if(file.is_open()){
        string line;
        while(getline(file, line)){
            gamedatas.push_back(line);
        }
      } 
      file.close(); 
      file.open(filename, ios::out);
      file << ""; 
      file.close();
      file.open(filename, ios::app); 
      gamedatas.at(assigned_line - 1) = to_string(data);
      for(string element: gamedatas){
        file << element.append("\n"); 
      }
      file.close();
     }

    void type(string message){
        for(int i=0; i < message.length(); i++){
            cout << message.at(i); 
            Sleep(15);
        }
        cout << "\n"; 
    }
}; 

int main(){
    int option;
    Profile profile;
    Manager manager;
    start:
    option = manager.check_input(
        "\nChoose an option\n----------------\n1 - New Game: start a whole new game\n2 - Load Game: continue your adventure\n\n>> ",
        "\nmessage: no such option available\n",
        1, 2);
    if(option == 1){
        string name; 
        cout << "\nEnter profile name >> "; 
        getline(cin >> ws, name);
        cout << "\nmessage: profile '" << name << "' created successfully\n";
        manager.append_to_file("profiles.txt", name.append("\n"));
        manager.append_to_file("checkpoints.txt", "0\n");
        manager.append_to_file("choices.txt", "0\n");
        goto start; 
    }
    else{
        cout << "\nChoose a profile" << "\n----------------\n"; 
        manager.show_profiles("profiles.txt", true);
        if(manager.getCount() == 0){
            cout << "message: no profiles created yet, start a new game instead\n";
            goto start;
        }
        option = manager.check_input(
            "\n\n>> ", 
            "\nmessage: no such profile available\n",
            1, manager.getCount()
            );

        profile.set_name(manager.readline("profiles.txt", option));
        profile.set_line(option);
    }
    cout << "\nselected profile: " << profile.get_name() << "\n----------------\n"; 
    option = manager.check_input(
         "\nactions\n-------\n1-Continue to game\n2-Delete profile\n\n>> ",
         "\nmessage: invalid action\n", 
         1, 2
    );
    if(option == 2){
        manager.remove("profiles.txt", profile.get_line());
        manager.remove("checkpoints.txt", profile.get_line());
        manager.remove("choices.txt", profile.get_line());
        cout << "profile '" << profile.get_name() << "' deleted successfully\n";
    }
    else{
        string checkpoint, choice, gamedata, file = "story.txt"; 
        int quit = 0; 
        do{
        checkpoint = manager.readline("checkpoints.txt", profile.get_line());
        choice = manager.readline("choices.txt", profile.get_line());
        gamedata = checkpoint.append(choice); 

        if(gamedata == "00"){ manager.readlines(file, 3, 7); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "1";}
        else if(gamedata == "11"){ manager.readlines(file, 11, 15); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "2";}
        else if(gamedata == "12"){ manager.readlines(file, 20, 25); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "7";}
        else if(gamedata == "21"){ manager.readlines(file, 31, 39); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "3";}
        else if(gamedata == "22"){ manager.readlines(file, 43, 45); checkpoint = "-1";} // end
        else if(gamedata == "31"){ manager.readlines(file, 49, 58); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "4";}
        else if(gamedata == "32"){ manager.readlines(file, 62, 64); checkpoint = "-1";} // end
        else if(gamedata == "41"){ manager.readlines(file, 70, 71); checkpoint = "-1"; } // end
        else if(gamedata == "42"){ manager.readlines(file, 74, 81); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "5";}
        else if(gamedata == "51"){ manager.readlines(file, 87, 94); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "6";}
        else if(gamedata == "52"){ manager.readlines(file, 97, 100); checkpoint = "-1";} // end
        else if(gamedata == "61"){ manager.readlines(file, 106, 111); checkpoint = "-1";} // end
        else if(gamedata == "62"){ manager.readlines(file, 114, 118); checkpoint = "-1";} // end
        else if(gamedata == "71"){ manager.readlines(file, 124, 133); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "8";}
        else if(gamedata == "72"){ manager.readlines(file, 136, 146); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "-1";}
        else if(gamedata == "81"){ manager.readlines(file, 152, 157); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "9";}
        else if(gamedata == "82"){ manager.readlines(file, 160, 164); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "-1";}
        else if(gamedata == "91"){ manager.readlines(file, 168, 173); option = manager.check_input("\n>> ", "", 1, 2); checkpoint = "10";} 
        else if(gamedata == "92"){ manager.readlines(file, 176, 180); checkpoint = "-1";} // end
        else{quit = 1;}

        manager.set_gameData("checkpoints.txt", profile.get_line(), stoi(checkpoint));
        manager.set_gameData("choices.txt", profile.get_line(), option);

        }while(quit == 0);
    }
    return 0;
}