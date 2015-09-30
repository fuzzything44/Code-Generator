#include "genName.h"
#include "logger.h"
#include "classDef.h"
#include <iterator>

using std::string;
using std::ifstream;

std::map<string, std::vector<string> > genName::lines;

using namespace std;

void genName::init() {
    ENTER_FUNC(genName::init())
    
    ifstream infile;
    infile.open("names.txt");
    string lineInfo ;
    // For what vector to add the info to.
    string varKey;
    lines[""].push_back("");
    
    LOG("Reading file..." << std::endl)
    
    //While the file hasn't fully been read and no errors have happened in reading it.
    while(infile) {
        
        //Store line in LineInfo
        getline(infile, lineInfo);
        
        
        
        if (lineInfo[0] == '-') {
            varKey = lineInfo.substr(1, lineInfo.size() );
        } else if(lineInfo[0] == '#') {
            //Nuthin
        } else {
            lines[varKey].push_back(lineInfo);
            LOG("Line reads: " << lineInfo)
        } // End symbols if/else
        
    } // End while
    
    infile.close();
    
    LEAVE_FUNC_VOID(genName::init())
} // End function


// Determines if the vector has a 1-char length string equal to the given char.
inline bool containsChar(const char c, const vector<string>& symbols)
{
    ENTER_FUNC(containsChar(const char, const vector<string>&))
    
    
    
    // Go through all symbols.
    for (auto i = symbols.cbegin(); i != symbols.cend(); i++) {
        // If a symbol matches the character, return true.
        if (*i == to_string(c) ) {
            LEAVE_FUNC_LITERAL(containsChar(const char, const vector<string>&), true)
        }
    }
    
    // No match found. Return false.
    LEAVE_FUNC_LITERAL(containsChar(const char, const vector<string>&), false)
}

inline bool isSpecial(const char c)
{
    ENTER_FUNC(isSpecial(const char))
    LEAVE_FUNC_LITERAL(isSpecial(const char), (c == '!') || (c == '@')|| (c=='#')|| (c == '$')|| (c == '%')|| (c == '^')|| (c == '*'))
}

string genName::get(const string& type, const vector<classDef::variable>& v)
{
    // Tries 20 times before giving up.
    for (int i = 0; i < 20; i++) {
        // String to test if used.
        string test = genName::get(type);
        bool isUsed = false;
        for (auto i = v.cbegin(); i != v.cend(); i++) {
            if (test == i->first) {
                isUsed = true;
            }
        }
        if (!isUsed) {
            return test;
        }
    }
    // Generate a completely unique name.
    string::size_type maxl = 0;
    for (auto i = v.cbegin(); i != v.cend(); i++) {
        if (i->first.size() > maxl) {
            maxl = i->first.size();
        }
    }
    // Create a string 1 longer than maxl.
    string ret;
    for (string::size_type i = 0; i <= maxl; i++) {
        char c = randRange('a', 'z');
        ret += c;
    }
    return ret;
}
string genName::get(const string& type, const vector<classDef>& v)
{
    // Tries 20 times before giving up.
    for (int i = 0; i < 20; i++) {
        // String to test if used.
        string test = genName::get(type);
        bool isUsed = false;
        for (auto i = v.cbegin(); i != v.cend(); i++) {
            if (test == i->getName() ) {
                isUsed = true;
            }
        }
        if (!isUsed) {
            return test;
        }
    }
    // Generate a completely unique name.
    string::size_type maxl = 0;
    for (auto i = v.cbegin(); i != v.cend(); i++) {
        if (i->getName().size() > maxl) {
            maxl = i->getName().size();
        }
    }
    // Create a string 1 longer than maxl.
    string ret;
    for (string::size_type i = 0; i <= maxl; i++) {
        char c = randRange('a', 'z');
        ret += c;
    }
    return ret;
}

string genName::get(const string& type){
    
    string name = "";
    LOG("Getting name of type " << type)

    /*
     
     Special symbols:
        '!' = .post
        '@' = type (the string passed in).
        '#' = Comment line. Ignored when read in.
        '$' =
        '%' = .pre
        '^' =
        '&' =
        '*' =
        '~' =
        '+' =
        '?' = 
     */
    
    const vector<string>& ref = lines[type];
    
    if(ref.size() == 0) {
        for(int64 i = randRange(10, 20); i > 0 ; i--) {
            
        char c = randRange('a', 'z');
        name += c;
    }
            
        
        
        
    } else {
        name = ref[randRange(0, ref.size()-1)];
        
        for (auto i = name.begin() ; i < name.end(); i++ ) {
            
            
            if(isSpecial(*i)) {
                insert_iterator<string> a(name, ++i);
                i--;
                string add = genName::get(type + "." + *i);
                LOG(" Inserting string \"" << add << "\" to string\"" << name << "\"")
                for (auto j = add.cbegin(); j != add.cend(); j++) {
                    if ( j != add.cbegin() ) {
                        a = *j;
                    } else {
                        *i = *j;

                    } // End if/else for inserts
                } // End insert for.
            } // End if it needs an insert
        } // End for
        
    } // End if/else.
    
    
    return name;
}

















