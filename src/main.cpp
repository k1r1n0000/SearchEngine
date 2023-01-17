#include <iostream>

#include "ConverterJSON.h"
#include "InvertedIndex.h"

int main() {
    auto converterJSON = ConverterJSON();
    auto invertedIndex = InvertedIndex();

    if(!converterJSON.LoadConfig()){
        return 1;
    }

    if(!converterJSON.LoadRequests()){
        return 1;
    }

    std::cout << converterJSON.cf.config.name << ((converterJSON.cf.config.version.empty())? "" : " version: ") << converterJSON.cf.config.version << std::endl;

    auto texts = converterJSON.GetTextDocuments();
    invertedIndex.UpdateDocumentBase(texts);
    SearchServer srv(invertedIndex);
    auto result = srv.search(converterJSON.GetRequests());
    converterJSON.PutAnswers(result);

    std::cout << "The search has been completed";
    std::cin.get();

    return 0;
}
