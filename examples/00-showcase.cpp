#include "openai.hpp"
#include <iostream>
#include <string>

int main() {
    openai::start("sk-on-Jo5FAGExsug1vrAvXCQ","",true,"https://agino.me/"); // Will use the api key provided by `OPENAI_API_KEY` environment variable
    // openai::start("your_API_key", "optional_organization"); // Or you can handle it yourself

    std::string userInput;
    std::cout << "请输入您的问题： ";
    std::getline(std::cin, userInput);

    auto completion = openai::chat().create(R"(
    {
        "model": "gpt-3.5-turbo",
        "messages": [{"role": "user", "content": userInput") }],
        "max_tokens": 4096,
        "temperature": 0
    }
    )"_json); // Using user-defined (raw) string literals
    std::cout << "AI的回答是：" << completion.dump(2) << '\n '; 
}
