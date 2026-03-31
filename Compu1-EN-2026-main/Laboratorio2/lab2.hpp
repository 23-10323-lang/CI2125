#pragma once
#include <concepts>
#include <vector>
#include <string>
#include <functional>
#include <tuple>
#include <iostream>

template <typename t>
struct Eq;

template <typename t>
concept EqImplementation = requires (t x, t y)
  {
    { x == y } -> std::same_as<bool>;
    { x != y } -> std::same_as<bool>;
  };

template<>
struct Eq<int>
  { static bool eq(int x, int y) { return x == y; }
    static bool neq(int x, int y) { return x != y; }
  };

template <>
struct Eq<double>
  { static bool eq(double x, double y) { return x == y; }
    static bool neq(double x, double y) { return x != y; }
  };

template<>
struct Eq<std::string>
  { static bool eq(std::string x, std::string y) { return x == y; }
    static bool neq(std::string x, std::string y) { return x != y; }
  };

template<>
struct Eq<bool>
  { static bool eq(bool x, bool y) { return x == y; }
    static bool neq(bool x, bool y) { return x != y; }
  };

// template <typename a, typename b>
//   requires EqImplementation<a> && EqImplementation<b>
// struct Eq<std::tuple<a,b>>
//   { static bool eq(std::tuple<a,b> x, std::tuple<a,b> y)
//     { return Eq<a>::eq(std::get<0>(x), std::get<0>(y)) && Eq<b>::eq(std::get<1>(x), std::get<1>(y)); }
//     static bool neq(std::tuple<a,b> x, std::tuple<a,b> y)
//     { return !eq(x,y); }
//   };
//

template <typename t>
struct Show;

template <typename t>
concept ShowImplementation = requires (t x)
  {
    { Show<t>::show(x) } -> std::same_as<std::string>;
  };

template<>
struct Show<int>
  { static std::string show(int x) { return std::to_string(x); } };

template <>
struct Show<double>
  { static std::string show(double x) { return std::to_string(x); } };

template<>
struct Show<std::string>
  { static std::string show(std::string x) { return x; } };

template<>
struct Show<bool>
  { static std::string show(bool x) { return x ? "true" : "false"; } };


template <typename t>
class List
  {
    private:
      std::vector<t> _inner;
      List<t> clone() const
      { List<t> xs;
        xs._inner = this->_inner;
        return xs;
      }
    public:
      List() {}
      List(List<t> const& other) : _inner(other._inner)  {}
      List<t> cons (t x) const
      { List<t> xs(*this);
        xs._inner.push_back(x);
        return xs;
      }
      List<t> tail() const
      { List<t> xs(*this);
        if (xs._inner.size() > 0)
          xs._inner.pop_back();
        return xs;
      }
      t head() const
      { return _inner.back(); }
      bool isEmpty() const
      { return _inner.empty(); }
  };

template<typename a, typename b>
  requires ShowImplementation<a> && ShowImplementation<b>
struct Show<std::tuple<a, b>>
  { static std::string show(std::tuple<a, b> t)
    { return "(" + Show<a>::show(std::get<0>(t)) + ", " + Show<b>::show(std::get<1>(t)) + ")"; }
  };


template <typename t>
  requires ShowImplementation<t>
struct Show<List<t>>
  { static std::string show(List<t> xs)
    { std::string s = "[";
      while(!xs.isEmpty())
        { s += Show<t>::show(xs.head());
          xs = xs.tail();
          if (!xs.isEmpty())
            s += ", ";
        }
      s += "]";
      return s;
    } };

template <typename t>
  requires EqImplementation<t>
struct Eq<List<t>>
  { static bool eq(List<t> xs, List<t> ys)
    { if (xs.isEmpty() && ys.isEmpty())
        return true;
      if (xs.isEmpty() || ys.isEmpty())
        return false;
      if (!Eq<t>::eq(xs.head(), ys.head()))
        return false;
      return eq(xs.tail(), ys.tail());
    } };


