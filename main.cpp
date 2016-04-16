#include "StringSet.h"
//Future work:
//1. File documenting system that indexes all names of files in a directory.
//2. Search for a file using the relevence algorithm in this program.
//3. This is done with the index.dat that stores the names of all files that
//are to be rated on a scale of relevance.

//Uses Programming Project 9 Chapter 11

int main()
{
    std::ifstream fin1, fin2, fin3;
    std::string file_name1("Doc.dat"), file_name2("Query.dat");
    std::string file_name3("Doc2.dat");
    std::string rele_file("");
    StringSet Doc, Query;
    StringSet Doc2;
    Doc2 = Doc2.intoSet(fin3, file_name3);
    Doc = Doc.intoSet(fin1, file_name1);
    //Doc.Printer();
    Query = Query.intoSet(fin2, file_name2);
    double sim = Doc.Sim(Query);
    double sim2 = Doc2.Sim(Query);
    int counted = Doc.CountSet();
    int counted2 = Doc2.CountSet();

    std::cout << "In " << file_name1 << " " << counted << " words." << std::endl;
    std::cout << "In " << file_name3 << " " << counted2 << " words." << std::endl;
    std::cout << "Relevence of first doc: " << sim << std::endl;
    std::cout << "Relevence of second doc: " << sim2 << std::endl;

    double Max;
    if(sim < sim2){
        Max = sim2;
        rele_file = file_name3;
    }
    else{
        Max = sim;
        rele_file = file_name1;
    }
    std::cout << rele_file << " is most relevant with: " << Max << std::endl;
    fin1.close();
    fin2.close();

    Doc.Clear();
    Query.Clear();
    return 0;
}

/* FOR MAIN TEST preliminary results...
    std::vector<std::string> stringy;
    stringy.push_back("Rouvem");
    stringy.push_back("David");
    stringy.push_back("Anton");
    StringSet SET1(stringy);
    std::cout << "SET1 is: ";
    SET1.Printer();
    stringy.push_back("Alla");
    stringy.push_back("Alex");
    stringy.push_back("Veronica");
    StringSet SET2(stringy);
    std::cout << "SET2 is: ";
    SET2.Printer();
    StringSet SET3;
    SET3 = SET1 + SET2;
    std::cout << "SET3 is: ";
    SET3.Printer();
    SET3 = SET1 * SET2;
    std::cout << "SET3 is: ";
    SET3.Printer();
*/

