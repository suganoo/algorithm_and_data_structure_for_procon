#include<iostream>
using namespace std;

// ( a b ) ( x ) = ( e )
// ( c d ) ( y ) = ( f )
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f ;

  int det = a * d - b * c;

  int x = (  d * e - b * f ) / det;
  int y = ( -c * e + a * f ) / det;

  cout << "x : " << x << " y : " << y << endl;
}
