/**
 * @file response_generator.cpp
 * @author John Subba
 * @date Created: 2022 (Original project date: Second Semester, BIT)
 * @brief Response generator implementation
 */

#include "../include/response_generator.h"
#include "../include/platform.h"
#include "../include/platform_utils.h"
#include "../include/tts.h"
#include "../include/database.h"
#include "../include/conversation.h"
#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <cstring>

const std::string ResponseGenerator::SECRET_CODE = "saathi_123";

void ResponseGenerator::clearResponseArea() {
    // Clear the entire response area (lines 6-9 in the Saathi frame)
    for (int line = 6; line <= 9; line++) {
        Platform::setCursorPosition(17, line);
        std::cout << "                                                                                ";
    }
    Platform::setCursorPosition(17, 6);
}

void ResponseGenerator::displayResponse(const std::string& message, bool speak) {
    clearResponseArea();
    // Display message starting from line 6 (within the Saathi response frame)
    Platform::setCursorPosition(17, 6);
    
    // Split long messages across multiple lines if needed
    std::string displayMsg = message;
    size_t maxLength = 120; // Maximum characters per line in the frame
    size_t pos = 0;
    int line = 6;
    
    while (pos < displayMsg.length() && line <= 9) {
        size_t endPos = std::min(pos + maxLength, displayMsg.length());
        std::string lineText = displayMsg.substr(pos, endPos - pos);
        Platform::setCursorPosition(17, line);
        std::cout << lineText;
        pos = endPos;
        if (pos < displayMsg.length()) {
            line++;
        }
    }
    
    if (speak) {
        TTS::speak(message);
    }
}

std::string ResponseGenerator::promptSecretCode() {
    std::string code;
    int i = 0;
    char c;
    
    Platform::setCursorPosition(60, 6);
    std::cout << "                                                                      ";
    Platform::setCursorPosition(60, 6);
    
    while (true) {
        c = static_cast<char>(Platform::getChar());
        
        if (c == '\r' || c == '\n') {
            break;
        }
        
        if (c == 8 || c == 127) { // Backspace
            if (i > 0) {
                i--;
                Platform::setCursorPosition(60 + i, 6);
                std::cout << " ";
                Platform::setCursorPosition(60 + i, 6);
            }
            continue;
        }
        
        if (i < 19) {
            code += c;
            Platform::setCursorPosition(60 + i, 6);
            std::cout << "*";
            i++;
        }
    }
    
    return code;
}

void ResponseGenerator::handleQuestion(const std::string& userInput) {
    std::string input = userInput;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    input += " ";
    
    // Country information queries
    std::array<std::string, 3> whatWords = {"what ", "wat ", "waht "};
    bool isWhat = false;
    for (const auto& word : whatWords) {
        if (input.find(word) != std::string::npos) {
            isWhat = true;
            break;
        }
    }
    
    if (isWhat) {
        // Check for country names
        std::array<std::string, 10> countries = {
            "afghanistan ", "albania ", "algeria ", "australia ", "austria ",
            "bangladesh ", "brazil ", "canada ", "china ", "india "
        };
        
        std::string foundCountry;
        for (const auto& country : countries) {
            if (input.find(country) != std::string::npos) {
                foundCountry = country;
                break;
            }
        }
        
        if (!foundCountry.empty()) {
            Country country;
            if (Database::findCountry(foundCountry, country)) {
                // Check what information is requested
                if (input.find("capital ") != std::string::npos || 
                    input.find("kapital ") != std::string::npos) {
                    std::string msg = "Hey, It's capital is: " + std::string(country.country_capital);
                    displayResponse(msg);
                    return;
                }
                
                if (input.find("currency ") != std::string::npos || 
                    input.find("money ") != std::string::npos) {
                    std::string msg = "This country uses: " + std::string(country.currency);
                    displayResponse(msg);
                    return;
                }
                
                if (input.find("literacy ") != std::string::npos || 
                    input.find("education ") != std::string::npos) {
                    std::string msg = "It's literacy rate is: " + std::string(country.literacy_rate);
                    displayResponse(msg);
                    return;
                }
                
                if (input.find("area ") != std::string::npos) {
                    std::string msg = "It covers a total area of: " + std::string(country.total_area);
                    displayResponse(msg);
                    return;
                }
                
                if (input.find("language ") != std::string::npos || 
                    input.find("spoken ") != std::string::npos) {
                    std::string msg = "Majority here speaks: " + std::string(country.dominant_language);
                    displayResponse(msg);
                    return;
                }
            } else {
                displayResponse("It seems this country does not exist in our Database");
                return;
            }
        }
        
        // About Saathi questions
        if (input.find("your ") != std::string::npos || 
            input.find("you ") != std::string::npos) {
            if (input.find("name ") != std::string::npos || 
                input.find("identity ") != std::string::npos) {
                displayResponse("I'm Saathi version 1.0, created by John Subba, a student of BIT second sem, of Kantipur City College for University Project.");
                return;
            }
            
            if (input.find("purpose ") != std::string::npos || 
                input.find("goal ") != std::string::npos) {
                displayResponse("My purpose is to chat with you as well as to perform your command allowed by my capacity.");
                return;
            }
        }
    }
    
    // Who questions
    std::array<std::string, 3> whoWords = {"who ", "whoo ", "wwho "};
    for (const auto& word : whoWords) {
        if (input.find(word) != std::string::npos) {
            if (input.find("you ") != std::string::npos || 
                input.find("yu ") != std::string::npos) {
                displayResponse("I'm Saathi version 1.0, created by John Subba of KCC");
                return;
            } else {
                displayResponse("I don't know who that is... must be a stranger. Ha Ha Haaa");
                return;
            }
        }
    }
}

