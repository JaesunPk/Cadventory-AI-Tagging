#include <iostream>
#include "lib/ModelTagging.h"

int main() {
    try{
        std::cout << "<< CADVentory AI Tagging Prototype >>" << std::endl;
        
        // create an instance of the ModelTagging class
        ModelTagging tagger = ModelTagging();

        // testing here (change path to your model file)
        tagger.generateTags("C:/Users/jaesu/Downloads/CADVentory_ex-20250309T235053Z-001/CADVentory_ex/Teapot/teapot.g");
    }catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;  
    }

    return 0;
}
