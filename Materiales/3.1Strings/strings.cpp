#include <cstdio>
#include <string>


using std::string;


string reverse(string s){
  string reversed = "";
  for(int i = s.length() - 1; i >= 0 ; --i){
    char p = s[i];
    reversed.push_back(p);
  }
  return reversed;
}

int es_palindromo(string s){
  return reverse(s) == s;
}

string rotacion(string s){
  string r = "";
  r.push_back(s[s.size()-1]);
  for (int i = 0; i < s.size() - 1; ++i){
    r.push_back(s[i]);
  }
  return r;
}

bool es_rotacion(string s, string r){
  string rotado = r;
  for (int i = 0; i < r.size(); ++i){
    rotado = rotacion(rotado);
    if (rotado == s)
      return true;
  }
  return false;
}


int main(){
  string s  = "pocholate";
  string s2 = "abba";
  string s3 = "abcd";
  string s4 = "cdab";
  fprintf(stdout,"reversed(%s) = %s\n",s.c_str(),reverse(s).c_str());
  fprintf(stdout,"es_palindromo(%s) = %d\n", s.c_str(), es_palindromo(s));
  fprintf(stdout,"es_palindromo(%s) = %d\n", s2.c_str(), es_palindromo(s2));
  fprintf(stdout,"es_rotacion(%s,%s) = %d\n",s3.c_str(), s4.c_str(), es_rotacion(s3,s4));
  fprintf(stdout,"es_rotacion(%s,%s) = %d\n",s3.c_str(), s.c_str(), es_rotacion(s3,s));


  return 0;
}