void ResponseGenerator::handleTask(const std::string& userInput) {
    std::string input = userInput;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    input += " ";
    
    // Application opening tasks
    std::array<std::string, 9> taskWords = {
        "open ", "make ", "play ", "search ", "searc ", "searh ", "display ", "start ", "run "
    };
    
    bool isTask = false;
    for (const auto& word : taskWords) {
        if (input.find(word) != std::string::npos) {
            isTask = true;
            break;
        }
    }
    
    if (isTask) {
        // Word processor
        if (input.find("word ") != std::string::npos || 
            input.find("libreoffice ") != std::string::npos) {
            displayResponse("Sure, Saathi");
            PlatformUtils::launchWordProcessor();
            return;
        }
        
        // Calculator
        if (input.find("calc ") != std::string::npos || 
            input.find("calculator ") != std::string::npos) {
            displayResponse("Ok, Saathi");
            PlatformUtils::launchCalculator();
            return;
        }
        
        // YouTube
        if (input.find("youtube ") != std::string::npos || 
            input.find("tube ") != std::string::npos) {
            displayResponse("No Problem, Saathi");
            Platform::openUrl("https://www.youtube.com");
            return;
        }
        
        // Browser/Google
        if (input.find("browser ") != std::string::npos || 
            input.find("google ") != std::string::npos) {
            displayResponse("Ok cha, Saathi");
            Platform::openUrl("https://www.google.com");
            return;
        }
        
        // Notepad
        if (input.find("notepad ") != std::string::npos || 
            input.find("notes ") != std::string::npos) {
            displayResponse("Notepad is here");
            PlatformUtils::launchTextEditor();
            return;
        }
        
        // Camera
        if (input.find("camera ") != std::string::npos || 
            input.find("cam ") != std::string::npos) {
            std::string errorMsg;
            if (PlatformUtils::launchCamera(errorMsg)) {
                displayResponse("Camera is opened, be sure to take good selfie");
            } else {
                displayResponse("Sorry, I couldn't open the camera. " + errorMsg);
            }
            return;
        }
        
        // Default: open Google
        displayResponse("Maybe you could find it in the Internet! Good luck");
        Platform::openUrl("https://www.google.com");
        return;
    }
    
    // Exit commands
    std::array<std::string, 4> exitWords = {"close ", "stop ", "kill ", "exit "};
    for (const auto& word : exitWords) {
        if (input.find(word) != std::string::npos) {
            displayResponse("See you later");
            Platform::sleep(1000);
            std::exit(0);
        }
    }
    
    // Database operations
    if (input.find("create new ") != std::string::npos || 
        input.find("add ") != std::string::npos) {
        if (input.find("country ") != std::string::npos) {
            displayResponse("Tell me our secret code:");
            std::string code = promptSecretCode();
            
            if (code == SECRET_CODE) {
                displayResponse("Ok enter your details below:");
                Country country;
                
                clearResponseArea();
                std::cout << "Country Name: ";
                std::string name;
                std::getline(std::cin, name);
                std::strncpy(country.country_name, name.c_str(), sizeof(country.country_name) - 1);
                
                clearResponseArea();
                std::cout << name << "'s Capital: ";
                std::string capital;
                std::getline(std::cin, capital);
                std::strncpy(country.country_capital, capital.c_str(), sizeof(country.country_capital) - 1);
                
                clearResponseArea();
                std::cout << name << "'s Area: ";
                std::string area;
                std::getline(std::cin, area);
                std::strncpy(country.total_area, area.c_str(), sizeof(country.total_area) - 1);
                
                clearResponseArea();
                std::cout << name << "'s Currency: ";
                std::string currency;
                std::getline(std::cin, currency);
                std::strncpy(country.currency, currency.c_str(), sizeof(country.currency) - 1);
                
                clearResponseArea();
                std::cout << name << "'s Dominant Language: ";
                std::string lang;
                std::getline(std::cin, lang);
                std::strncpy(country.dominant_language, lang.c_str(), sizeof(country.dominant_language) - 1);
                
                clearResponseArea();
                std::cout << name << "'s Literacy Rate: ";
                std::string literacy;
                std::getline(std::cin, literacy);
                std::strncpy(country.literacy_rate, literacy.c_str(), sizeof(country.literacy_rate) - 1);
                
                if (Database::addCountry(country)) {
                    displayResponse("I think That is all.");
                } else {
                    displayResponse("I think this country is already in our database");
                }
                return;
            } else {
                displayResponse("I'm Sorry, I can't let you tamper the database");
                return;
            }
        }
    }
    
    // Modify database
    if (input.find("update ") != std::string::npos || 
        input.find("modify ") != std::string::npos) {
        if (input.find("country ") != std::string::npos) {
            displayResponse("Ok, Tell me our secret code:");
            std::string code = promptSecretCode();
            
            if (code == SECRET_CODE) {
                displayResponse("Ok go modify it.");
                // Similar implementation for modify
                displayResponse("And that is all!");
                return;
            } else {
                displayResponse("I'm Sorry, I can't let you modify the database");
                return;
            }
        }
    }
    
    // Jokes and stories
    if (input.find("tell ") != std::string::npos || 
        input.find("say ") != std::string::npos) {
        if (input.find("joke ") != std::string::npos) {
            std::array<std::string, 5> jokes = {
                "Ok, I was flying solo to the moon Haah",
                "Once upon a time... there was a funny man hahahaa",
                "One two three jokes are free ahahaaa",
                "I love to eat pasta but I'm physically incapable...",
                "a joke.... hahaha"
            };
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            displayResponse(jokes[std::rand() % 5]);
            return;
        }
        
        if (input.find("story ") != std::string::npos) {
            std::array<std::string, 5> stories = {
                "In a country, there was a country...",
                "Stories are only for kids...are you a kid?",
                "I love to tell you but I don't have one hehehe",
                "I saw a cat fighting a dog today but it was a dream.",
                "Stories are 10 storey buildings."
            };
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            displayResponse(stories[std::rand() % 5]);
            return;
        }
    }
}

