#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <openssl/evp.h>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <boost/beast/core/detail/base64.hpp>

using namespace std;
namespace base64 = boost::beast::detail::base64;

vector<char*> parse_command(const string& cmd) {
    vector<char*> args;
    stringstream ss(cmd);
    string token;
    while (ss >> token) {
        char* arg = new char[token.size() + 1];
        copy(token.begin(), token.end(), arg);
        arg[token.size()] = '\0';
        args.push_back(arg);
    }
    args.push_back(nullptr); // يجب أن تنتهي المصفوفة بـ nullptr دائماً
    return args;
}

string user_name;
string Input_user_for_Running;
const bool status_loop1 = false;
const bool status_loop2 = true;
string Input_to_contorol;
string encoding_text_input_user;
string yes_no_to_save_files1, yes_no_to_save_files2, yes_no_to_save_files3;
string encoded, decoded, input_files_name, password_var_save;
string re_en_def, re_de_def, re_sh_def, path;
string text, algos, algo, selected_algo, commands_run_in_terminal_linux;
int choice;
time_t now = time(0);

void informations_for_tools(){
    system("clear");
    system("figlet info mode | lolcat");
    cout << "" << endl;
    cout << "=====================================) Information about the tool, version 2.2 (=====================================" << endl;
    cout << "" << endl;
    cout << "Hello user, this tool or terminal application was designed by an Iraqi team affiliated with Shloncom Company." << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Hello user, you are now using the Shirazi tool" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "" << endl;
    cout << "one of the advanced tools in the field of data protection and encryption." << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "This tool was developed by the Nahj Al-Balagha 313 team, affiliated with the Iraqi company SHLONKM." << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "This tool works using commands stored in its source code," << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "and you can modify these commands as you wish because it is a fully open-source tool." << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Note: All text commands begin with /command, and numeric commands work as is." << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Visit our website on the Tor network http://zofjpdufbw7ump3gwt3iwm7uhw7t2jua5ky5tkcdtserr76btpt2rjad.onion/" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "================================(Tool commands)================================" << endl;
    cout << "" << endl;
    cout << "Command to enter encoding mode ----> 1 or /encoding" << endl;
    cout << "" << endl;
    cout << "Command to enter hash mode ----> 2 or /hashing" << endl;
    cout << "" << endl;
    cout << "Command to enter decoding mode ----> 3 or /decoding" << endl;
    cout << "" << endl;
    cout << "Command to save output to a file ----> /y or /yes" << endl;
    cout << "" << endl;
    cout << "Command not to save output to a file ----> /n or /no" << endl;
    cout << "" << endl;
    cout << "Go back command ----> ../" << endl;
    cout << "" << endl;
    cout << "Note: There are hidden commands in the tool; you need to read the source code to understand them. Thank you for your support." << endl;
    cout << "" << endl;
    cout << "===============================================================================" << endl;
    cout << "Press Enter to continue.....";
    cin.get();
    system("clear");
}

void GUI_for_user(){
    system("clear");
    cout << "" << endl;
    cout << "=============================) Shirazi tools 2.2 (=============================" << endl;
    cout << "" << endl;
    cout << "Enter the username: ";
    getline(cin, user_name);
    cout << "Enter the password: ";
    getline(cin, password_var_save);
    cout << "" << endl;
    cout << "=======================================================" << endl;
    cout << "" << endl;
    cout << "The username is: " << user_name << endl;
    cout << "" << endl;
    cout << "The password is: " << password_var_save << endl;
    cout << "" << endl;
    cout << "Address, place, username in memory: " << &user_name << endl;
    cout << "" << endl;
    cout << "Address, place, password in memory: " << &password_var_save << endl;
    cout << "" << endl;
    cout << "=======================================================" << endl;
    cout << "" << endl;
    cout << "Hello " << user_name << "." << endl;
    cout << "It works via commands and should be like this. /commands" << endl;
    cout << "" << endl;
    cout << "To close the tool, press on Ctrl + C " << endl;
    cout << "" << endl;
    //Features of our product
    cout << "" << endl;
}

