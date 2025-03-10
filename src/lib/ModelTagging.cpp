#include <iostream>
#include <string>
#include <vector>
#include "ModelTagging.h"

ModelTagging::ModelTagging(){
    // instantiate the parser
    parser = ModelParser();
}

ModelTagging::~ModelTagging(){
    // destructor implementation
}

void ModelTagging::generateTags(std::string filepath){
    // parse the model
    ModelMetadata metadata = parser.parseModel(filepath);

    // validate the metadata
    std::cout << "Filepath: " << metadata.filepath << std::endl;
    std::cout << "Title: " << metadata.title << std::endl;
    for(auto& object : metadata.objectFiles){
        std::cout << "Object: " << object << std::endl;
    }
}