template <typename t>
  requires ShowImplementation<t>
std::string show(const t& x) {
    return Show<t>::show(x);
}

template <typename t>
  requires EqImplementation<t>
bool operator==(const List<t>& xs, const List<t>& ys) {
    return Eq<List<t>>::eq(xs, ys);
}

template <typename t>
  requires EqImplementation<t>
bool operator!=(const List<t>& xs, const List<t>& ys) {
    return !Eq<List<t>>::eq(xs, ys);
}

template <typename a, typename b, typename f_b_a_b>
  requires std::invocable<f_b_a_b, b, a>
    && std::convertible_to<f_b_a_b,std::function<b(b, a)>>
b reduceLeft(f_b_a_b f, b init, List<a> const& xs )
  {
    b acc = init;
    List<a> ys = xs;
    while (!ys.isEmpty()){
        acc = f(acc, ys.head());
        ys = ys.tail();
      }
    return acc;

  }

template <typename t>
List<t> snoc(const List<t> &xs, t x)
  {
    List<t> reversed = reverse(xs);
    List<t> result = reversed.cons(x);
    return reverse(result);
  }

template <typename a, typename b, typename f_b_a_b>
  requires std::invocable<f_b_a_b, b, a>
    && std::convertible_to<f_b_a_b,std::function<b(b, a)>>
b reduceLeftRec(f_b_a_b f, b init, List<a> const& xs )
  {
    if (xs.isEmpty())
      return init;
    return reduceLeftRec(f, f(init, xs.head()), xs.tail());
  }

template <typename a, typename b, typename f_a_b_b>
  requires std::invocable<f_a_b_b, a, b>
    && std::convertible_to<f_a_b_b,std::function<b(a, b)>>
b reduceRight(f_a_b_b f, b init, List<a> const& xs )
  {
    if (xs.isEmpty())
      return init;
    b res = reduceRight(f, init, xs.tail());
    return f(xs.head(), res);
  }

template<typename a>
List<a> reverse(List<a> const& xs)
  { return reduceLeft(
      [](List<a> acc, a x) { return acc.cons(x); },
      List<a>(),
      xs
    );
  }


template <typename a, typename b, typename f_a_b>
  requires std::invocable<f_a_b, a>
    && std::convertible_to<f_a_b,std::function<b(a)>>
List<b> map(f_a_b f, List<a> const& xs )
  { List<b> reversed;
    List<a> zs = xs;
    while (!zs.isEmpty())
      { reversed = reversed.cons(f(zs.head()));
        zs = zs.tail();
      }

    return reverse(reversed);

  }

template <typename a, typename b, typename f_a_b>
  requires std::invocable<f_a_b, a>
    && std::convertible_to<f_a_b,std::function<b(a)>>
List<b> mapRec(f_a_b f, List<a> const& xs )
  {
    if (xs.isEmpty())
      return List<b>();
    return mapRec(f, xs.tail()).cons(f(xs.head()));
  }

template <typename a, typename b, typename f_a_b>
  requires std::invocable<f_a_b, a>
    && std::convertible_to<f_a_b,std::function<b(a)>>
List<b> mapReduce(f_a_b f, List<a> const& xs )
  {

    List<b> reversed = reduceLeft(
      [&f](List<b> acc, a x) { return acc.cons(f(x)); },
      List<b>(),
      xs
    );
    return reverse(reversed);

  }

template <typename t>
List<t> concat(List<List<t>> const& xss)
  {
    return reduceRight(
      [](List<t> xs, List<t> acc) { return reduceRight([](t x, List<t> acc2) { return acc2.cons(x); }, acc, xs); },
      List<t>(),
      xss
        );
  }


template <typename a, typename f_a_b>
  requires std::invocable<f_a_b, a>
    && std::convertible_to<f_a_b,std::function<bool(a)>>
List<a> filter(f_a_b f, List<a> const& xs )
  {
    List<a> reversed;
    List<a> zs = xs;
    while (!zs.isEmpty())
      { if (f(zs.head()))
          reversed = reversed.cons(zs.head());
        zs = zs.tail();
      }

    return reverse(reversed);
  }


