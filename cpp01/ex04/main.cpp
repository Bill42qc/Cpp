#include <iostream>
#include <fstream>

std::string replace_word(std::string &str, const std::string &original_word, const std::string &newWord)
{
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(original_word, pos)) != std::string::npos)
    {
        result = result.substr(0, pos) + newWord + result.substr(pos + original_word.length());
        pos += newWord.length();
    }
    return result;
}

void replace(std::string filename, std::string s1, std::string s2)
{
    // fichier source en lecture
    std::ifstream source_file(filename);
    if (!source_file.is_open())
    {
        std::cerr << "Problem Opening Source File" << std::endl;
        return;
    }

    // fichier destination write + add .replace
    std::ofstream destination_file(filename + ".replace");
    if (!destination_file.is_open())
    {
        std::cerr << "Problem Creating Destination File" << std::endl;
        source_file.close();
        return;
    }

    //copie
    std::string line;
    std::string replaced_line;
    while (std::getline(source_file, line))
    {
        replaced_line = replace_word(line, s1, s2);
        destination_file << replaced_line << std::endl;
    }
    source_file.close();
    destination_file.close();
    return;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cout << "USE 3 ARGS ex:  ./sed   <filename>   <str_to_replace>   <str_to_replace_with", 1);
    else
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        replace(filename, s1, s2);
        return (0);
    }
}