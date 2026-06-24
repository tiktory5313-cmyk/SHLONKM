#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <boost/beast/core/detail/base64.hpp>
#include <openssl/evp.h>
#include <vector>

using namespace std;
namespace base64 = boost::beast::detail::base64;

string user_name;
string Input_user_for_Running;
bool status_loop1 = false;
bool status_loop2 = true;
string Input_to_contorol;
string encoding_text_input_user;
string yes_no_to_save_files1, yes_no_to_save_files2, yes_no_to_save_files3;
string encoded, decoded;
string re_en_def, re_de_def, re_sh_def;
string text, algos, algo, selected_algo;
int choice;

void GUI_for_user(){
    system("clear");
    cout << "" << endl;
    cout << "Enter your name: ";
    cin >> user_name;
    cout << "=======================================================" << endl;
    cout << "" << endl;
    cout << "Your name: " << user_name << endl;
    cout << "" << endl;
    cout << "Address, place, your name in memory: " << &user_name << endl;
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
    cin >> Input_user_for_Running;
}

void Input_to_encoding(){
    system("clear");
    cout << "" << endl;
    cout << "You are now in a situation /encoding" << endl;
    cout << "" << endl;
    cout << "Enter your text to perform the encoding process: ";
    cin >> encoding_text_input_user;
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
    cin >> encoding_text_input_user;
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

void create_files2(){

    std::ofstream outFile(user_name);
    if (outFile.is_open()) {
        outFile << "account name ===) " << user_name << endl;
        outFile << "" << endl;
        outFile << "your Encoded Text ===) " << encoding_text_input_user << endl;
        outFile << "" << endl;
        outFile << "your Decoded ===) " << re_de_def << endl;
        outFile << "" << endl;
        outFile << "From the products of the Iraqi company shlonkm" << endl;
        outFile.close();
        system("clear");
        cout << "" << endl;
        cout << "===) Done: File created at (=== " << user_name << endl;
        cout << "" << endl;
        } else {
            cout << "Error: Could not create the file." << endl;
        }
}

void create_files1(){
    std::ofstream outFile(user_name);
    
    if (outFile.is_open()) {
        outFile << "account name ===) " << user_name << endl;
        outFile << "" << endl;
        outFile << "your Text ===) " << encoding_text_input_user << endl;
        outFile << "" << endl;
        outFile << "your Encoded ===) " << re_en_def << endl;
        outFile << "" << endl;
        outFile << "From the products of the Iraqi company shlonkm" << endl;
        outFile.close();
        system("clear");
        cout << "" << endl;
        cout << "===) Done: File created at (=== " << user_name << endl;
        cout << "" << endl;
        } else {
            cout << "Error: Could not create the file." << endl;
        }
}

void create_files3(){
    std::ofstream outFile(user_name);

    if (outFile.is_open()) {
        outFile << "account name ===) " << user_name << endl;
        outFile << "" << endl;
        outFile << "your Text ===) " << text << endl;
        outFile << "" << endl;
        outFile << "your hashed ===) " << re_sh_def << endl;
        outFile << "" << endl;
        outFile << "Hash algorithm ===) " << selected_algo << endl;
        outFile << "" << endl;
        outFile << "From the products of the Iraqi company shlonkm" << endl;
        outFile.close();
        system("clear");
        cout << "" << endl;
        cout << "===) Done: File created at (=== " << user_name << endl;
        cout << "" << endl;
        } else {
            cout << "Error: Could not create the file." << endl;
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
    while (cin.fail() || choice < 1 || choice > 17) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Try again (1-17): ";
            cin >> choice;
    }
    cout << "Enter your Text to perform the hashing process: ";
    cin >> text;
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
    cin >> yes_no_to_save_files3;
    if(yes_no_to_save_files3 == "/yes" || yes_no_to_save_files3 == "/y"){
        create_files3();
    } else if(yes_no_to_save_files3 == "/no" || yes_no_to_save_files3 == "/n"){
        cout << "" << endl;
        cout << "The file was not created as requested." << endl;
        cout << "" << endl;
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
    cin >> yes_no_to_save_files2;
    if(yes_no_to_save_files2 == "/yes" || yes_no_to_save_files2 == "/y"){
        create_files2();
    } else if(yes_no_to_save_files2 == "/no" || yes_no_to_save_files2 == "/n"){
        cout << "" << endl;
        cout << "The file was not created as requested." << endl;
        cout << "" << endl;
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
    cin >> yes_no_to_save_files1;
    if(yes_no_to_save_files1 == "/yes" || yes_no_to_save_files1 == "/y"){
        create_files1();
    } else if(yes_no_to_save_files1 == "/no" || yes_no_to_save_files1 == "/n"){
        cout << "" << endl;
        cout << "The file was not created as requested." << endl;
        cout << "" << endl;
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
            Input_user_for_Running != "../" && Input_user_for_Running != "/clean") 
            {
                cout << "" << endl;
                cout << "Error in your input ===) " << Input_user_for_Running << endl;
                cout << "" << endl;
                Input_to_Running(); 
            }
          if(Input_user_for_Running == "/clean"){
            system("clear");
        } else if(Input_user_for_Running == "1" || Input_user_for_Running == "/encoding"){
            Input_to_encoding();
            Q_user_create_files1();
            while(yes_no_to_save_files1 != "/y" && yes_no_to_save_files1 != "/yes" && yes_no_to_save_files1 != "/n" && yes_no_to_save_files1 != "/no" && yes_no_to_save_files1 != "../") {
                cout << "" << endl;
                cout << "Error in your input ===) " << yes_no_to_save_files1 << endl;
                cout << "" << endl;
                Q_user_create_files1();
            }
        } else if(Input_user_for_Running == "2" || Input_user_for_Running == "/hashing"){
           hash_def_clreator();
           Q_user_create_files3();
           while(yes_no_to_save_files3 != "../" && yes_no_to_save_files3 != "/yes" && yes_no_to_save_files3 != "/y" && yes_no_to_save_files3 != "/no" && yes_no_to_save_files3 != "/n"){
                cout << "" << endl;
                cout << "Error in your input ===) " << Q_user_create_files3 << endl;
                cout << "" << endl;
                Q_user_create_files3();
            }
        } else if(Input_user_for_Running == "3" || Input_user_for_Running == "/decoding"){
            Input_to_decoding();
            Q_user_create_files2();
            while(yes_no_to_save_files2 != "../" && yes_no_to_save_files2 != "/yes" && yes_no_to_save_files2 != "/y" && yes_no_to_save_files2 != "/no" && yes_no_to_save_files2 != "/n"){
                cout << "" << endl;
                cout << "Error in your input ===) " << yes_no_to_save_files2 << endl;
                cout << "" << endl;
                Q_user_create_files2();
            }
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