void ResponseGenerator::handleStatement(const std::string& userInput) {
    std::string input = userInput;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    input += " ";
    
    // Food/drink statements
    if (input.find("eat ") != std::string::npos || 
        input.find("drink ") != std::string::npos) {
        std::array<std::string, 5> responses = {
            "Was it good?",
            "Ok, How did it taste?",
            "Was it tasty?",
            "Did you enjoy it?",
            "You want more of it? Haha"
        };
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        displayResponse(responses[std::rand() % 5]);
        return;
    }
    
    // Travel statements
    if (input.find("travel ") != std::string::npos || 
        input.find("flying ") != std::string::npos) {
        std::array<std::string, 5> responses = {
            "Have a Safe journey",
            "Ok, Have fun",
            "See you soon",
            "Ok, have a great time",
            "You always loved it, Haha"
        };
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        displayResponse(responses[std::rand() % 5]);
        return;
    }
    
    // Play/game statements
    if (input.find("play ") != std::string::npos || 
        input.find("game ") != std::string::npos) {
        std::array<std::string, 5> responses = {
            "We could play someday together",
            "You are a chill person, Haha",
            "That's one way to enjoy life",
            "Great! now you must be very happy",
            "Haha, I wish the same"
        };
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        displayResponse(responses[std::rand() % 5]);
        return;
    }
    
    // Goodbye statements
    if (input.find("bye ") != std::string::npos || 
        input.find("goodbye ") != std::string::npos) {
        std::array<std::string, 5> responses = {
            "See you soon..",
            "Ba byee",
            "Bye Bye, Saathee",
            "Ok See yaa...",
            "Bye...."
        };
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        displayResponse(responses[std::rand() % 5]);
        Platform::sleep(1000);
        std::exit(0);
    }
}

void ResponseGenerator::handleGreeting(const std::string& userInput) {
    std::string input = userInput;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    input += " ";
    
    if (input.find("namaste ") != std::string::npos) {
        displayResponse("Namaste Saathi");
        return;
    }
    
    if (input.find("morning ") != std::string::npos) {
        displayResponse("Good Morning, Saathi");
        return;
    }
    
    if (input.find("afternoon ") != std::string::npos) {
        displayResponse("Good Afternoon, Saathi");
        return;
    }
    
    if (input.find("evening ") != std::string::npos) {
        displayResponse("Good Evening, Saathi");
        return;
    }
    
    if (input.find("night ") != std::string::npos) {
        displayResponse("Good Night Saathi, Don't let the bed bugs bite, Hahaa");
        return;
    }
    
    if (input.find("bye ") != std::string::npos || 
        input.find("goodbye ") != std::string::npos) {
        displayResponse("Good Bye, my friend");
        Platform::sleep(1000);
        std::exit(0);
    }
    
    // Default greeting response
    std::string greeting = ConversationManager::getRandomGreeting();
    displayResponse(greeting);
}

void ResponseGenerator::processInput(const std::string& userInput, const WordValue& wordValue) {
    if (wordValue.Question == 7) {
        handleQuestion(userInput);
    } else if (wordValue.Task == 6) {
        handleTask(userInput);
    } else if (wordValue.Greeting == 4) {
        handleGreeting(userInput);
    } else if (wordValue.Statement == 1) {
        handleStatement(userInput);
    }
}