template <typename a, typename f_a_b>
  requires std::invocable<f_a_b, a>
    && std::convertible_to<f_a_b,std::function<bool(a)>>
List<a> filterRec(f_a_b f, List<a> const& xs )
  {
    if (xs.isEmpty())
      return List<a>();
    List<a> tailFiltered = filterRec(f, xs.tail());
    if (f(xs.head()))
      return tailFiltered.cons(xs.head());
    return tailFiltered;
  }

template <typename a, typename f_a_b>
  requires std::invocable<f_a_b, a>
    && std::convertible_to<f_a_b,std::function<bool(a)>>
List<a> filterMap(f_a_b f, List<a> const& xs )
  {
    List<List<a>> xss = map(
        [&f](a x) { return f(x) ? List<a>().cons(x) : List<a>(); },
        xs
        );
    return concat(xss);
  }

template <typename a, typename f_a_b>
  requires std::invocable<f_a_b, a>
    && std::convertible_to<f_a_b,std::function<bool(a)>>
List<a> filterReduce(f_a_b f, List<a> const& xs )
  {
    List<List<a>> xss = reduceRight(
        [f](a x, List<List<a>> acc) { return (f(x) ? List<a>().cons(x) : List<a>()).cons(acc); },
        List<List<a>>(),
        xs
        );
    return concat(xss);
  }

template <typename t>
  requires EqImplementation<t>
List<List<t>> groupEqual(List<t> const& xs)
  {
    List<List<t>> groups = reduceRight(
        [](t x, List<List<t>> acc) {
          if (acc.isEmpty())
            return List<List<t>>().cons(List<t>().cons(x));
          if (x == acc.head().head() ){
            List<t> aux =  acc.head().cons(x);
            List<List<t>> ret = acc.tail().cons(aux);
            return ret;

          }
          return acc.cons(List<t>().cons(x));
        },
        List<List<t>>(),
        xs
      );
    auto rv = [](List<t> l){ return reverse(l);};
    return map<List<t>,List<t>,std::function<List<t>(List<t>)> >(rv,groups);

  }

template <typename t>
int length(List<t> const& xs)
  {
    return reduceLeft([](int acc, t x) { return acc + 1; }, 0, xs);
  }

template <typename t>
  requires EqImplementation<t>
List<std::tuple<t, int>> encode(List<t> const& xs)
  {
    List<List<t>> groups = groupEqual(xs);
    List<std::tuple<t, int>> encoded = map<List<t>,std::tuple<t,int>,std::tuple<t,int>(List<t>)>(
        [](List<t> group) { return std::make_tuple(group.head(), length<t>(group)); },
        groups
        );
    return encoded;
  }

template <typename t>
List<t>  repeatN(int n, t x)
  { List<t> xs;
    for (int i = 0; i < n; ++i)
      xs = xs.cons(x);
    return xs;
  }

template <typename t>
  requires EqImplementation<t>
List<t> decode(List<std::tuple<t, int>> const& xss)
  {
    List<List<t>> groups = map(
        [](std::tuple<t, int> x) { return repeatN(std::get<1>(x), std::get<0>(x)); },
        xss
        );
    return concat(groups);
  }

template <typename a, typename b>
  List<std::tuple<a,b>> zip(List<a> const& xs, List<b> const& ys)
  {
    List<std::tuple<a,b>> zipped;
    List<a> zs = xs;
    List<b> ws = ys;
    while (!zs.isEmpty() && !ws.isEmpty())
      { zipped = zipped.cons(std::make_tuple(zs.head(), ws.head()));
        zs = zs.tail();
        ws = ws.tail();
      }

    return reverse(zipped);
  }

template <typename t>
List<std::tuple<t,int>> enumerate(List<t> const& xs)
  {
    List<std::tuple<t,int>> enumerated;
    List<t> zs = xs;
    int index = 0;
    while (!zs.isEmpty())
      { enumerated = enumerated.cons(std::make_tuple(zs.head(), index));
        zs = zs.tail();
        index++;
      }

    return reverse(enumerated);
  }