void Input_to_Running(){
    cout << "=======================================================" << endl;
    cout << "" << endl;
    
    cout << "1 ===) /encoding" << endl;
    cout << "2 ===) /hashing" << endl;
    cout << "3 ===) /decoding" << endl;
    
    cout << "" << endl;
    cout << "=======================================================" << endl;
    cout << "" << endl;
    cout << "Enter the Mode Number: ";
     getline(cin, Input_user_for_Running);
}

void Input_to_encoding(){
    system("clear");
    cout << "" << endl;
    cout << "You are now in a situation /encoding" << endl;
    cout << "" << endl;
    cout << "Enter your text to perform the encoding process: ";
    getline(cin, encoding_text_input_user);
}

//generaet encoding 
string create_text_to_encoding(string en_coding){
    encoded.resize(base64::encoded_size(en_coding.size()));
    auto const result = base64::encode(&encoded[0], en_coding.data(), en_coding.size());
    encoded.resize(result);
    return encoded;
}

void Input_to_decoding(){
    system("clear");
    cout << "" << endl;
    cout << "You are now in a situation /decoding" << endl;
    cout << "" << endl;
    cout << "Enter your Encoded Text to perform the decoding process: ";
    getline(cin, encoding_text_input_user);
}

string create_text_to_decoding(string de_coding){
    decoded.resize(base64::decoded_size(de_coding.size()));
    auto const result = base64::decode(&decoded[0], de_coding.data(), de_coding.size());
    decoded.resize(result.first);
    return decoded;
}

string calculate_hash(string algo, string data) {
    const EVP_MD* md = EVP_get_digestbyname(algo.c_str());
    if (!md) return "Error: Invalid Algorithm or not supported on your system.";

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int len = 0;

    EVP_Digest(data.data(), data.size(), hash, &len, md, nullptr);

    char hex[EVP_MAX_MD_SIZE * 2 + 1];
    for (unsigned int i = 0; i < len; i++) sprintf(&hex[i * 2], "%02x", hash[i]);
    
    return hex;
}

bool create_files2(){

    std::ofstream outFile(input_files_name);
    if (outFile.is_open()) {
        outFile << "=======================) Shirazi tools 2.2 (=======================" << endl;
        outFile << "" << endl;
        outFile << "account name ===) " << user_name << endl;
        outFile << "" << endl;
        outFile << "password ===) " << password_var_save << endl;
        outFile << "" << endl;
        outFile << "your Encoded Text ===) " << encoding_text_input_user << endl;
        outFile << "" << endl;
        outFile << "your Decoded ===) " << re_de_def << endl;
        outFile << "" << endl;
        outFile << "The time ===) " << ctime(&now);
        outFile << "" << endl;
        outFile << "From the products of the Iraqi company, SHLONKM" << endl;
        outFile << "" << endl;
        outFile << "===================================================================" << endl;
        outFile << "" << endl;
        outFile.close();
        system("clear");
        cout << "" << endl;
        cout << "===) The file was created with this name: " << input_files_name << " (=== " << endl;
        cout << "" << endl;
        return true;
        } else {
            cout << "Error: Could not create the file." << endl;
            return false;
        }
}

bool create_files1(){
    std::ofstream outFile(input_files_name);
    
    if (outFile.is_open()) {
        outFile << "=======================) Shirazi tools 2.2 (=======================" << endl;
        outFile << "" << endl;
        outFile << "account name ===) " << user_name << endl;
        outFile << "" << endl;
        outFile << "password ===) " << password_var_save << endl;
        outFile << "" << endl;
        outFile << "your Text ===) " << encoding_text_input_user << endl;
        outFile << "" << endl;
        outFile << "your Encoded ===) " << re_en_def << endl;
        outFile << "" << endl;
        outFile << "The time ===) " << ctime(&now);
        outFile << "" << endl;
        outFile << "From the products of the Iraqi company, SHLONKM" << endl;
        outFile << "" << endl;
        outFile << "===================================================================" << endl;
        outFile << "" << endl;
        outFile.close();
        system("clear");
        cout << "" << endl;
        cout << "===) The file was created with this name: " << input_files_name << " (=== " << endl;
        cout << "" << endl;
        return true;
        } else {
            cout << "Error: Could not create the file." << endl;
            return false;
        }
}

