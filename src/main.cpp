#include "clearTerminal.h"
#include <iostream>
#include <vector>

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

    clearTerminal(); // clear terminal kitty!
    // bools
    bool amIWantingToBeAFemboy = true;
    // strings
    std::string ourhome = "/Applications/AssaultCube.app";
    std::string homeeqthing = "$HOME/Library/Application Support/assaultcube/v1.3";
    std::string data = "/Contents/gamedata"; // i want the user to point to "AssaultCube.app" if i add that
    std::string exec = "./assaultcube.app/Contents/MacOS/assaultcube";
    std::vector<std::string> arguments = {"--init", "-w1637", "-h1024", "-z32", "-a0", "-t1", "-s8"}; // i think this is better

    while (amIWantingToBeAFemboy) {
    // cout
    std::cout << "Application path: " << ourhome << "\n";
    std::cout << "Executable path: " << exec << "\n\n";
    std::cout << "Options: \n1: launch\n2: edit arguments\n3: edit whatever\n4: exit\n5: clear terminal\n";
    std::cout << "I like pink: "; // because i like pink

    std::string input; // ask the user for an input to figure out what to do next
    getline(std::cin, input);
    switch (input[0]) {
        case '1': {
            std::string command = "cd \"" + ourhome + data + "\" && exec \"" + exec + "\" --home=\"" + homeeqthing + "\" ";
            for (const auto& arg : arguments) {
                command += arg + " ";
            }
            std::cout << "Executing command\n\n"; // "you were sprayed by KillSwitch" tragic i got killed by an ai multiple times
            system(command.c_str()); // "rrawr" 
            std::cout << "\n"; // it should look better
            break; // why just be like java we dont need "break;"
        }
        case '2': {
            //so how do i print arguments then allow the user to edit them(one at a time)
            std::cout << "Current arguments:\n";
            for (size_t i = 0; i < arguments.size(); ++i) {
                std::cout << i + 1 << ": " << arguments[i] << "\n";
            }
            std::cout << "Enter the number of the argument you want to edit (or 0 to cancel): ";
            size_t argIndex; // i might see if i can switch to CLion by JetBrains or Xcode im starting to dislike VS Code
                if (!(std::cin >> argIndex)) { // thanks deepseek!
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Not a number.\n";
                break;
            }
            std::cin.ignore(1000, '\n'); // thanks deepseek!
            if (argIndex > 0 && argIndex <= arguments.size()) {
                std::cout << "Enter new value for argument " << argIndex << ": ";
                std::string newArg;
                getline(std::cin, newArg);
                arguments[argIndex - 1] = newArg;
                std::cout << "Argument updated.\n";
            } else if (argIndex == 0) {
                std::cout << "Edit cancelled.\n";
            } else {
                std::cout << "Invalid argument number: '" << argIndex << "'\n"; // show the number or whatever it was
            }
            break;
        }
        case '3': {
            // ill just copy edit arguments but for stuff like "ourhome" 
            // never mind i just made this and its worse so ill kep it
            std::cout << "1: Application path: " << ourhome << "\n";
            std::cout << "2: Home path: " << homeeqthing << "\n";
            std::cout << "3: Executable path: " << exec << "\n";
            std::cout << "4: Data path: " << data << "\n";

            std::cout << "Enter the number of the path you want to edit (or 0 to cancel): ";
            getline(std::cin, input);
            switch (input[0]) {
            case '1': { // switch is like pretty-printing json but its just to replace if/else
                std::cout << "Enter new application path: ";
                getline(std::cin, ourhome);
                break;
            }
            case '2': {
                std::cout << "Enter new home path: ";
                getline(std::cin, homeeqthing);
                break;
            }
            case '3': {
                std::cout << "Enter new executable path: ";
                getline(std::cin, exec);
                break;
            }
            case '4': {
                std::cout << "Enter new data path: ";
                getline(std::cin, data);
                break;
            }
            case '0': {
                std::cout << "Edit cancelled.\n\n";
                break;
            }
            default: { 
                // nothing(enter) -> first message "a"(or something else we dont have) -> second message
                if (input.empty()) std::cout << "Edit cancelled. I love getting called a puppy boy and good puppy!\n\n";
                else
                std::cout << "Invalid input: '" << input << "'\n\n";
            }
                break;
            }
            break;
        }
        case '4': {
            std::cout << "Exiting...\n";
            amIWantingToBeAFemboy = false; // its still true
            break; // why not just return 0; idk im a weirdo and i want to use amIWantingToBeAFemboy
        }
        case '5': {
            clearTerminal();
            break;
        }
        default: {
            std::cout << "Invalid input. No action taken.\n\n";
            break;
        }
    }
}
    return 0; // bye kitty !
} // "I want to text you genius" - misty