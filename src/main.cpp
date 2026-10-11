#include <iostream>

int main() {
    /*
     * cd "/Applications/AssaultCube.app/Contents/gamedata" &&
exec "./assaultcube.app/Contents/MacOS/assaultcube" \
  --home="$HOME/Library/Application Support/assaultcube/v1.3" \
  --init -w1637 -h1024 -z32 -a0 -t1 -s8
     * i need to recreate this in c++ >_<
     * so ill use my own paths right now so i dont have to ask
     * should i worry about the agruments being able to be changed by the user not right now 
     */

     // strings
    std::string ourhome = "/Applications/AssaultCube.app";
    std::string data = "/Contents/gamedata"; // i want the user to point to "AssaultCube.app" if i add that
    std::string exec = "./assaultcube.app/Contents/MacOS/assaultcube";
    std::string arguments = "--init -w1637 -h1024 -z32 -a0 -t1 -s8"; // there's gotta be a better way for this

    //cout
    std::cout << "Application path: " << ourhome << "\n";
    std::cout << "Executable path: " << exec << "\n\n";
    std::cout << "Options: \n1: launch\n2: nothing\n";
    std::cout << "I like pink\n"; // because i like pink

    std::string input;// ask the user for an input to figure out what to do next
    getline(std::cin, input);
    if (input == "1") {// probably should use a switch statement
        std::string command = "cd \"" + ourhome + data + "\" && exec \"" + exec + "\" --home=\"$HOME/Library/Application Support/assaultcube/v1.3\" " + arguments;
        std::cout << "Executing command\n"; // "you were sprayed by KillSwitch" tragic i got killed by an ai multiple times
        system(command.c_str()); // "rrawr" 
    } else {
        std::cout << "No action taken.\n";
    }
    return 0;
}