bool create_files3(){
    std::ofstream outFile(input_files_name);

    if (outFile.is_open()) {
        outFile << "=======================) Shirazi tools 2.2 (=======================" << endl;
        outFile << "" << endl;
        outFile << "account name ===) " << user_name << endl;
        outFile << "" << endl;
        outFile << "password ===) " << password_var_save << endl;
        outFile << "" << endl;
        outFile << "your Text ===) " << text << endl;
        outFile << "" << endl;
        outFile << "your hashed ===) " << re_sh_def << endl;
        outFile << "" << endl;
        outFile << "Hash algorithm ===) " << selected_algo << endl;
        outFile << "" << endl;
        outFile << "The time ===) " << ctime(&now);
        outFile << "" << endl;
        outFile << "From the products of the Iraqi company, SHLONKM" << endl;
        outFile << "" << endl;
        outFile << "===================================================================" << endl;
        outFile << "" << endl;
        outFile.close();
        system("clear");
        cout << "" << endl;
        cout << "===) The file was created with this name: " << input_files_name << " (=== " << endl;
        cout << "" << endl;
        return true;
        } else {
            cout << "Error: Could not create the file." << endl;
            return false;
        }
}

void hash_def_clreator(){
    system("clear");
    vector<string> algos = {
        "MD4", "MD5", "SHA1", "RIPEMD160", 
        "SHA224", "SHA256", "SHA384", "SHA512", "SHA512-224", "SHA512-256",
        "SHA3-224", "SHA3-256", "SHA3-384", "SHA3-512",
        "BLAKE2S256", "BLAKE2B512", "SM3"
    };
    cout << "" << endl;
    cout << "You are now in a situation /hashing" << endl;
    cout << "" << endl;
     for (int i = 0; i < algos.size(); i++) {
        cout << "[" << i + 1 << "] " << algos[i] << "\n";
    }
    cout << "" << endl;
    cout << "Enter the number of the Hash Algorithm: ";
    cin >> choice;
    std::cin.ignore();
    while (cin.fail() || choice < 1 || choice > 17) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Try again (1-17): ";
            cin >> choice;
            std::cin.ignore();
    }
    cout << "Enter your Text to perform the hashing process: ";
   getline(cin, text);
    selected_algo = algos[choice - 1];
}

void Q_user_create_files3(){
    re_sh_def = calculate_hash(selected_algo, text);
    cout << "" << endl;
    cout << "====================================================" << endl; 
    cout << "your hash ===) " << re_sh_def << endl;//
    cout << "====================================================" << endl;
    cout << "" << endl;
    cout << "Do you want to save the output as a file?(y/n): ";
    getline(cin, yes_no_to_save_files3);
    if(yes_no_to_save_files3 == "/yes" || yes_no_to_save_files3 == "/y"){
        while(true){
            cout << "Enter your file name and type (e.g., report.txt): ";
            getline(cin, input_files_name);
            
            if (input_files_name.empty()) {
                cout << "[!] Error: You cannot leave the filename blank! Try again." << endl;
                cout << "----------------------------------------------------------" << endl;
                continue;
            } if((create_files3())){break;}
        }
    } else if(yes_no_to_save_files3 == "/no" || yes_no_to_save_files3 == "/n"){
        cout << "" << endl;
        cout << "The file was not created as requested." << endl;
        cout << "" << endl;
    } else if(yes_no_to_save_files3 == "/info" || yes_no_to_save_files3 == "313" || yes_no_to_save_files3 == "/shlonkm" || yes_no_to_save_files3 == "/shlonkm313"){
        informations_for_tools();
        Q_user_create_files3();
    }
}

