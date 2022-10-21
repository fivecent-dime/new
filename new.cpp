#include<thread> 
#include<iostream> // popen, pclose
#include<string> 

/*
creates a new instance of a cmd like kate in a new thread and stops stdout 
so you can use the teriminal while kate is running 
*/

int main(int argc, char** argv){
    // argv[0] == new
    // this removes argv[0]
    // i.e new kate -> kate
    std::string command;
    for(int i = 1; i < argc; i++){
        command+=(std::string)argv[i]+" ";
    }
    std::thread thread = std::thread([=](){
        popen((command+/*stops stdout*/" 2>/dev/null").c_str(),"w"); // executes cmd
        pclose(stdout);
    });
    thread.join();
}