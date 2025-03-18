#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "ModelTagging.h"

ModelTagging::ModelTagging(){
    // instantiate the parser
    parser = ModelParser();
}

ModelTagging::~ModelTagging(){
    // destructor implementation
}

void ModelTagging::generateTags(std::string filepath) {
    ModelMetadata metadata = parser.parseModel(filepath);
    std::ostringstream objectPathsStream;

    for (const auto& object : metadata.objectFiles) {
        objectPathsStream << "  - " << object << "\n";
    }

    std::ostringstream prompt;
    prompt << R"(
        Generate exactly **10 relevant tags** for categorization and search filtering of this 3D CAD model.
        ### **File Metadata:**
        - **Filepath:** )" << filepath << R"(
        - **Title:** )" << metadata.title << R"(
        - **Object Paths:**  
    )" 
        << objectPathsStream.str() << R"(

        ### **Instructions:**
        - **ONLY use words directly related to the object in the CAD model.**  
        - **Do NOT include metadata like names, file paths, BRL-CAD, or dates.**  
        - **Prioritize useful search terms for categorization (e.g., mechanical, architectural, vehicle, tool).**  
        - **Infer object identity from file names, object names, and folder structure.**  
        - **Do NOT make them generic (e.g., object, model, 3D).**
        - **Do NOT assume additional details beyond what's in the metadata.**  
        - **Number the tags from 1 to 10.**
    )";

    // Save the prompt to a temp file for execution
    std::ofstream promptFile("prompt.txt");
    promptFile << prompt.str();
    promptFile.close();

    // Construct the command for Ollama to call LLaMA
    std::string command = "ollama run llama3 < prompt.txt";
    int result = std::system(command.c_str());

    if (result == 0) {
        // Read the output from temp_tags.txt
        std::ifstream file("temp_tags.txt");
        std::string line;
        while (std::getline(file, line)) {
            tags.push_back(line);
        }
        file.close();
    }
    else {
        std::cerr << "ERROR: LLaMA call failed." << std::endl;
    }
}