void Q_user_create_files2(){
    re_de_def = create_text_to_decoding(encoding_text_input_user);
    cout << "" << endl;
    cout << "====================================================" << endl; 
    cout << "your decoded ===) " << re_de_def << endl;//
    cout << "====================================================" << endl;
    cout << "" << endl;
    cout << "Do you want to save the output as a file?(y/n): ";
    getline(cin, yes_no_to_save_files2);
    if(yes_no_to_save_files2 == "/yes" || yes_no_to_save_files2 == "/y"){
    while(true){
        cout << "Enter your file name and type (e.g., report.txt): ";
        getline(cin, input_files_name);

        if (input_files_name.empty()) {
            cout << "[!] Error: You cannot leave the filename blank! Try again." << endl;
            cout << "----------------------------------------------------------" << endl;
            continue;
        } if((create_files2())){break;}
    }
    } else if(yes_no_to_save_files2 == "/no" || yes_no_to_save_files2 == "/n"){
        cout << "" << endl;
        cout << "The file was not created as requested." << endl;
        cout << "" << endl;
    } else if(yes_no_to_save_files2 == "/info" || yes_no_to_save_files2 == "313" || yes_no_to_save_files2 == "/shlonkm" || yes_no_to_save_files2 == "/shlonkm313"){
        informations_for_tools();
        Q_user_create_files2();
    }
}

void Q_user_create_files1(){
    re_en_def = create_text_to_encoding(encoding_text_input_user);
    cout << "" << endl;
    cout << "====================================================" << endl; 
    cout << "your encoded ===) " << re_en_def << endl;//
    cout << "====================================================" << endl;
    cout << "" << endl;
    cout << "Do you want to save the output as a file?(y/n): ";
    getline(cin, yes_no_to_save_files1);
    if(yes_no_to_save_files1 == "/yes" || yes_no_to_save_files1 == "/y"){
        while(true){
            cout << "Enter your file name and type (e.g., report.txt): ";
            getline(cin, input_files_name);

            if (input_files_name.empty()) {
                cout << "[!] Error: You cannot leave the filename blank! Try again." << endl;
                cout << "----------------------------------------------------------" << endl;
                continue;
            } if((create_files1())){break;}
        }
    } else if(yes_no_to_save_files1 == "/no" || yes_no_to_save_files1 == "/n"){
        cout << "" << endl;
        cout << "The file was not created as requested." << endl;
        cout << "" << endl;
    } else if(yes_no_to_save_files1 == "/info" || yes_no_to_save_files1 == "313" || yes_no_to_save_files1 == "/shlonkm" || yes_no_to_save_files1 == "/shlonkm313"){
        informations_for_tools();
        Q_user_create_files1();
    }
}

void Runnung_commands_in_shell_system(){
    system("clear");
    system("figlet Run Commands In System | lolcat");
    cout << "" << endl;
    
    commands_run_in_terminal_linux;
    while (true) {
        cout << "Shirazi-Shell> ";
        if (!getline(cin, commands_run_in_terminal_linux) || commands_run_in_terminal_linux == "/exit_shell" || commands_run_in_terminal_linux == "/exit_commands_system" || commands_run_in_terminal_linux == "/exit_commands_mode") break;
        if (commands_run_in_terminal_linux.empty()) continue;

        if (commands_run_in_terminal_linux.substr(0, 3) == "cd ") {
            path = commands_run_in_terminal_linux.substr(3);
            if (chdir(path.c_str()) != 0) {
                perror("cd failed");
            }
            continue;
        }
        vector<char*> args = parse_command(commands_run_in_terminal_linux);
        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args.data()) == -1) {
                perror("Execution failed");
            }
            exit(EXIT_FAILURE);
        } 
        else if (pid > 0) {
            waitpid(pid, nullptr, 0);
        } 
        else {
            perror("Fork failed");
        }
        for (char* arg : args) delete[] arg;
    }
}