template <typename t>
  List<t> dropEveryN(int n, List<t> const& xs)
  {
    if (n <= 0)
      return xs;
    List<std::tuple<t,int>> enumerated = enumerate(xs);
    List<std::tuple<t,int>> dropped = filter(
        [n](std::tuple<t,int> x) { return (std::get<1>(x) + 1) % n != 0; },
        enumerated
        );
    List<t> result = map<std::tuple<t,int>,t,std::function<t(std::tuple<t,int>)>>(
        [](std::tuple<t,int> x) { return std::get<0>(x); },
        dropped
        );
    return result;
  }


template <typename t>
std::tuple<List<t>,t,List<t>> splitAt(int n, List<t> const& xs)
  {
    List<t> left;
    List<t> right = xs;
    while (n > 0 && !right.isEmpty())
      { left = left.cons(right.head());
        right = right.tail();
        n--;
      }
    return std::make_tuple(reverse(left), right.head(), right.tail());
  }

template <typename t, typename f_a_b>
  requires std::invocable<f_a_b, t, t>
    && std::convertible_to<f_a_b,std::function<bool(t, t)>>
int indexOfMin(List<t> const& xs, f_a_b f)
  {
    if (xs.isEmpty())
      return -1;
    int minIndex = 0;
    t minValue = xs.head();
    List<t> ys = xs.tail();
    int index  = 1;
    while (!ys.isEmpty())
      {
        if (f(ys.head(), minValue))
          { minValue = ys.head();
            minIndex = index;
          }
        ys = ys.tail();
        index++;
      }
    return minIndex;
  }

template <typename t>
List<t> mappend(List<t> xs, List<t> ys)
  {
    return reduceRight(
      [](t x, List<t> acc) { return acc.cons(x); },
      ys,
      xs
        );
  }

template <typename t, typename f_a_b>
  requires std::invocable<f_a_b, t, t>
    && std::convertible_to<f_a_b,std::function<bool(t, t)>>
  List<t> sortBy(List<t> const& xs, f_a_b f)
  {
    List<t> sorted = List<t>();
    List<t> aux = xs;
    int n = length(xs);
    for (int i = 0; i < n; ++i)
      { int minIndex = indexOfMin(aux, f);
        std::tuple<List<t>, t, List<t>> split = splitAt(minIndex, aux);
        aux = mappend(std::get<0>(split), std::get<2>(split));
        sorted = sorted.cons(std::get<1>(split));
      }
    return reverse(sorted);

  }

template <typename t>
  List<t> rotateByN(List<t> const& xs, int n)
  {
    int lxs = length(xs);
    if (xs.isEmpty())
      return xs;
    n = n % lxs;
    if (n < 0)
      n += length(xs);
    List<std::tuple<t,int>> enumerated = enumerate(xs);
    List<std::tuple<t,int>> enum_rotated = map<std::tuple<t,int>,std::tuple<t,int>,std::function<std::tuple<t,int>(std::tuple<t,int>)>>(
        [n,lxs](std::tuple<t,int> x) { return std::make_tuple(std::get<0>(x), (std::get<1>(x) + n) %  lxs ); },
        enumerated
        );
    auto comp = []( std::tuple<t,int> x, std::tuple<t,int> y) { return std::get<1>(x) < std::get<1>(y); };
    List<std::tuple<t,int>> sorted = sortBy(enum_rotated, comp);
    List<t> result = map< std::tuple<t,int>, t, std::function<t(std::tuple<t,int>)>>(
        [](std::tuple<t,int> x) { return std::get<0>(x); },
        sorted
        );
    return result;
  }

template <typename t>
  List<t> from_vector(const std::vector<t> &v)
  {
    List<t> l;
    for (int i = v.size() - 1; i >= 0; --i)
      l = l.cons(v[i]);
    return l;
  }
