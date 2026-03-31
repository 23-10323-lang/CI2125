#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct list {
  private: vector<int> elements;
  public:

  list() : elements{} {}
  list(const vector<int> &v) : elements{v} {}
  int head() const {
    return elements[0];
  }
  list tail() const {
    return list(vector<int>(elements.begin() + 1, elements.end()));
  }
  bool is_empty() const {
    return elements.empty();
  }
  string to_string() const {
    string result = "[";
    for (size_t i = 0; i < elements.size(); ++i) {
      result += std::to_string(elements[i]);
      if (i < elements.size() - 1) {
        result += ", ";
      }
    }
    result += "]";
    return result;
  }
  list prepend(int value) const {
    vector<int> new_elements = {value};
    new_elements.insert(new_elements.end(), elements.begin(), elements.end());
    return list(new_elements);
  }

};


/* bottom up */
int sumatoria_bu(int n){
  if(n == 0)
    return 0;
  int n1 = sumatoria_bu(n-1);
  return n + n1;
}

/* top_down */
int sumatoria_td(int n,int acc){
  if (n == 0)
    return acc;
  int new_acc = n + acc;
  return sumatoria_td(n-1,new_acc);
}

/*
 * Return the sum of the first n natural numbers.
 * Precondition: n >= 0
 */
int sumatoria(int n){
  return sumatoria_bu(n);
}

// sumatoria_bu(n)
//   { 0 si n = 0
//   { n + sumatoria_bu(n-1) en cualquier otro caso


// sumatoria(3)
// if (3 == 0)
// n1 = sumatoria_bu(2) = 3
// 3 + 3
// if (2 == 0)
// n1 = sumatoria_bu(1) = 1
// 2 + 1
// if (1 == 0)
// n1 = sumatoria(0) = 0
// 1 + 0
// if (0 == 0)
//


// <1,2,3,4,5,6>
//
// head: 1
// tail: <2,3,4,5,6>
// is_empty: false
// prepend 0: <0,1,2,3,4,5,6>
//
/*
 * Return the last element of a vector.
 * Precondition: the vector is not empty.
 */
// <5> -> return head()
// head: 5
// tail: <>
// <1,2,3>
// <2,3>
int last(const list &v) {
  if (v.tail().is_empty())
    return v.head();
  int last_elem_tail = last(v.tail());
  return last_elem_tail;
}

/*
 * Return the length of a list.
 */
int length(const list &lst) {
  /* |<>| = 0 */
  if (lst.is_empty())
    return 0;
  /* |<1,2,3,4>| =  */
  /* lt = |<2,3,4>| = 3 */
  int lt = length(lst.tail());
  return 1 + lt;
}

/* length_td(lst,0) */
int length_td(const list &lst, int acc){
  if (lst.is_empty())
    return acc;
  int new_acc = 1 + acc;
  return length_td(lst.tail(),new_acc);
}

/*
 * Return the element at the given index in a list.
 * Precondition: 1 <= index <= length(lst)
 */
int element_at(const list &lst, int index) {
  // <1,2,3,4,5> 1 -> head() -> 1
  // <1,2,3,4,5> 8 -> nunca hay errores de este tipo
  // <1> 1 -> 1
  //
  if (index == 1)
    return lst.head();

  // <1,2,3,4> 3 -> 3
  // <2,3,4> 2   -> 3
  int res =  element_at(lst.tail(),index - 1);
  return res;
}

list insert_at_end(int,const list &lst){
  return {};
}

/*
 * Return a new list that is the reverse of the input list.
 */
list reverse(const list &lst) {
  if (lst.is_empty())
    return lst;
  // <1,2,3,4,5>
  list r = reverse(lst.tail());
  // r = <5,4,3,2>

  return insert_at_end(lst.head(),r);
}

/*
 * Return true if the list is a palindrome, false otherwise.
 */
bool is_palindrome(const list &s) {
  // return s == reverse(s);
  return false;
}

/*
 * Return a new list that is the concatenation of two lists.
 */
list mappend(const list &s1, const list &s2) {
  return list();
}

/*
 * Return a new list with consecutive duplicates removed.
 * Example: delete_consecutive_duplicates([1,2,2,3,3,3,2,2,1]) == [1,2,3,2,1]
 */
list delete_consecutive_duplicates(const list &s) {
  return list();
}



/*
 * Eight queens problem.
 * This is a classical problem in computer science. The objective is to place eight queens on a chessboard so that no two queens
 * are attacking each other; i.e., no two queens are in the same row, the same column, or on the same diagonal.
 *
 * Hint: Represent the positions of the queens as a list of numbers 1..N. Example: [4,2,7,3,6,8,5,1]
 * means that the queen in the first column is in row 4, the queen in the second column is in row 2, etc.
 * Use the generate-and-test paradigm.
 *
 * */
vector<vector<int>> eight_queens() {
  vector<vector<int>> solutions;
  // Your code here
  return solutions;
}


// mul(x)(y) =
//   { x + mul(x)(y-1) si y >= 0
//   { 0 si x o y = 0
//
// sum(x,y)
//  { 1 + sum(x)(y-1) si y >=0
//  { x si y = 0
//
// fibonacci(x)
//   { fibonacci(x-1) + fibonacci(x-2) si x > 1
//   { x si x <= 1
//
// int fibonacci(int x){
//   if (x > 1)
//     return fibonacci(x-1) + fibonacci(x-2);
//   if (x <= 1)
//     return x;
// }


int main(){
  cout << sumatoria_bu(3) << endl;
  cout << sumatoria_td(3,0) << endl;
  return 0;
}
