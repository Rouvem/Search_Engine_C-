#include "StringSet.h"
#include <math.h>
class EmptyVect{
// for catching Exceptions
};

StringSet::StringSet(){
}

StringSet::StringSet(const std::vector<std::string> init){
    Vectstring = init;
}

void StringSet::Printer(){
    std::vector<std::string>::iterator iter;
    if(Vectstring.size() == 0){
        //std::cout << "String is Empty!" << std::endl << std::endl;
        return;
    }

    for(iter = Vectstring.begin(); iter != Vectstring.end(); iter++){
        std::cout << *iter << " ";
    }
    std::cout << std::endl << std::endl;
}

void StringSet::Add(std::string str){
    std::vector<std::string>::iterator iter;
    /*for(iter = Vectstring.begin(); iter != Vectstring.end(); iter++){
        if(*iter == str){
            //std::cout << *iter << " is already in the set!" << std::endl;
            return;
        }
    }*/
    Vectstring.push_back(str);
}

void StringSet::Discard(std::string str){
    EmptyVect EMPTY;
    try{
        std::vector<std::string>::iterator iter;
        if(Vectstring.size() == 0){
            throw EMPTY;
        }
        for(iter = Vectstring.begin(); iter != Vectstring.end(); iter++){
            if(*iter == str){
                //std::cout << "Discarding: " << *iter << " from set!" << std::endl;
                Vectstring.erase(iter);

                return;
            }
        }
        //std::cout << "Could not find " << str << " to erase!" << std::endl;
    }
    catch(EmptyVect e){
        //std::cout << "Cannot remove from empty set!" << std::endl;
    }
}

void StringSet::Clear(){
    Vectstring.clear();
}

int StringSet::CountSet(){
    std::cout << Vectstring.size() << std::endl;
    return Vectstring.size();
}

StringSet StringSet::operator +(StringSet strset){
    StringSet Union;
    std::vector<std::string>::iterator itB, itA;
	std::vector<std::string>::iterator loc1, loc2;
	for(itA = Vectstring.begin(); itA != Vectstring.end(); itA++){
		loc1 = find(itA+1, Vectstring.end(), *itA); // make sure its a true set
		loc2 = find(itB, strset.Vectstring.end(), *itA);
		if(loc1 == Vectstring.end() && loc2 == strset.Vectstring.end())
			Union.Vectstring.push_back(*itA);
	}

	for(itB = Vectstring.begin(); itB != strset.Vectstring.end(); itB++){
		loc1 = find(itA, Vectstring.end(), *itB);
		loc2 = find(itB+1, strset.Vectstring.end(), *itB);
		if(loc1 == Vectstring.end() && loc2 == strset.Vectstring.end())
			Union.Vectstring.push_back(*itB);
	}
    return Union;
}

StringSet StringSet::operator *(StringSet strset){
    StringSet Intersection;
    std::vector<std::string>::iterator itB = strset.Vectstring.begin(), itA;
	std::vector<std::string>::iterator loc1, loc2;
	for(itA = Vectstring.begin(); itA != Vectstring.end(); itA++){
		loc1 = find(itA+1, Vectstring.end(), *itA); // make sure its a true set
		loc2 = find(itB, strset.Vectstring.end(), *itA);
		if(loc1 == Vectstring.end() && loc2 != strset.Vectstring.end())
			Intersection.Vectstring.push_back(*itA);
	}
    return Intersection;
}

double StringSet::Sim(StringSet strset){
    StringSet A(Vectstring);
    StringSet Intersect;
    Intersect =  A * strset;
    //std::cout << "A set is: ";
    //A.Printer();
    //double top = Intersect.CountSet();
 /*double top = A;
    double bottom = (sqrt(A.CountSet())*sqrt(strset.CountSet()));
    double sim = top/bottom;
    */
    int DCount = CountSet();
    std::vector<std::string>::iterator diter, qiter;
    int num_of_times = 0;
    int detrement = 1;
    for(qiter = strset.Vectstring.begin(); qiter != strset.Vectstring.end(); qiter++){
            char flag = 0x0;
            for(diter = Vectstring.begin(); diter != Vectstring.end(); diter++)
                if(*diter == *qiter){
                    num_of_times++;
                    flag = 0x1;
            }
            if(!flag){
                detrement++;
            }
    }
    std::cout << "num_of_times " << num_of_times << std::endl;
    std::cout << "detrement " << detrement << std::endl;
    if(num_of_times == 0){
        return 0.0;
    }
    else{
        double result = Intersect.CountSet() / (sqrt(num_of_times));
        //(((double) num_of_times) / DCount)
        std::cout << "result: " << result << std::endl;
        result *= (num_of_times) * (1.0 / sqrt(detrement));
        return result;
    }

}

StringSet StringSet::intoSet(std::ifstream& fin1, std::string file_name){
    // Note: no need to mess with buffers in this program...for now
    StringSet File;
    std::string  line1, line2, word;
    fin1.open(file_name.c_str());
    if(fin1.is_open()){
       // std::cout << std::endl << file_name << " is open!" << std::endl << std::endl;
    }
    if(fin1.fail())
        exit(1);

    while(getline(fin1, line1)){
        std::istringstream iss1(line1);

        while(iss1 >> word){
            for(int i = 0, len = word.size(); i < len; i++){
               if(65 <= char(word[i]) && char(word[i]) <= 90){ // to lowercase
                    word[i] = tolower(word[i]);
               }
               if(ispunct(word[i])){ //removes punctuation
                    word.erase(i--, 1);
                    len = word.size();
               }
            }
            File.Add(word);
        }
    }
    return File;
}
