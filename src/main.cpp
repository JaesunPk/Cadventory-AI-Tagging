#include <iostream>
#include <vector>
#include <string>
#include "lib/ModelTagging.h"

int main(int argc, char* argv[]) {
    try {
        std::cout << "<< CADVentory AI Tagging Prototype >>" << std::endl;
        
        // Create an instance of the ModelTagging class
        ModelTagging tagger = ModelTagging();
        
        if (argc < 2) {
            std::cout << "Usage: " << argv[0] << " <cad_model_path> [<cad_model_path> ...]" << std::endl;
            return 1;
        }

        // Generate tags for each model file
        for (int i = 1; i < argc; i++) {
            std::string filepath = argv[i];
            std::cout << "\nGenerating tags for: " << filepath << std::endl;
            tagger.generateTags(filepath);
            std::vector<std::string> tags = tagger.getTags();

            // print the tags
            std::cout << "\nGenerated " << tags.size() << " tags for: " << filepath << std::endl;
            std::cout << "-------------------------------------" << std::endl;
            for (const auto& tag : tags) {
                std::cout << "- " << tag << std::endl;
            }
            std::cout << "-------------------------------------" << std::endl;
        }
        
        
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