int main()
{
    do{
        GUI_for_user();
    }while(status_loop1);
    while(status_loop2){
        Input_to_Running();
        while(Input_user_for_Running != "1" && Input_user_for_Running != "/encoding" &&
            Input_user_for_Running != "2" && Input_user_for_Running != "/hashing" &&
            Input_user_for_Running != "3" && Input_user_for_Running != "/decoding" &&
            Input_user_for_Running != "../" && Input_user_for_Running != "/clean" &&
            Input_user_for_Running != "/info" && Input_user_for_Running != "shlonkm313" &&
            Input_user_for_Running != "313" && Input_user_for_Running != "shlonkm" && 
            Input_user_for_Running != "/Run_commands_in_system" && Input_user_for_Running != "/Run_commands" && 
            Input_user_for_Running != "/system_commands") 
            {
                cout << "" << endl;
                cout << "command is not supported ===) " << Input_user_for_Running << endl;
                cout << "" << endl;
                cout << "Type the command /info to learn about the commands." << endl;
                cout << "" << endl;
                Input_to_Running();
            }
          if(Input_user_for_Running == "/clean"){
            system("clear");
        } else if(Input_user_for_Running == "1" || Input_user_for_Running == "/encoding"){
            Input_to_encoding();
            Q_user_create_files1();
            while(yes_no_to_save_files1 != "/y" && yes_no_to_save_files1 != "/yes" && yes_no_to_save_files1 != "/n" && yes_no_to_save_files1 != "/no" && yes_no_to_save_files1 != "../" && yes_no_to_save_files1 != "/info" && yes_no_to_save_files1 != "313" && yes_no_to_save_files1 != "/shlonkm" && yes_no_to_save_files1 != "/shlonkm313") {
                cout << "" << endl;
                cout << "command is not supported ===) " << yes_no_to_save_files1 << endl;
                cout << "" << endl;
                cout << "Type the command /info to learn about the commands." << endl;
                cout << "" << endl;
                Q_user_create_files1();
            }
        } else if(Input_user_for_Running == "2" || Input_user_for_Running == "/hashing"){
           hash_def_clreator();
           Q_user_create_files3();
           while(yes_no_to_save_files3 != "../" && yes_no_to_save_files3 != "/yes" && yes_no_to_save_files3 != "/y" && yes_no_to_save_files3 != "/no" && yes_no_to_save_files3 != "/n" && yes_no_to_save_files3 != "/info" && yes_no_to_save_files3 != "313" && yes_no_to_save_files3 != "/shlonkm" && yes_no_to_save_files3 != "/shlonkm313"){
                cout << "" << endl;
                cout << "command is not supported ===) " << yes_no_to_save_files3 << endl;
                cout << "" << endl;
                cout << "Type the command /info to learn about the commands." << endl;
                cout << "" << endl;
                Q_user_create_files3();
            }
        } else if(Input_user_for_Running == "3" || Input_user_for_Running == "/decoding"){
            Input_to_decoding();
            Q_user_create_files2();
            while(yes_no_to_save_files2 != "../" && yes_no_to_save_files2 != "/yes" && yes_no_to_save_files2 != "/y" && yes_no_to_save_files2 != "/no" && yes_no_to_save_files2 != "/n" && yes_no_to_save_files2 != "/info" && yes_no_to_save_files2 != "313" && yes_no_to_save_files2 != "/shlonkm" && yes_no_to_save_files2 != "/shlonkm313"){
                cout << "" << endl;
                cout << "command is not supported ===) " << yes_no_to_save_files2 << endl;
                cout << "" << endl;
                cout << "Type the command /info to learn about the commands." << endl;
                cout << "" << endl;
                Q_user_create_files2();
            }
        } else if(Input_user_for_Running == "/info" || Input_user_for_Running == "shlonkm" || Input_user_for_Running == "shlonkm313" || Input_user_for_Running == "313"){
            informations_for_tools();
        } else if(Input_user_for_Running == "/Run_commands_in_system" || Input_user_for_Running == "/Run_commands" || Input_user_for_Running == "/system_commands"){
            Runnung_commands_in_shell_system();
        } else if(Input_user_for_Running == "../"){
            GUI_for_user();
        } else if(yes_no_to_save_files1 == "../"){
            Input_to_Running();
        } else if(yes_no_to_save_files2 == "../"){
            Input_to_Running();
        } else if(yes_no_to_save_files3 == "../"){
            Input_to_Running();
        }
    }
    return 0;
}
